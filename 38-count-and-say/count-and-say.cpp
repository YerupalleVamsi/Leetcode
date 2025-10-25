class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string curr = "1";
        n--;
        while(n--){
            string res="";
            int cnt=1;
            for(int i=1;i<curr.size();i++){
                if(curr[i] == curr[i-1]){
                    cnt++;
                }
                else{
                    res = res + to_string(cnt) + curr[i-1];
                    cnt=1;
                }
            }
            res = res + to_string(cnt) + curr.back();
            // cout << res << " " << n << endl;
            curr = res; 
        }
        return curr;
    }
};