#include<iostream>
#include<vector>
using namespace std;
void printSudoku(vector<vector<char>>& board){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
bool isSafe(int row, int col, vector<vector<char>>& board, char value) {
    int n=board.size();
    for(int i=0;i<n;i++){
        //row check
       if(board[row][i]==value){
            return false;
       }

        //col check
        if(board[i][col]==value){
            return false;
        }

        //3x3 check
        if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==value){
            return false;
        }

    }

    return true;

}

bool solve(vector<vector<char>>& board) {
    //traverse through the matrix
    int n=board.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]=='.'){
                //empty cell found
                //try to fill the cell with values ranging from 1 to 9
                for(char value='1';value<='9';value++){
                    //check if it is safe to put that value in the empty cell
                    if(isSafe(i,j,board,value)){
                        //place the value in the empty cell
                        board[i][j]=value;

                        //R.R->solve for next 
                        bool aageKaSoln=solve(board);//remaining board ka soln->possible if not backtrack
                        if(aageKaSoln==true){
                            return true;
                        }else{
                            //backtrack->problem occured in furthur filling->backtrack
                            board[i][j]='.';
                        }
                    }
                    
                }
                //if 1 se 9 tak koi bhi value se solution
                //nahi nikla ,current cell pr, 
                //that means piche kahin pr galti h , 
                //go back by returning false
             return false;
            }

        }
    }

    return true;

}
void solveSudoku(vector<vector<char>>& board) {
    solve(board);

        
}
int main(){
    vector<vector<char>> board
                            {
                                {'5','3','.','.','7','.','.','.','.'},
                               {'6','.','.','1','9','5','.','.','.'},
                               {'.','9','8','.','.','.','.','6','.'},
                               {'8','.','.','.','6','.','.','.','3'},
                               {'4','.','.','8','.','3','.','.','1'},
                               {'7','.','.','.','2','.','.','.','6'},
                               {'.','6','.','.','.','.','2','8','.'},
                               {'.','.','.','4','1','9','.','.','5'},
                               {'.','.','.','.','.','8','.','7','9'}
                            };

    cout<<"printing the board before solving:->"<<endl;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<" "<<board[i][j];
        }
        cout<<endl;
    }
    cout<<endl;

    solveSudoku(board);







}