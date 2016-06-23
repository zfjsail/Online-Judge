#include <map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> mmap;
        for(int i = 0; i < nums.size(); i++) {
            if(mmap.count(nums[i]) <= 0) {
                mmap[nums[i]] = 1;
            }
            else return true;
        }
        return false;
    }
};