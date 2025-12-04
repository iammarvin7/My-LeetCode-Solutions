class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTri;
        vector<int> curr;
        vector<int> row_0 = {1};
        vector<int> row_1 = {1, 1};

        for(int i = 0; i < numRows; ++i){
            for(int j = 0; j <= i; ++j){
                int val = 0;
                if(j == 0 || j == i){
                    val = 1;
                }
                else{
                    val = pascalTri[i-1][j-1] + pascalTri[i-1][j];
                }
                curr.push_back(val);
            }
            pascalTri.push_back(curr);
            curr.clear();
        }
        return pascalTri;

    }
};