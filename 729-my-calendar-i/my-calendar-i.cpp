class MyCalendar {
public:
vector<pair<int,int>>p;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        for(auto &it:p){
            if(it.second > startTime && endTime > it.first){
                return false;
            }
        }
        p.push_back({startTime,endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */