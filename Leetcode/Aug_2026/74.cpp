class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int rl = 0, rh = m-1;
        int ri = -1;
        while(rl <= rh) {
            int mid = rl + (rh-rl)/2;
            if(matrix[mid][0] > target) {
                rh = mid-1;
            } else if(matrix[mid][n-1] < target) {
                rl = mid+1;
            } else {
                ri = mid;
                break;
            }
        }
        if(ri == -1) {
            return false;
        }
        int l = 0, r = n-1;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(matrix[ri][mid] == target) {
                return true;
            } else if(matrix[ri][mid] > target) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return false;
    }
};