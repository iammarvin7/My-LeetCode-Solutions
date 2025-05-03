class Solution {

public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        int n = s.size();
        long long sum = 0;
        

        for(int i = 0; i < n; ++i){
            int cs = s[i] - 'a';
            int ct = t[i] - 'a';

            long long nxt = 0;
            while(cs != ct){ //next
                nxt += nextCost[cs];
                cs = (cs + 1) % 26;
            }

            long long prv = 0;
            cs = s[i] - 'a';
            while(cs != ct){ //prev
                prv += previousCost[cs];
                cs = (cs - 1 + 26) % 26;
            }
            sum += min(nxt, prv);
        }
        return sum;

    }
};