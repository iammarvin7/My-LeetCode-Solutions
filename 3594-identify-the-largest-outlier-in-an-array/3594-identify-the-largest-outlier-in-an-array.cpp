class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int,int> freq;
        for(int num : nums) {
            sum += num;
            freq[num]++;
        }
        int ans = INT_MIN;
        for(int num : nums){
            int sub = (sum - num);
            freq[num]--;
            if((sub%2==0) and (freq[sub/2] != 0)){
                ans = max(ans,num);
            }
            freq[num]++;
        }
        return ans;
        

    }
};