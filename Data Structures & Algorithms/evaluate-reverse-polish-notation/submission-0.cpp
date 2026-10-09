class Solution {
public:
    vector<int> v;

    bool is_op(string s) {
        if (s.length() > 1)
            return false;
        char c = s[0];
        
        switch (c) {
            case '+':
            case '-':
            case '*':
            case '/':
                return true;
            default:
                return false;
        }
        return false;
    }

    int do_op(int num1, int num2, char c) {
        switch (c) {
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
            case '*':
                return num1 * num2;
            case '/':
                return num1 / num2;
        }
        return 0;
    }

    int evalRPN(vector<string>& tokens) {

        for (string &token: tokens) {
            if (!is_op(token)) {
                v.push_back(stoi(token));
                continue;
            }

            char c = token[0];
            // assume always valid
            int num2 = v.back(); v.pop_back();
            int num1 = v.back(); v.pop_back();
            
            v.push_back(do_op(num1, num2, c));
            
        }
        return v.back();
    }
};
