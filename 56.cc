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



class Solution { 
  public:
    bool compare(Interval &a,Interval &b) { return a.start<b.start || (a.start==b.start&& a.end<b.end); }
    vector merge(vector& intervals) {
      int len = intervals.size();
      if(len==0|| len==1) return intervals;
      vector<Interval> v(intervals);
      sort(v.begin(),v.end(),compare);
      vector<Interval> vec;
      Interval pre = v[0],cur;
      for(int i=1;i<len;++i)
      {
        cur = v[i];
        if(cur.start>pre.end)
        {
          vec.push_back(pre);
          pre = cur;
        }
        else
        {
          if(cur.end>pre.end)
          {
            pre.end = cur.end;
          }

        }

      }

      vec.push_back(pre);

      return vec;

    }
};
