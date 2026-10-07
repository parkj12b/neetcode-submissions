#include <iostream>

class Solution {
public:
    bool isAnagram(string s, string t) {

        int char_map[27][2];

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 27; j++) {
                char_map[j][i] = 0;
            }
        }
        
        for (char c : s) {
            char_map[c - 'a'][0]++;
        }

        for (char c : t) {
            char_map[c - 'a'][1]++;
        }

        for (int i = 0; i < 27; i++) {
            if (char_map[i][0] != char_map[i][1])
                return false;
        }
        return true;

    }
};
