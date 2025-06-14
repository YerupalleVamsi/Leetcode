class Solution {
public:
    int maxDiff(int num) {
        string n = to_string(num);
        int non_nine = -1;
        for (char ch : n) {
            int d = ch - '0';
            if (non_nine == -1 && d != 9) {
                non_nine = d;
                break;
            }
        }

        int non_zero = -1;
        for (char ch : n) {
            int d = ch - '0';
            if (non_zero == -1 && d != 1 && d != 0) {
                non_zero = d;
                break;
            }
        }

     
        string maxi = "";
        for (char ch : n) {
            int d = ch - '0';
            if (d == non_nine) {
                maxi += '9';
            } else {
                maxi += ch;
            }
        }
   
     string mini = "";
        for (char ch : n) {
            int d = ch - '0';
            if (d == non_zero) {
                if (n[0] == ch)
                    mini += '1';
                else
                    mini += '0';
            } else {
                mini += ch;
            }
        }

        int maxim = stoi(maxi);
        int minim = stoi(mini);
        return maxim - minim;
    }
};
