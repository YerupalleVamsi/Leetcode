class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char,int> freq;
        for(char ch : word)
            freq[ch]++;
        set<int> s;
        for(auto &it : freq)
            s.insert(it.second);

        if(s.size() == 1){
            int val = *s.begin();
            if(val == 1 || freq.size() == 1)
                return true;
            else
                return false;
        }

        if(s.size() == 2){
            int low = *s.begin();
            int high = *s.rbegin();
            int lowCount = 0, highCount = 0;

            for(auto &it : freq){
                if(it.second == low) lowCount++;
                else if(it.second == high) highCount++;
            }
            if((low == 1 && lowCount == 1) || 
               (high - low == 1 && highCount == 1))
                return true;
        }

        return false;
    }
};
