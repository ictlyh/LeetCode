/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
	public:
		int maxPoints(vector<Point>& points) {
			int n = points.size();
			int result = 0;
			int i, j;
			for (int i = 0; i < n; i++) {
				int nSamePoint = 1;
				int nSameX = 0;
				unordered_map<double, int> myMap;
				for (j = i + 1; j < n; j++) {
					if (points[j].x == points[i].x && points[j].y == points[i].y)
						nSamePoint++;
					else if (points[j].x == points[i].x)
						nSameX++;
					else {
						float k = 1.0 * (points[j].y - points[i].y) / (points[j].x - points[i].x);
						if (myMap.count(k) == 0)
							myMap[k] = 1;
						else myMap[k]++;
					}
				}
				result = max(result, nSameX + nSamePoint);
				for (auto x = myMap.begin(); x != myMap.end(); x++)
					result = max(result, x->second + nSamePoint);
				myMap.clear();
			}
			return result;
		}
};

// Wrong Answer, why?
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
	public:
		bool isLine(Point& i, Point& j, Point& k) {
			return (i.x - j.x) * (j.y - k.y) == (i.y - j.y) * (j.x - k.x);
		}

		int maxPoints(vector<Point>& points) {
			if (points.size() <= 2) return points.size();
			int res = 2;
			for (int i = 0; i < points.size() - 2; i++) {
				for (int j = i + 1; j < points.size() - 1; j++) {
					int count = 2;
					for (int k = j + 1; k < points.size(); k++)
						if (isLine(points[i], points[j], points[k])) count++;
					res = max(res, count);
				}
			}
			return res;
		}
};
