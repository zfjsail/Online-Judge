class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 0) return 0;
        int* p = &nums[0];
        //int* q = p;
        //int last = *p;
        int len = sz;
        for(int i = 1; i < sz; i++) {
            if(nums[i] > *p) {
                p++;
                if(p != &nums[i]) {
                    int tmp = *p;
                    *p = nums[i];
                    nums[i] = tmp;
                }
            }
            else {
                len--;
            }
        }
        return len;
    }
};