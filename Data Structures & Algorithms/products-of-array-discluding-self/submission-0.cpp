class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero_count = 0;
        vector<int> ans;

        long long product = 1;

        for (int num: nums) {
            if (num == 0) {
                zero_count++;
                if (zero_count > 1)
                    break;
                continue;
            }
            product *= num;
        }

        for (int num: nums) {
            if (zero_count > 1)
                ans.push_back(0);
            else if (num != 0 && zero_count > 0) {
                ans.push_back(0);
            } else {
                if (num == 0)
                    ans.push_back(product);
                else
                    ans.push_back(product / num);
            }
        }
        return ans;
    }
};
