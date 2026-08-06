class Solution {
   public:
    string encode(vector<string>& strs) {
        string encoded_string = "";

        for(const string& s : strs) {
            encoded_string += to_string(s.size());
            encoded_string += '#';
            encoded_string += s;
        }

        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;

        while(i < s.size()) {
            string length = "";

            while(s[i] != '#') {
                length += s[i];
                i++;
            }

            i++; // skip '#'

            int len = stoi(length);
            string current_str = "";

            for(int j = 0 ; j < len ; j++) {
                current_str += s[i];
                i++;
            }

            decoded.push_back(current_str);
        }

        return decoded;
    }
};
