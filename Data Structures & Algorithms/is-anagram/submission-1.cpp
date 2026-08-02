class Solution {
public:
    bool isAnagram(string s, string t) {

        if(!(s.size() == t.size())) return false;
        
        unordered_map<char, int> freq1;
        unordered_map<char, int> freq2;

        for(char ch : s) {
            freq1[ch]++;
        }

        for(char ch : t) {
            freq2[ch]++;
        }

        for(char ch : s) {
            if(!(freq1[ch] == freq2[ch])) return false;
        }

        return true;
    }
};
