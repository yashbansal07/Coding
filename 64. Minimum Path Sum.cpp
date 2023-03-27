class Solution {
public:
    int row, col, minSum = INT_MAX;
    bool isValidMove(int i, int j){
        return (i >= 0 && i < row && j >= 0 && j < col);
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int sumTillNow){
        if(!isValidMove(i, j))
            return;
        
        sumTillNow += grid[i][j];
        if(i == row-1 && j == col-1){
            minSum = min(minSum, sumTillNow);
            return;
        }

        dfs(grid, i+1, j, sumTillNow);
        dfs(grid, i, j+1, sumTillNow);
    }

    int minPathSum(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();

        /*dfs(grid, 0, 0, 0);
        return minSum;*/

        for(int i = 1; i < row; i++)
            grid[i][0] += grid[i-1][0];
        for(int j = 1; j < col; j++)
            grid[0][j] += grid[0][j-1];
        
        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++)
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
        }
        return grid[row-1][col-1];
    }
};
