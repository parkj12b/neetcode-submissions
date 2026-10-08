#include <string>

class Solution {
public:

    string encode(vector<string>& strs) {
        string buf;
        
        for (auto &str: strs) {
            buf += to_string(str.size());
            buf += '#';
            buf += str;
        }
        return buf;
    }

    vector<string> decode(string s) {
        cout << s << endl;
        vector<string> ans;
        int cursor = 0;

        while (cursor < s.size()) {
            int size_length = 0;
            while (s[size_length + cursor]  !=  '#') {
                size_length++; 
            }

            int size = std::stoi(s.substr(cursor, size_length));

            cursor += size_length + 1; // +1 to mitigate #

            ans.push_back(s.substr(cursor, size));
            cursor += size;
        }
        return ans;
    }
};
