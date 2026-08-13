class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;

        for(int num : prices){
            buy = min(buy,num);
            profit = max(profit,num-buy);
        }
        return profit;
    }
};