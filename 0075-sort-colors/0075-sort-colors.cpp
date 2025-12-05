class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> freq(3, 0);

        for(int i = 0; i < nums.size(); ++i){
            freq[nums[i]]++;
        }

        int ind = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(freq[ind] != 0){
                nums[i] = ind;
                freq[ind]--;
            }
            else{
                i--;
                ind++;
            }
        }

    }
};