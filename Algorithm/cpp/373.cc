class Solution {
  public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
      vector<pair<int, int>>result;
      for(int i1=0;i1<min((int)nums1.size(),k);++i1)
        for(int i2=0;i2<min((int)nums2.size(),k);++i2)
          result.push_back({nums1[i1],nums2[i2]});
      sort(result.begin(),result.end(),[](pair<int, int>&a,pair<int, int>&b){return a.first+a.second<b.first+b.second;});
      if(result.size()>k)result.erase(result.begin()+k,result.end());
      return result;
    }
};
