#include <iostream>

class Solution {
public:
    bool isAnagram(string s, string t) {

        int char_map[27];

        if (s.size() != t.size())
            return false;
        
        for (int j = 0; j < 27; j++) {
            char_map[j] = 0;
        }

        for (int i = 0; i < s.size(); i++) {
            char_map[s[i] - 'a']++;
            char_map[t[i] - 'a']--;
        }

        for (int i = 0; i < 27; i++) {
            if (char_map[i] != 0)
                return false;
        }
        return true;

    }
};
