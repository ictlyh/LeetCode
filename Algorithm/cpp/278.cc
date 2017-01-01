// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
  public:
    int firstBadVersion(int n) {
      long long l = 1;
      long long r = n;
      while (l < r) {
        long long mid = (l + r) / 2;
        if (isBadVersion(mid)) {
          if (mid == 1 || !isBadVersion(mid - 1)) return mid;
          else r = mid - 1;
        } else {
          if (isBadVersion(mid + 1)) return mid + 1;
          else l = mid + 1;
        }
      }
      return l;
    }
};
