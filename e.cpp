class Solution {
public:
    vector<int> sumZero(int n) {
        int x[n];
        int sum;
        for (int i = 0; i < n; i++){
            for (int z = 0; z < n; z++){
                sum += x[z];
            }
            if (sum < 0){
                x[i] = 1;
            }else if (sum > 0){
                x[i] = -1;
            }else {x[i] = 0;}
            }
        }
    }
};