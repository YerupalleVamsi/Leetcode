class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left=0;
        int max_length=1;
        unordered_map<int,int>freq;
        for(int right=0;right<fruits.size();right++){
            freq[fruits[right]]++;
            while (freq.size()>2){
                freq[fruits[left]]--;
                if(freq[fruits[left]]==0)
                    freq.erase(fruits[left]);
                    left++;
            }
            max_length=max(max_length,right-left+1);
        }
        return max_length;
    }
};