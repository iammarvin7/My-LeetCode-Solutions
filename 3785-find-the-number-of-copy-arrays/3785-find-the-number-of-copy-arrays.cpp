class Solution {

    pair<int, int> intersection(int opr, int u1, int v1, int u2, int v2){
        int b0 = u1 + opr;
        int b1 = v1 + opr;

        int U = max(b0, u2), V = min(b1, v2);


        if(U > V) return {-1, -1};



        return {U, V};
    }

public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int n = original.size();
        int u = bounds[0][0];
        int v = bounds[0][1];


        for(int i = 1; i < n; ++i){

            int opr = original[i] - original[i-1];

            auto [new_u, new_v] = intersection(opr, u, v, bounds[(i)][0], bounds[(i)][1]);

            if(new_u == -1) return 0;
            u = new_u;
            v = new_v;

        }

        return (v - u + 1);
        
    }
};