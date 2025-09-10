class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& lang, vector<vector<int>>& friends) {
        // n < = 500 is small we can bf
        // first find the friends with a lang barrier
       vector<unordered_set<int>>s(lang.size());
       for(int i=0;i<lang.size();i++){
        for(int l:lang[i]){
            s[i].insert(l);
        }
       }
       unordered_set<int>intros;
       for(int i=0;i<friends.size();i++){
            // 1 - indexed nigga
        int x=friends[i][0]-1;
        int y=friends[i][1]-1;
        bool can_talk=false;
        for (int lang : s[x]) {
            if (s[y].count(lang)) {
                can_talk = true;
                break;
            }
        }

        if (!can_talk) {
            intros.insert(x);
            intros.insert(y);
        }
        }
        if(intros.size()==0) return 0;
        vector<int>langs_they_know(n+1);
        for (int u : intros) {               
            for (int l : s[u]) {             
                langs_they_know[l]++;        
        }
    }

    int most_known=0;
    for(int i:langs_they_know)
    most_known=max(most_known,i);
    return intros.size()-most_known;
    }
};