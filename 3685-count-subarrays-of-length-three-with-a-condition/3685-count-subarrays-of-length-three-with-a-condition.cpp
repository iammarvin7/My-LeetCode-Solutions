class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n-2; ++i){
            int f = nums[i];
            int s = nums[i+1];
            int t = nums[i+2];
            if((f + t)*2 == s) ans++;

        }
        return ans;
    }
};