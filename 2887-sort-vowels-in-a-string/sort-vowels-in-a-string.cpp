class Solution {
public:
    string sortVowels(string s) {
        vector<char>vows;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c == 'A' || c == 'E' || c=='I' || c=='O' || c=='U' || c=='a' ||c=='e' || c=='i' || c=='o' || c=='u'){
                vows.push_back(c);
                s[i]='#';
            }
        }
        sort(vows.begin(),vows.end());
        // cout << vows;
        int j=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#'){
                s[i]=vows[j];
                j++;
            }
        }
        return s;
    }
};