class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long mini = 0;
        long long maxi = 0;
        long long sum = 0;

        for(int elem : differences){
            sum += elem;
            maxi = max(maxi, sum);
            mini = min(mini, sum);
        }
        //OLD CODE
        // int ans = 0;
        // for(int i = lower; i <= upper; ++i){
        //     if((i+maxi) <= upper and (i+mini)>= lower) ans++;
            
        // }
        // return ans;

        //NEW CODE:- Instead of checking for each value, 
        //check for how high the curve can go and still stay in the bount
        /*
        diff = [2, -4, 5];
          x+2 
          /\    x+1
        x/  \  /
             \/
             x-2
        if you start at (x-2) say p, how far up high can you go? (p + 4) will be the max value;
        but if the upper bound is still 3 points above p, you can still have valid 3 sequences as, p+1, p+2, p+3;
        therefore, the valid seqs will be (upper bound - range_of_diff) + 1 (make sure to include p too)
        */
        int ans = ((upper-lower) - (maxi-mini)) + 1;
        return (ans > 0) ? ans : 0;



    }
};