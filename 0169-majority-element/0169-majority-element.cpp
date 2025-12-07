class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n= nums.size();

        for(int i = 0; i < n; ++i){
            if(freq.count(nums[i])){
                freq[nums[i]]++;
            }
            else{
                freq[nums[i]] = 1;
            }
        }

        for(const auto& pair : freq){
            if(pair.second > (n/2)){
                return pair.first;
                
            }
        }
        return -1;
    }
};