class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // best (cheapest) price to buy so far
        int minBuyPrice = prices[0];
        int maxProfit = 0;   // best profit found

        for (int i = 1; i < prices.size(); i++) {

            int profitIfSoldToday = prices[i] - minBuyPrice;
            maxProfit = max(maxProfit, profitIfSoldToday);

            // update best buying price
            minBuyPrice = min(minBuyPrice, prices[i]);
        }

        return maxProfit;
    }
};

//Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

/* 
Dynamic Programming tag but comes under Constructive Algorithm (here, Remembering the minimum) 
Time Complexity: O(N) 
Space Complexity: O(1) 
*/

//Revised on: 08/02/2026

