class TaskManager {
public:
struct Compare {
    bool operator()(const pair<int,int>&a, const pair<int,int>&b) {
        if (a.first == b.first) {
            return a.second < b.second;  
        }
        return a.first < b.first;  
    }
};
    unordered_map<int,int>tp;
    unordered_map<int,int>tu;
    priority_queue<pair<int,int>,vector<pair<int,int>>,Compare>pq;
    TaskManager(vector<vector<int>>& tasks) {
        for(int i=0;i<tasks.size();i++){
            int uid = tasks[i][0];
            int tid = tasks[i][1];
            int prio = tasks[i][2];
            tp[tid]=prio;
            tu[tid]=uid;
            pq.push({prio,tid});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        tp[taskId]=priority;
        tu[taskId]=userId;
        pq.push({priority,taskId});
    }
    
    void edit(int taskId, int newPriority) {
        tp[taskId]=newPriority;
        pq.push({newPriority,taskId});
    }
    
    void rmv(int taskId) {
            tp.erase(taskId);
            tu.erase(taskId);
    }
    
    int execTop() {
        while(!pq.empty()){
            int prio=pq.top().first;
            int tid=pq.top().second;
           if (tp.count(tid) && tp[tid] == prio) {
            int uid = tu[tid];
            pq.pop();
            tp.erase(tid);
            tu.erase(tid);
            return uid;
        }  

            else
            pq.pop();
            
        }

        return -1;

    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */