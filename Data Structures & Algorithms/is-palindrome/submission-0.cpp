class Solution {
public:
    bool isPalindrome(string s) {
        string newStr = "";

        for (const char& ch : s) {
            if (isalnum(ch)) {
                newStr += tolower(ch);
            }
        }

        string revStr = newStr;
        reverse(revStr.begin(), revStr.end());

        return newStr == revStr;
    }
};