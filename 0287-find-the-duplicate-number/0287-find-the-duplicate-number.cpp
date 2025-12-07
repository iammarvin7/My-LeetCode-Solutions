class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> all_nums;
        int ans = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(all_nums.count(nums[i])){
                ans = nums[i];
                break;
            }    
            else{
                all_nums.insert(nums[i]);
            }
        }
        return ans;
    }
};