class Solution {
  public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      std::map<int,int> mymap;
      for (int i = 0; i < nums.size(); i++) {
        std::map<int,int>::iterator ite = mymap.find(nums[i]);
        if (ite != mymap.end())
          if (i - ite->second <= k) return true;
        mymap[nums[i]] = i;
      }
      return false;
    }
};
