class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            if(prices.size() == 0)
                return 0;

            int profit = 0, min, max, prev;
            bool increasing = false;
            min = max = prev = prices[0];

            for(int i=1; i<prices.size(); i++){
                if(prev<prices[i]){
                    increasing = true;
                    max = prices[i];
                }

                if(prev>prices[i]){
                    increasing = false;
                    profit += (max-min);
                    min = prices[i];
                    max = prices[i];
                }

                prev = prices[i];
            }

            if(increasing)
                profit += (max-min);
            return profit;
        }
};
