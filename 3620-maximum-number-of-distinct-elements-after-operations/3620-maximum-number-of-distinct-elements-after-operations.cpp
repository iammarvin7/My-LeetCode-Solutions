class Solution {
    #define long long ll
public:
    int maxDistinctElements(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;

        int prev = INT_MIN;
        for(int i = 0; i < n; ++i){
            int l = nums[i] - k;
            int r = nums[i] + k;

            if(l > prev){
                prev = l;
                ans++;
            }
            else if(prev < r){
                prev += 1;
                ans++;
            }


        }
        return ans;



    }
};