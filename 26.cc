class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        if (length < 2) return length;
        vector<int>::iterator curr = nums.begin();
        vector<int>::iterator next = nums.begin();
        next++;
        while (next != nums.end()) {
            if (*curr == *next) {
                next = nums.erase(next);
                length--;
            } else {
                curr++;
                next++;
            }
        }
        return length;
    }
};