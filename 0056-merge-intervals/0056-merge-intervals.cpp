class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        if (intervals.size() == 1) return intervals;

        vector<vector<int>> result; //ans matrix

        int i = 0;
        
        while(i < intervals.size()){
            vector<int> curr = intervals[i];

            int j = i+1;

            while(j < intervals.size() && curr[1] >= intervals[j][0]){
                int start = min(curr[0], intervals[j][0]);
                int end = max(curr[1], intervals[j][1]);

                curr = {start, end};
                i++;
                j++;
            }
            result.push_back(curr);
            i++;

        }
        return result;
       

    }
};