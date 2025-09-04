class Solution {
public:
    int findClosest(int x, int y, int z) {
        if(abs(y-z)==abs(x-z))return 0;
        return abs(y-z)<abs(x-z)? 2:1;
    }
};