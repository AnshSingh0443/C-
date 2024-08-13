#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool IsPossibleSolution(vector<int>trees,int M,int mid){
    int woodObtained=0;
    for(int i=0;i<trees.size();i++){
        //calulating wood  obatined at height=mid
        if(trees[i]>mid){
            //wood is obtained only when height of tree is more than that of sawblade
            woodObtained +=trees[i]-mid;
        }
    }
    if(woodObtained>=M){
        return true;
    }else{
        return false;
    }

}

int MaxSawBladeHeight(vector<int>trees,int M){
    sort(trees.begin(),trees.end());
    int s=0;
    int e=trees[trees.size()-1];//end should be the max height among  the tree
    int ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        // CASE1->if mid is the height of sawblade which provides at least M meters of wood
        if(IsPossibleSolution(trees,M,mid)){
            //it can be the answer
            ans=mid;
            //see if there is another greater than mid->to maximize
            s=mid+1;
        }
        // CASE2->at height=mid we could not obtain m meters of wood 
        else{
            e=mid-1;
        }
    }
    return ans;
    
}
int main(){
    //PROBLEM STATEMENT
    //Lumberjack Mirko needs to chop down M metres of wood.->least meter of wood required 
    //However, Mirko is only allowed to cut a single row of trees.
    //Mirko‟s machine works as follows: Mirko sets a height parameter H (in metres),
    //and the machine raises a giant sawblade to that height 
    //and cuts off all tree parts higher than H (of course, trees not higher than H meters remain intact).
    //Mirko then takes the parts that were cut off. For example, 
    //if the tree row contains trees with heights of 20, 15, 10, and 17 metres, 
    //and Mirko raises his sawblade to 15 metres, the remaining tree heights after cutting will be 15, 15, 10, and 15 metres, 
    //respectively, while Mirko will take 5 metres off the first tree and 2 metres off the fourth tree (7 metres of wood in total).
    //Mirko is ecologically minded,
    //so he doesn‟t want to cut off more wood than necessary.
    //That‟s why he wants to set his sawblade as high as possible. 
    //Help Mirko find the maximum integer height of the sawblade that still allows him to cut off at least M metres of wood.

    //EXAMPLE
    // Input:
    // N=4->no of trees ,M=7->least meter of wood required
    // 20 15 10 17->containes heights of tree

    // Output:
    // 15->maximum height of sawblade required to obtaine at least M(7) meters of wood

    //SOLUTION
    //height of saw blade can range from o to the max hieght of the tree
    //(most amount of wood) 0----------mid------------20(least amount of wood)
    //we check if at  height=mid  can we obtain M meter of wood if yes then this is the max height
    //1.IF( wood obtained>=M) it may be answer if there is no mid for which we get M meters of wood 
    // so search in the right to maximize the height 
    //2.IF( wood obtained<M) then this height cannot give at least M meters of wood so Search in the Right side

    vector<int>trees{20, 15, 10, 17};
    int N=4;//no of trees
    int M=7;//least meter of wood req
    //for bigger range use-long long int for necesssay variables and fuctions
    cout<<"the max height of sawbalde should be "<<MaxSawBladeHeight(trees,M);
    
}