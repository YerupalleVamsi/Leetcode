class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
    if (nums1 == nums2) return 0;
        queue<pair<int, vector<int>>> q;
        set<vector<int>> vis;
        q.push({0, nums1});
        vis.insert(nums1);
        while(!q.empty()){
            auto [steps,curr] = q.front();
            q.pop();
            for(int l=0;l<curr.size();l++){
                for(int r=l;r<curr.size();r++){
                    vector<int>rem;
                    for(int i=0;i<l;i++){
                        rem.push_back(curr[i]);
                    }
                    for(int i=r+1;i<curr.size();i++){
                        rem.push_back(curr[i]);
                    }
                    vector<int> slice(curr.begin() + l, curr.begin() + r + 1);
                    for (int pos = 0; pos <= rem.size(); pos++) {
                        vector<int> next = rem;
                        next.insert(next.begin() + pos, slice.begin(), slice.end());
                        if (next == nums2) return steps + 1;
                        
                        if (!vis.count(next)) {
                            vis.insert(next);
                            q.push({steps+1, next});
                        }
                    }
                }
            }
        }
        return -1;
    }
};