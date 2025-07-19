class Solution {
public:
    string largestOddNumber(string num) {
        string res="";
        int n=num.size();
        int end=-1;
        for(int i=n-1;i>=0;i--){
            char c=num[i];
            int x=c-'0';
            if(x%2==1){
                end=i;
                break;
            }
        }
        if(end==-1){
            return res;
        }
        res=num.substr(0,end+1);
        return res;
    }
};