class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int sum = 0;
        vector<int> P_L;

        for(int i = 0; i < prices.size()-1; ++i){
            P_L.push_back(prices[i+1]-prices[i]);
        }

        for(int i = 0; i < P_L.size(); ++i){
            sum = max(P_L[i], sum + P_L[i]);
            profit = max(sum, profit);
        }


        return (profit < 0) ? 0 : profit;
    }
};