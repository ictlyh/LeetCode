class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        //if (size == 1) return 0;
        int sum = 0, i = 0;
        while (i < size -1) {
            int base = prices[i];
            while (i < size - 1 && prices[i] < prices[i + 1]) i++;
            if (i == size) {
                sum = sum + prices[i - 1] - base;
                return sum;
            }
            sum = sum + prices[i] - base;
            while (i < size - 1 && prices[i] >= prices[i + 1]) i++;
        }
        return sum;
    }
};