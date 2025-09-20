class Router {
public:
int memoryLimit;
 map<vector<int>, int> mpp;
 deque<vector<int>>router;
 unordered_map<int, vector<int>> timestamps;
 unordered_map<int, int> st; 
    Router(int memoryLimit): memoryLimit(memoryLimit) {
       
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        vector<int>newpack={source,destination,timestamp};
        if (mpp.count(newpack))
            return false;
        if((int)router.size()>=memoryLimit){
            vector<int>rem=router.back();
            mpp.erase(rem);
            st[rem[1]]++;
            router.pop_back();
        }
        router.push_front(newpack);
        mpp[newpack]++;
        timestamps[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        
        if(!router.empty()){
            vector<int>rem=router.back();
            router.pop_back();
            st[rem[1]]++;
            mpp.erase(rem);
            return rem;
        }
        return {};
        
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if(timestamps.find(destination) ==  timestamps.end())
        return 0;
        auto &it=timestamps[destination];
        int t=st[destination];
        auto r=lower_bound(it.begin()+t,it.end(),startTime);
        auto l=upper_bound(it.begin()+t,it.end(),endTime);
        return int(l-r);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */