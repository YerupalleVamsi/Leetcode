class Solution {
public:

    string intToBinary(int n) {
    if (n == 0) {
        return "0";
    }
    string binaryString = "";
    while (n > 0) {
        binaryString += (n % 2 == 0 ? "0" : "1");
        n /= 2;
    }
    reverse(binaryString.begin(), binaryString.end());
    return binaryString;
}
    string convertDateToBinary(string s) {
        string y=s.substr(0,4);
        string m=s.substr(5,2);
        string d=s.substr(8,2);
        int Y=stoi(y);
        int M=stoi(m);
        int D=stoi(d);
        y=intToBinary(Y);
        m=intToBinary(M);
        d=intToBinary(D);
        return y+'-'+m+'-'+d;


    }
};