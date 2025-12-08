class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int s = 0, e = (n*m -1);

        while(s <= e){
            int mid = e - (e-s)/2;
            int row = mid/n, col = mid%n;
            if (matrix[row][col]==target) return true;
            if(matrix[row][col] > target){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }

        return false;
    }
};