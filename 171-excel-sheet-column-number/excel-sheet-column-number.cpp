class Solution {
public:
    int titleToNumber(string columnTitle) {
      int colnum=0;
      for(char ch:columnTitle)
      {
        colnum*=26;
        colnum+=ch-'A'+1;
      }  
      return colnum;
    }
};