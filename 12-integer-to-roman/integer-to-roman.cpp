
/*  I	1
    V	5    
    X	10
    L	50
    C	100
    D	500
    M	1000  */ 

// 1 <= num <= 3999

class Solution {
public:
    string intToRoman(int num) {
        string ans="";
        vector<pair<string,int>> lookup={
        {"M", 1000},
        {"CM", 900},
        {"D", 500},
        {"CD", 400},
        {"C", 100},
        {"XC", 90},
        {"L", 50},
        {"XL", 40},
        {"X", 10},
        {"IX", 9},
        {"V", 5},
        {"IV", 4},
        {"I", 1}
            
        };
            for (auto const& [symbol, value] : lookup) {
        while (num >= value) {
            ans += symbol;
            num -= value;
        }
    }
    return ans;
    }
};