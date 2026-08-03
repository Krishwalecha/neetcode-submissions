class Solution {
private:
    bool checkIfIsAnagram(string s1, string s2) {
        unordered_map<char, int> freq;

        for(char ch : s1) {
            freq[ch]++;
        }

        for(char ch : s2) {
            if(--freq[ch] < 0) return false;
        }

        return true;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> hash(strs.size(), 0);
        vector<vector<string>> ans;

        for(int i = 0 ; i < strs.size() ; i++) {
            if(!hash[i]) {
                hash[i] = 1;
                vector<string> temp;
                string str1 = strs[i];

                for(int j = i + 1 ; j < strs.size() ; j++) {
                    if(!hash[j]) {
                        string str2 = strs[j];
                        if(str1.length() != str2.length()) continue;
                        bool isAnagram = checkIfIsAnagram(str1, str2);

                        if(isAnagram) {
                            hash[j] = 1;
                            temp.push_back(str2);
                        }
                    }
                }
                temp.push_back(str1);
                ans.push_back(temp);
            }
        }

        return ans;
    }
};
