class Solution {
  public:
    bool static intCompare(int a, int b) {
      stack<int> adigits;
      stack<int> bdigits;
      int v1 = a, v2 = b;
      do {
        adigits.push(v1 % 10);
        v1 /= 10;
      } while (v1);
      do {
        bdigits.push(v2 % 10);
        v2 /= 10;
      } while (v2);
      int amax = adigits.top();
      int bmax = bdigits.top();
      int amin, bmin;
      while (!adigits.empty() && !bdigits.empty()) {
        amin = adigits.top();
        bmin = bdigits.top();
        if (amin < bmin) return false;
        else if (amin > bmin) return true;
        adigits.pop();
        bdigits.pop();
      }
      while (!adigits.empty()) {
        amin = adigits.top();
        if (amin < bmax) return false;
        else if (amin > bmax) return true;
        adigits.pop();
      }
      while (!bdigits.empty()) {
        bmin = bdigits.top();
        if (amax < bmin) return false;
        else if (amax > bmin) return true;
        bdigits.pop();
      }
      return amin > bmin;
    }

    string largestNumber(vector<int>& nums) {
      sort(nums.begin(), nums.end(), intCompare);
      stringstream ss;
      for (int i = 0; i < nums.size(); i++)
        ss << nums[i];
      string res = ss.str();
      int i = 0;
      while (i < res.size() && res[i] == '0') i++;
      if (i == res.size()) return "0";
      return res.substr(i);
    }
};
