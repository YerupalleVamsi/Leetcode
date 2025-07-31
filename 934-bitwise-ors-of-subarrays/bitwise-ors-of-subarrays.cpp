class Solution {
public:
// ok we have to count the number of subarrays with distinct OR
    int subarrayBitwiseORs(vector<int>& arr) {
    unordered_set<int> result, curr;
    int n=arr.size();
    for (int i = 0; i < n; ++i) {
        unordered_set<int> next;
        next.insert(arr[i]);
        for (int x : curr)
            next.insert(x | arr[i]);
        curr = next;  
        for (int x : curr)
            result.insert(x);
}
return result.size();
    }
};