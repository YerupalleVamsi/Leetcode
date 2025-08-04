class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if(fruits.size()<2)return fruits.size();
        int l=0;
        int max_length=1;
        unordered_map<int,int>freq;
        for(int r=0;r<fruits.size();r++){
            freq[fruits[r]]++;
            while(freq.size()>2){
                freq[fruits[l]]--;
                if(freq[fruits[l]]==0)
                freq.erase(fruits[l]);
                l++;
            }
            if(freq.size()<=2)
            max_length=max(max_length,r-l+1);
        }
        return max_length;
    }
};