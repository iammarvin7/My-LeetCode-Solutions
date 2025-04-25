class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        long long ans1 = 0, ans2 = 0;
        int n = arr.size();

        for(int i = 0; i < n; ++i){
            ans1 += abs(arr[i]-brr[i]);
        }

        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());

        for(int i = 0; i < n; ++i){
            ans2 += abs(arr[i]-brr[i]);
        }

        return min(ans1, ans2+k);

    }
};