/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
  public:
    Interval mergeTwoInterval(Interval val1, Interval val2) {
      int low = val1.start < val2.start ? val1.start : val2.start;
      int up = val1.end > val2.end ? val1.end : val2.end;
      Interval res(low, up);
      return res;
    }

    vector<Interval> insertInterval(vector<Interval>& intervals, Interval newInterval) {
      vector<Interval> res;
      res.push_back(newInterval);
      for (int i = 0; i < intervals.size(); i++) {
        Interval val = intervals[i];
        Interval back = res.back();
        if (val.end < back.start) {
          res.pop_back();
          res.push_back(val);
          res.push_back(back);
        }
        else if (val.start > back.end) {
          res.push_back(val);
        } else {
          res.pop_back();
          res.push_back(mergeTwoInterval(val, back));
        }
      }
      return res;
    }

    vector<Interval> merge(vector<Interval>& intervals) {
      vector<Interval> res;
      for (int i = 0; i < intervals.size(); i++)
        res = insertInterval(res, intervals[i]);
      return res;
    }
};
