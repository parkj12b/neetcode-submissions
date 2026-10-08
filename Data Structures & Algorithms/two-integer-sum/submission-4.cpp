#include <algorithm>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size() -1;
        vector<int> ans;
        vector<pair<int, int>> pairNums;
        for (int i = 0; i < nums.size(); i++)
            pairNums.push_back({nums[i], i});

        sort(pairNums.begin(), pairNums.end());

        while (left < right) {
            int numL = pairNums[left].first;
            int numR = pairNums[right].first;

            if (numL + numR == target) {
                ans.push_back(pairNums[left].second);
                ans.push_back(pairNums[right].second);
                break;
            }
            if (numL + numR < target) {
                left++;
                continue;
            } else {
                right--;
            }

        }        
        sort(ans.begin(), ans.end());
        return ans;
    }
};
