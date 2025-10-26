class Bank {
public:
    vector<long long> cred;
    int n;
    Bank(vector<long long>& balance) {
        cred = balance;
        n=balance.size()-1;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1-1 < 0 || account2-1<0 || account1-1>n || account2-1>n) return false;
        if(cred[account1-1] <  money) return false;
        cred[account1-1]-=money;
        cred[account2-1]+=money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(account-1<0 || account-1 >n) return false;
        cred[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account-1<0 || account-1 >n || cred[account-1] < money) return false;
        cred[account-1]-=money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */