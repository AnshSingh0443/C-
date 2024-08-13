#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string convert(string s, int numRows) {
    //1.if num of rows=1->return orignal string
    if(numRows==1){
        return s;
    }
    //2.check directiom after sometime
    //   a:For 1st iteration top to bottom till numrows then change direction
    //   b:bottom to top and then top to bottom switch after every numrows-1  

    vector<string>zigzag(numRows);
    int i=0;
    int row=0;
    bool directon=1;//a:Top->Bottom
    while(true){
        if(directon){
            while(row<numRows && i<s.length()){
                zigzag[row].push_back(s[i]);
                row++,i++;
            }
            //since row has reached num+1 to start the next we need to change direction and  go to numrow-1
            row=numRows-2;
        }else{
            // Bottom->Top
            while(row>=0 && i<s.length()){
                zigzag[row].push_back(s[i]);
                row--,i++;
            }
            // row has reached 0 to start next we need to change direction and go from next row
            row=1;
        }
        if(i>=s.length()){
            break;
        }
        //chaange direction
        directon=!directon;
    }   
    string ans="";
    for(int i=0;i<zigzag.size();i++){
        ans=ans+zigzag[i];// read row wise
    }
    return ans;
}
int main(){
    //Input: s = "PAYPALISHIRING", numRows = 4
    // Output: "PINALSIGYAHRPI"
    // Explanation:
    // P     I    N
    // A   L S  I G
    // Y A   H R
    // P     I

    //s="ABCDEFGHIJ",numrows=3
    //zig zag->
    //A   F  J
    //B  EG I
    //C D H
    //OUTPUT:"AFJBEGICDH"//read rowise
    string s="PAYPALISHIRING";
    int numRows=4;
    cout<<convert(s,numRows);
}

