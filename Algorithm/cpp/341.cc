class NestedIterator {
  public:
    queue<int> vals;
    void inQueue(const NestedInteger& nestedInteger) {
      if (nestedInteger.isInteger())
        vals.push(nestedInteger.getInteger());
      else {
        for (int i = 0; i < nestedInteger.getList().size(); i++) {
          inQueue(nestedInteger.getList()[i]);
        }
      }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
      for (int i = 0; i < nestedList.size(); i++)
        inQueue(nestedList[i]);
    }

    int next() {
      int val = vals.front();
      vals.pop();
      return val;
    }

    bool hasNext() {
      return !vals.empty();
    }
};
