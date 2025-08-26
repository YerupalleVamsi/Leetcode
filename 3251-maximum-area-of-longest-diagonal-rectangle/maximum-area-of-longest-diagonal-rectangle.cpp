class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dim) {
        long long max_area=0;
        double diag=INT_MIN;
        int dia_index=-1;
        for(int i=0;i<dim.size();i++){
            double curr_diag=sqrt(dim[i][0]*dim[i][0]+dim[i][1]*dim[i][1]);
            long long curr_area=dim[i][0]*dim[i][1]*1LL;
            if(curr_diag>diag){
                diag=curr_diag;
                max_area=curr_area;
            }
            if(curr_diag==diag){
                max_area=max(max_area,curr_area);
            }
        }
        return max_area;
    }
};