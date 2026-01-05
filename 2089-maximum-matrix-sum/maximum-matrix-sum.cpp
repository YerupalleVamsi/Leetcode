class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int N  = matrix.size();

        long long abs_sum = 0;

        int mini = INT_MAX;

        int neg = 0;

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){

                int element  = matrix[i][j];

                if(element < 0){

                    neg++;

                } 
              
                abs_sum += abs(element);
                mini = min(mini,abs(element));
            }
        }

        if(neg%2==0) return abs_sum;

        return abs_sum - 2ll*mini;
    }
};