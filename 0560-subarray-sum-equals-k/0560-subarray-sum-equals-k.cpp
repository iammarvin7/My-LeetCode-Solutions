class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size(), sum = 0;
        freq[0] = 1;
        int ans = 0;
        for(const auto& num : nums){
            sum += num;
            int diff = sum-k;

            if(freq.count(diff)){
                ans+=freq[diff];
            }
            freq[sum]++;

        }
        return ans;        
    }
};