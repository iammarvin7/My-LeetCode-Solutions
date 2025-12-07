class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int size = n*n;
        vector<int> ans(2, 0);
        vector<int> nums(size+1, 0);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                nums[grid[i][j]]++;
            }
        }

        for(int i = 1; i <= size; ++i){
            if(nums[i] == 2) ans[0] = i;
            if(nums[i] == 0) ans[1] = i;
        }
        return ans;
    }
};