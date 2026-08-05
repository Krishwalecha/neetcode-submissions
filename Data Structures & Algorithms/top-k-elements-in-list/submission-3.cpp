class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(const int& num : nums) {
            freq[num]++;
        }

        vector<vector<int>> arr(nums.size() + 1);

        for(const auto& i : freq) {
            arr[i.second].push_back(i.first);
        }

        vector<int> res;
        for(int i = nums.size() ; i >= 0 ; i--) {
            if(arr[i].size() == 0) continue;
            for(int num : arr[i]) res.push_back(num);
            if(res.size() == k) return res;
        }

        return res;
    }
};
