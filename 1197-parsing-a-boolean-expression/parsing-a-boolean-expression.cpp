class Solution {
public:
    bool parseBoolExpr(string exp) {
        int n = exp.size();
        stack<char> st;

        for (int i = 0; i < n; i++) {
            if (exp[i] == ')') {
                bool a = true, o = false, val = true;
                while (!st.empty() && st.top() != '(' && st.top() != '!' && st.top() != '&' && st.top() != '|') {
                    char curr = st.top(); st.pop();
                    bool cur = (curr == 't');
                    a = a && cur;
                    o = o || cur;
                    val = cur;
                }
                if (!st.empty() && st.top() == '(') st.pop();
                if (!st.empty()) {
                    char op = st.top(); st.pop();
                    if (op == '!') st.push(val ? 'f' : 't');
                    else if (op == '|') st.push(o ? 't' : 'f');
                    else if (op == '&') st.push(a ? 't' : 'f');
                }
            } else if (exp[i] != ',') {
                st.push(exp[i]);
            }
        }
        return st.top() == 't';
    }
};