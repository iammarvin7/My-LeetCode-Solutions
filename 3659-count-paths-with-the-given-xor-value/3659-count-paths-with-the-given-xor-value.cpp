class Solution {

    vector<vector<vector<int>>> dp;
    const int MOD = 1000000007;

    int trav(vector<vector<int>>& grid, int i, int j, int& xor_val, int k){
        int n = grid[0].size();
        int m = grid.size();
        int paths = 0;

        if (i >= m || j >= n) {
            return 0;
        }
        int new_xor = xor_val ^ grid[i][j];

        if(i == m-1 and j == n-1 and new_xor == k){
            return 1;
        }

        if(dp[i][j][new_xor] != -1){
            return dp[i][j][new_xor];
        }

        paths = (paths + trav(grid, i+1, j, new_xor, k)) % MOD;
        paths = (paths + trav(grid, i, j+1, new_xor, k)) % MOD;

        return dp[i][j][new_xor] = paths;
    }
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int n = grid[0].size();
        int m = grid.size();

        dp.assign(m, vector<vector<int>>(n, vector<int>(16, -1)));
        int i = 0, j = 0, xor_val = 0;
        return trav(grid, i, j, xor_val, k);
    }
};