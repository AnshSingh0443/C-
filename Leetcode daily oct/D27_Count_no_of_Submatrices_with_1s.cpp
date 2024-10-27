#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

class Solution {
public:
    //memoization
    int m, n;
    int solve(int i, int j, vector<vector<int>>& grid,
              vector<vector<int>>& t) {
        
        if (i >= grid.size() || j >= grid[0].size()) 
            return 0;

        if (grid[i][j] == 0)
            return 0;
        //precomputed or not
        if (t[i][j] != -1)
            return t[i][j];

        // Right
        int right = solve(i, j + 1, grid, t);
        // Diagonal
        int diagonal = solve(i + 1, j + 1, grid, t);
        // Below
        int below = solve(i + 1, j, grid, t);
        //why min becuz we need to  know ki max kitne side ka square possible hai
        //eg right=2 diag=1  and down = 2 meaning dia mai onnly single 1 is present thus  we  can not form a 3 x 3 square but we can  only form 2 x 2 square max
        //why +1 ->cuz 1 is considered a square of side 1
        return t[i][j] = 1 + min({right, diagonal, below});
    }

    int countSquares_mem(vector<vector<int>>& grid) {
        int result = 0;
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> t(m, vector<int>(n, -1));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                //har ek 1 pr check kro ki kitne square ban sakte hai and keep adding the no
                result += solve(i, j, grid, t);
            }
        }
        return result;
    }

    //BOTTOM UP APPROACH
    int countSquares(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> t(m, vector<int>(n, 0));
        int result = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 || j == 0) {
                    t[i][j] = matrix[i][j];
                } else {
                    if(matrix[i][j] == 1) {
                        // Because, if you have any 0, then you cannot expand side of square
                        t[i][j] = 1 + min({t[i-1][j], t[i][j-1], t[i-1][j-1]});
                    }
                }
                result += t[i][j];
            }
        }
        
        return result;
    }
};

int main(){

}