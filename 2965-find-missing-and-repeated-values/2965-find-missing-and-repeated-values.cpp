class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_set<int> seen;
        
        int repeat = 0;
        int missing = 0;
        for(int i = 1; i <= n*n; ++i){
            seen.insert(i);
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(seen.count(grid[i][j])){
                    seen.erase(grid[i][j]);
                }
                else{
                    repeat = grid[i][j];
                }
            }
        }
        missing = *seen.begin();
        return {repeat, missing};
    }
};