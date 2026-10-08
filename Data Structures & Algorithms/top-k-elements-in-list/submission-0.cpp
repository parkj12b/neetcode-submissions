class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;

        unordered_map<int, int> freq; // num, freq
        for (int num: nums) {
            freq[num]++;
        }

        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        for (auto &[num, freq]: freq) {
            pq.push({freq, num});
            if (pq.size() > k)
                pq.pop();
        }
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
