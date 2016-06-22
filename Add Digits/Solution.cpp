class Solution {
public:
    int addDigits(int num) {
        if(num == 0) return 0;
        int r = num % 9;
        return r == 0 ? 9 : r;
    }
};