class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> st;

        // if one smaller comes in pop the tall one, calculate rectangle for the popped
        // we can get the index of the next small one to measure how long 2 will be

        st.push_back(0);
        heights.push_back(0);
        int max_area = 0;
        for (int i = 1; i < heights.size(); i++) {

            
            while (!st.empty() && heights[i] < heights[st.back()]) {
                int index = st.back(); st.pop_back();
                int st_top_index = st.empty() ? 0 : st.back() + 1;

                int area = (i - st_top_index ) * heights[index];
                if (area > max_area)
                    max_area = area;
            }
            st.push_back(i);
        }
        return max_area;
    }
};
