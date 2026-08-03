class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;

        for (const string& s : strs) {
            vector<int> freq(26, 0);

            for (char ch : s)
                freq[ch - 'a']++;

            string key;
            for (int x : freq) {
                key += "#";
                key += to_string(x);
            }

            res[key].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto& [_, group] : res)
            ans.push_back(group);

        return ans;
    }
};