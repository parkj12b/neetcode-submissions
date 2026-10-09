class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int max_streak = 0;

        for (int num: nums) {
            if (st.count(num - 1)) continue; // skip if in the middle or end

            int streak = 1;
            int curNum = num + 1;

            while (st.count(curNum)) {
                streak++;
                curNum++;
            }

            max_streak = streak > max_streak ? streak : max_streak;
        }
        return max_streak;
    }
};
