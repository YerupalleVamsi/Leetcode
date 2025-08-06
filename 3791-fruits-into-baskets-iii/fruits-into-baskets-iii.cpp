class Solution {
public:
// segment tree ? Ez
vector<int> T;
void build(vector<int>&baskets,int tl, int tr , int n){
    if(tl==tr){
        T[n]=baskets[tl]; // assigning the val in leaf nodes vamsi-chan :)
        return;
    }
    int tm=(tl+tr)/2;
    build(baskets,tl,tm,2*n); // left - side
    build(baskets,tm+1,tr,2*n+1); // right - side
T[n] = max(T[2*n],T[2*n+1]); // so we knew for range sumQ ---> T[n]= T[2*n]+t[2*n+1] so for the curr problem we take max

}

int bin_search(int n, int l, int r, int k){
    if(T[n] < k)return -1; // we cant take if we have the basket < fruit
    if(l==r){
        // left node
        T[n]=-1;
        return l;
    }
    int m=(l+r)/2;
    int pos= (T[2*n] >=k) ? /*go left*/ bin_search(2*n,l,m,k) : /*right*/ bin_search(2*n+1,m+1,r,k);
    // build the segTree after placing the fruit
    T[n]=max(T[2*n],T[2*n+1]);
    return pos;

}

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        // simply use the segTree
        // segTree takes O(4*n) space ---> iykyk nigga
        T.assign(4*n,0); // initalise the tree with size 4*n and filled with 0's 
        build(baskets,0,n-1,1); // we start the segTree with index 1 
        int rem_fruits=0;
        for(int i=0;i<n;i++){
            if(bin_search(1,0,n-1,fruits[i]) == -1) // which means unplaced
            rem_fruits++;
        }
        return rem_fruits;

    }
};