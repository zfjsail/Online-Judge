class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        while(1) {
            if(n == 1) return true;
            int r = n & 1;
            if(r) return false;
            n >>= 1;
        }
        return true;
    }
};