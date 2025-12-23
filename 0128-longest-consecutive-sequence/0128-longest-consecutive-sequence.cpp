class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()) return 0;
        unordered_set<int> mySet(nums.begin(), nums.end());
        int n = nums.size();
        int longest = 1;

        for(const auto& elem: mySet){
            int len = 1;
            if(!mySet.count(elem-1)){
                int cur = elem;
                while(mySet.count(cur+1)){
                    len++;
                    cur+=1;
                }
            }
            longest = max(longest, len);
        }
        return longest;
    }
};