#include<iostream>
#include<vector>
using namespace std;
//1.Recursion
int getMinOperation(string a,string b,int i,int j){
    if(i==a.length()){
        return b.length()-j;
    }
    if(j==b.length()){
        return a.length()-i;
    }

    int ans=0;
    //if same chars no operations needed
    if(a[i]==b[j]){
        ans=0+getMinOperation(a,b,i+1,j+1);       
    }else{
        //perform operations
        int insert=1+getMinOperation(a,b,i,j+1);
        int delete1=1+getMinOperation(a,b,i+1,j);
        int replace=1+getMinOperation(a,b,i+1,j+1);

        ans=min(insert,min(delete1,replace));
    }

    return ans;

}
//2.Memoization
int getMinOperation_TOPDOWN(string a,string b,int i ,int j,vector<vector<int>>&dp){
    if(i==a.length()){
        return b.length()-j;
    }
    if(j==b.length()){
        return a.length()-i;
    }
    //step 2:check for answer in dp
    if(dp[i][j]!=-1){
        return dp[i][j];
    }



    int ans=0;
    //if same chars no operations needed
    if(a[i]==b[j]){
        ans=0+getMinOperation_TOPDOWN(a,b,i+1,j+1,dp);       
    }else{
        //perform operations
        int insert=1+getMinOperation_TOPDOWN(a,b,i,j+1,dp);
        int delete1=1+getMinOperation_TOPDOWN(a,b,i+1,j,dp);
        int replace=1+getMinOperation_TOPDOWN(a,b,i+1,j+1,dp);

        ans=min(insert,min(delete1,replace));
    }
    //step 3:update dp
    dp[i][j]=ans;

    return dp[i][j];
    
}
//3.Tabulation
int getMinOperation_BOTTOMUP(string a,string b){
    //step 1:create a dp array
    vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,0));
    //step 2:observe base cases
    for(int j=0;j<=b.length();j++){
        dp[a.length()][j]=b.length()-j;
    }

    for(int i=0;i<=a.length();i++){
        dp[i][b.length()]=a.length()-i;
    }
    
    //step 3:revrese flow of top down

    //i->a.len to 0
    for(int i=a.length()-1;i>=0;i--){

        for(int j=b.length()-1;j>=0;j--){
            int ans=0;
            //replace rec call with dp and use loop  varible accordingly
            
            //if same chars no operations needed
            if(a[i]==b[j]){
                ans=0+dp[i+1][j+1];       
            }else{
                //perform operations
                int insert=1+dp[i][j+1];
                int delete1=1+dp[i+1][j];
                int replace=1+dp[i+1][j+1];

                ans=min(insert,min(delete1,replace));
            }
            //step 3:update dp
            dp[i][j]=ans;

        }
    }
    //since we are going from index to 0 final ans is stored at dp[0][0]
    return dp[0][0];
    

}
//4.Space optimized solution
// dp[i][j] curr row is dpending upon dp[i][j+1],dp[i+1][j+1] and dp[i+1][j] ie next row
    int getMinOperation_SO(string a, string b) {
        //vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1,0));
        vector<int> curr(b.length()+1, 0);
        vector<int> next(b.length()+1, 0);
        //replace dp[i] with curr[..] and dp[i+1] with next[..]

        //handle base case->columns handled

        for(int j =0; j<=b.length(); j++) {
            next[j] =  b.length()-j;
        }
        //since we do not have all the rows we cannot handle the end base case as above
        //so we handle it when we start to traverse the row->inside the outer loop
        for(int i = a.length()-1; i>=0; i--) {
            //every row starts here
            //yaha galti karoge
            curr[b.length()] = a.length()-i;
            
            for(int j =b.length()-1; j>=0; j--) {
                //replace rec call with dp and use loop  varible accordingly

                //if same chars no operations needed
                int ans = 0;
                if(a[i] == b[j]) {
                    ans = next[j+1];
                }
                else {
                    //operation perform karo 
                    int insert = 1 + curr[j+1];
                    int deleted = 1 + next[j];
                    int replace = 1 + next[j+1];
                    ans = min(insert, min(deleted, replace));
                }
                //step 3:update dp
                curr[j] =  ans;
            }
            //shift
            next = curr;
        }
        return next[0];
    }
int minDistance(string word1,string word2){
    //base case 
    if(word1.length()==0){
        //kyuki word1 ko word2 banane k liye word2.length jitne char add karne honge
        //no of operations->word2.length()
        return word2.length();
    }
    if(word2.length()==0){
        //kyuki word1 ko word2 banane k liye word1.length jitne char remove karne honge
        //no of operations->word1.length()
        return word1.length();
    }

    int i=0;
    int j=0;
    // return getMinOperation(word1,word2,i,j);
    //using dp
    //step 1: create a dp array
    vector<vector<int>>dp(word1.length()+1,vector<int>(word2.length()+1,-1));
    return getMinOperation_BOTTOMUP(word1,word2);

}
int main(){

    //ex
    // Input: word1 = "horse", word2 = "ros"
    // Output: 3
    // Explanation: 
    // horse -> rorse (replace 'h' with 'r')
    // rorse -> rose (remove 'r')
    // rose -> ros (remove 'e')
    string word1="horse";
    string word2="ros";
    cout<<"min no of operation req to change "<<word1<<" to "<<word2<<" is "<<minDistance(word1,word2);

    return 0;

}