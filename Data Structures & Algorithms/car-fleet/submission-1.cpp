class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // time it takes = remaining / speed
        // if i - 1 position car is faster than front = fleet
        // make the fleet speed into front

        // since position doesn't come in order, group them and sort

        using pii = pair<int, int>;
        vector<pii> st;

        for (int i = 0; i < position.size(); i++) {
            st.push_back({position[i], speed[i]});
        }

        sort(st.begin(), st.end());

        int ans = 0;

        while (!st.empty()) {
            auto front = st.back(); st.pop_back();
            double time_taken = (target - front.first) / (double) front.second; 

            while(!st.empty()) {
                auto cur = st.back();
                double time_cur_taken = (target - cur.first) / (double) cur.second;


                cout << time_cur_taken << " " << time_taken << endl;
                if (time_cur_taken > time_taken)
                    break ;
                st.pop_back();
            }
            ans++;
        }
        return ans;
    }
};
