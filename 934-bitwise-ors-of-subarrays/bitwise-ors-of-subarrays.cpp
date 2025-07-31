class Solution {
public:
// ok we have to count the number of subarrays with distinct OR
// use set nigga
    int subarrayBitwiseORs(vector<int>& arr) {
    unordered_set<int> result, curr;
    int n=arr.size();
    for (int i = 0; i < n; ++i) {
        unordered_set<int> next;
        next.insert(arr[i]); // start 
        for (int x : curr)
            next.insert(x | arr[i]); // or with prev set
        curr = next;  // so in the next iteration we can use the curr to OR
        for (int x : curr)
            result.insert(x); // store all the or vals
}
return result.size();
    }
};