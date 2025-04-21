class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        long long sum = 0;
        int n = differences.size();
        for(int i = 0; i < n; ++i){
            sum += differences[i];
            if(sum > maxi) maxi = sum;
            if(sum < mini) mini = sum;
        }
        int ans = 0;
        for(int i = lower; i <= upper; ++i){
            if((i+maxi) <= upper and (i+mini)>= lower) ans++;
            
        }
        return ans;
    }
};