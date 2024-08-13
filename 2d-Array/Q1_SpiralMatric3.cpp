#include<iostream>
#include<vector>
using namespace std;
//https://leetcode.com/problems/spiral-matrix-iii/description/?envType=daily-question&envId=2024-08-08
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> directions={{0,1},{1,0},{0,-1},{-1,0}};
        //0->right 1->down 2->left 3->up
        //observation during right(0) and left(2) step increses by 1
        int steps=0;
        int currDir=0;
        vector<vector<int>>res;
        res.push_back({rStart,cStart});

        while(res.size()<rows*cols){
            if(currDir==0 || currDir==2){
                steps++;
            }

            for(int count=0;count<steps;count++){
                rStart+=directions[currDir][0];
                cStart+=directions[currDir][1];

                if(rStart>=0 && rStart<rows && cStart>=0 &&cStart<cols){
                    res.push_back({rStart,cStart});
                }
            }
            //change direction
            currDir= (currDir+1)%4;
        }
        return res;
        
    }

int main(){
    return 0;

}