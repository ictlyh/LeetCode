/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
// LeetCode runtime error, but vs okay, why?
class Solution {
public:
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
  vector<Interval>::iterator ite = intervals.begin();
  while (ite != intervals.end() && ite->end < newInterval.start) ite++;
  while (ite != intervals.end() && ite->start <= newInterval.end) {
    newInterval = Interval(min(ite->start, newInterval.start), max(ite->end, newInterval.end));
    ite = intervals.erase(ite);
  }
  intervals.insert(ite, newInterval);
  return intervals;
}
};

class Solution {
	public:
		Interval merge(Interval val1, Interval val2) {
			int low = val1.start < val2.start ? val1.start : val2.start;
			int up = val1.end > val2.end ? val1.end : val2.end;
			Interval res(low, up);
			return res;
		}

		vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
			vector<Interval> res;
			// if (intervals.size() == 0) {
			// 	res.push_back(newInterval);
			// 	return res;
			// }
			// if (intervals.front().start > newInterval.end) {
			// 	intervals.insert(intervals.begin(), newInterval);
			// 	return intervals;
			// }
			// if (intervals.back().end < newInterval.start) {
			// 	intervals.push_back(newInterval);
			// 	return intervals;
			// }
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
					res.push_back(merge(val, back));
				}
			}
			return res;
		}
};
