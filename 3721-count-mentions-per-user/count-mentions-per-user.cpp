class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        vector<int>Mentions(n,0);
      sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b){
    long long t1 = stoll(a[1]);
    long long t2 = stoll(b[1]);
    if(t1 != t2) return t1 < t2;
    if(a[0]=="OFFLINE" && b[0]!="OFFLINE") return true;
    if(a[0]!="OFFLINE" && b[0]=="OFFLINE") return false;
    return false;
});

    
    unordered_set<int>online;
    
    for(int i=0;i<n;i++){
        online.insert(i);
    }


    unordered_map<int,int>offline_time;
    unordered_set<int>offline;
    int all = 0;

    for(int i=0;i<events.size();i++){
        string type = events[i][0];
        long long time = stoi(events[i][1]);
        string mentions = events[i][2];
        if(type == "OFFLINE"){
            int id = stoi(mentions);
            offline_time[id] = time;
            online.erase(id);
            offline.insert(id);
            continue;
        }
        for (auto it = offline_time.begin(); it != offline_time.end(); ){

                if(time - it->second >= 60){
                    offline.erase(it->first);
                    online.insert(it->first);
                    it = offline_time.erase(it);
                }
                else{
                    it++;
                }
            }

            if(mentions =="ALL"){
                all++;
                continue;
            }
            if(mentions == "HERE"){
                for(auto it:online){
                    Mentions[it]++;
                }
                continue;
            }
            for (int i = 0; i < mentions.size(); i++) {
            if (mentions[i] == 'i' && i + 1 < mentions.size() && mentions[i + 1] == 'd') {
                i += 2;
            int num = 0;
            while (i < mentions.size() && isdigit(mentions[i])) {
            num = num * 10 + (mentions[i] - '0');
            i++;
                }
                Mentions[num]++;
             }}


    }
    for(int i=0;i<n;i++){
        Mentions[i]+=all;
    }
    return Mentions;
    }
};