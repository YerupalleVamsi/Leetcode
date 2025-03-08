class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        int minedits=INT_MAX;
        for(int i=0;i<=blocks.size()-k;i++){
            int edits=0;
            for(int j=i;j<i+k;j++){
                if(blocks[j]=='W'){
                    edits++;
                }
            }
           minedits = min(minedits, edits);
        }return minedits;
    }
};