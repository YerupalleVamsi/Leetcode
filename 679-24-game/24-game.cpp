class Solution {
public:
    const double tar=24.0;
    bool judgePoint24(vector<int>& cards) {
        int n=cards.size();
        vector<double>real(cards.begin(),cards.end());
        return backtrack(real);
    }
    bool backtrack(vector<double>&real){
        if(real.size()==1)return fabs(real[0]-tar)<1e-6;
        for(int i=0;i<real.size();i++){
            for(int j=i+1;j<real.size();j++){
                vector<double>next;
                for(int k=0;k<real.size();k++)
                if(k!=i && k!=j)
                next.push_back(real[k]);

                for(double t: oper(real[i],real[j])){
                    next.push_back(t);
                    if(backtrack(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }
    unordered_set<double> oper(double a,double b){
        unordered_set<double> res;
        res.insert(a+b);
        res.insert(a*b);
        res.insert(a-b);
        res.insert(b-a);
        if(fabs(a) > 1e-6 )res.insert(b/a);
        if(fabs(b)> 1e-6) res.insert(a/b);
        return res;
    }
};