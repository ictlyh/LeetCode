class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n == 0 ? false : (n == 1 ? true : (n % 2 == 1 ? false : isPowerOfTwo(n / 2)));
    }
};