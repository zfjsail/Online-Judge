class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int major;
        for(int i = 0; i < nums.size(); i++) {
            if(cnt == 0) {
                major = nums[i];
                cnt = 1;
            }
            else {
                if(nums[i] == major) {
                    cnt++;
                }
                else {
                    cnt--;
                }
            }
        }
        return major;
    }
};