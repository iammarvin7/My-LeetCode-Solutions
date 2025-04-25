class Solution {
    #define long long ll
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        //sort the nums
        sort(nums.begin(), nums.end());

        int n = nums.size(), ans = 0;

        /*
        iterate through the array, with a required number (prev) 
        (i.e: we want the current number to be greater than prev)
        */
        for(int i = 0, prev = INT_MIN; i < n; ++i){
            //calculate the lower and the upper bound possible for the current number
            int l = nums[i] - k;
            int r = nums[i] + k;

            /*
            if lower bound is bigger than required number (happens if current number is bigger than last number), 
            then the next required number will be that lower bound, and increase the ans length by 1
            */
            if(l > prev){
                prev = l;
                ans++;
            }
            /*
            otherwise, check if the required number is in the range of current number,
            if it is then increase the required number by 1
            */
            else if(prev < r){
                prev += 1;
                ans++;
            }
        }
        //return the ans length
        return ans;
    }
};

/*
DRY RUN:

prev = INT_MIN, k = 1, ans = 0;
nums: [4, 4, 4, 4]
       i
l = 3
r = 5

condition 1: l > prev --> prev = 3, ans = 1;

nums: [4, 4, 4, 4]
          i
l = 3
r = 5

condition 2: r > prev --> prev = 4, ans = 2;

nums: [4, 4, 4, 4]
             i 
l = 3
r = 5

condition 2: r > prev --> prev = 5, ans = 3;

nums: [4, 4, 4, 4]
                i
l = 3
r = 5

no condition hits


returns ans = 3;


*/