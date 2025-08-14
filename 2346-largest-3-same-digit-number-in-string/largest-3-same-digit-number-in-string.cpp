class Solution {
public:
    string largestGoodInteger(string num) {
        string gi="";
        int lar=INT_MIN;
        int curr=-1;
        for(int i=0;i<num.size();i++){
            if(num[i]==num[i+1] && num[i+1]==num[i+2]){
            curr=num[i]-'0';
            lar=max(curr,lar);}
            
        }
        if(lar==INT_MIN){
            return gi;
        }
        string nm=to_string(lar);
        return nm+nm+nm;


    }
};