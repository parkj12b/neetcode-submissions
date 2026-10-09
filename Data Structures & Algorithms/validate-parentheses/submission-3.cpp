class Solution {
public:
    char match_bracket(char c) {
        switch (c) {
            case '(':
                return ')';
            case '{':
                return '}';
            case '[':
                return ']';
        }
        return '.';
    }

    bool isValid(string s) {
        vector<char> st;

        for (char c: s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push_back(c);
            } else {
                if (st.empty())
                    return false;
                if (match_bracket(st.back()) != c)
                    return false;
                st.pop_back();
            }
        }
        if (!st.empty())
            return false;
        return true;
    }
};
