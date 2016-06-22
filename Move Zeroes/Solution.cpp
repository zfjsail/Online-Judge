class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int* p = &nums[0];
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i]) {
                if(p != &nums[i]) {
                    int tmp = *p;
                    *p = nums[i];
                    nums[i] = tmp;
                }
                p++;
            }
        }
    }
};