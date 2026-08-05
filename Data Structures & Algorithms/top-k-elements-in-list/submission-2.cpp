class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (const int& num : nums) {
            freq[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (const auto& i : freq) {
            pq.push({i.second, i.first});
            if (pq.size() > k) pq.pop();
        }

        vector<int> res;

        for (int i = 0; i < k; i++) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
