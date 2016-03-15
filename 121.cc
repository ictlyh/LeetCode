class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        vector<int> back(prices);
        int pro = 0;
        for (int i = prices.size() - 2; i >= 0; i--)
            back[i] = prices[i] < back[i + 1] ? back[i + 1] : prices[i];
        for (int i = 0; i < prices.size(); i++)
            pro = pro < back[i] - prices[i] ? back[i] - prices[i] : pro;
        return pro;
    }
};