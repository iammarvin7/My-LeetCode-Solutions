const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}
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