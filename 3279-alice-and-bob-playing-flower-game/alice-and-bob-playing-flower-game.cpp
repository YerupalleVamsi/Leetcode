class Solution {
public:
    long long flowerGame(int n, int m) {
        long long n_e=n/2;
        long long n_o=n-n_e;
        long long m_e=m/2;
        long long m_o=m-m_e;
        if((n_e == 0 && m_e == 0) || (n_o==0 && m_o == 0)  )return 0;

        return (1LL*n_e*m_o)+(1LL*m_e*n_o); 
    }
};