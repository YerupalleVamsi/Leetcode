class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count=0;
        set<int>unq(nums.begin(),nums.end());
        if(unq.size()==nums.size()){
            return 0;
        }
        while(unq.size()!=nums.size()&&nums.size()>3){
            nums.erase(nums.begin(),nums.begin()+3);
            count++;
            unq.clear();
            unq.insert(nums.begin(),nums.end());
        }
        if (nums.size()==unq.size()){
            return count;
        }
        if(nums.size()!=unq.size() && nums.size()<=3){
            count++;
        }
        return count;

    }
};