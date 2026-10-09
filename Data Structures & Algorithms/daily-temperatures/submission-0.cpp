class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> st, ans; // keep indexes in the stack
        ans.resize(temperatures.size());

        for (int i = 0; i < temperatures.size(); i++) {
            if (st.empty()) {
                st.push_back(i);
                continue;
            }
            int cur_temp = temperatures[i];
            
            while (!st.empty() && cur_temp > temperatures[st.back()]) {
                ans[st.back()] = i - st.back();
                st.pop_back();
            }
            st.push_back(i);
        }

        while (!st.empty()) {
            ans[st.back()] = 0;
            st.pop_back();
        }

        return ans;

    }
};
