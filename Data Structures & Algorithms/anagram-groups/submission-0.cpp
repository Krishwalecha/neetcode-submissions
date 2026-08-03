class Solution {
private:
    bool checkIfIsAnagram(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return (s1 == s2);
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
