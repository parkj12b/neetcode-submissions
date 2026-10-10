class Solution {
public:
    bool isPalindrome(string s) {
        string clean_string;

        for (char c : s) {
            if (isalnum(c))
                clean_string += tolower(c);
        }
        string rs = clean_string;
        reverse(rs.begin(), rs.end());

        return rs == clean_string;
    }
};
