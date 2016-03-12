class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::map<int,int> mymap;
        for (int i = 0; i < nums.size(); i++) {
            std::map<int,int>::iterator ite = mymap.find(nums.at(i));
            if (ite != mymap.end()) {
                if (i - ite->second <= k) return true;
                else mymap[ite->first] = i;
            } else mymap.insert(std::pair<int,int>(nums.at(i),i));
        }
        return false;
    }
};