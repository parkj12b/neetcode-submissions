#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            int val = target - nums[i];
            if (m.contains(val))
                return {m[val], i};
            m[nums[i]] = i;
        }
        return {};
        
    }
};
