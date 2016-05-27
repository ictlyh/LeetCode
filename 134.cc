class Solution {
  public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int size = gas.size();
      if (size == 0) return -1;
      int sum = 0;
      int tempSum = 0;
      int index = 0;
      for (int i = 0; i < size; i++){
        sum += gas[i] - cost[i];
        tempSum += gas[i] - cost[i];
        if (tempSum < 0) {
          tempSum = 0;
          index = i+1;
        }
      }
      return sum < 0 ? -1 : index;
    }
};

// Time Limit Exceeded
class Solution {
  public:
    bool canCompleteCircuitHelper(vector<int>& gas, vector<int>& cost, int idx) {
      int left = 0;
      int size = gas.size();
      for (int i = 0; i < size; i++) {
        int index = (idx + i) % size;
        left += gas[index];
        left -= cost[index];
        if (left < 0) return false;
      }
      return true;
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      for (int i = 0; i < gas.size(); i++)
        if (canCompleteCircuitHelper(gas, cost, i)) return i;
      return -1;
    }
};
