class Solution {
public:
bool has0(int no)
{
    if(no==0)return true;
    while(no!=0)
    {
        if(no%10==0)return true;
        no=no/10;
    }
    return false;
}
    vector<int> getNoZeroIntegers(int n) {
        int a=n;
        int b=0;
        while(a>0){
            a--;
            b++;
            if(!has0(a) && !has0(b)) return {a,b};
        }
        return {a,b};
    }
};