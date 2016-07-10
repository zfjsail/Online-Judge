class Solution {
private:
    void qsort(vector<int>& a, int s, int t) {
        if(s >= t) return;
        int i = s, j = t;
        int pivot = a[s];
        while(i < j) {
            while(a[j] > pivot && i < j) j--;
            if(i < j) a[i++] = a[j];
            while(a[i] < pivot && i < j) i++;
            if(i < j) a[j--] = a[i];
        }
        a[i] = pivot;
        qsort(a, s, i-1);
        qsort(a, i+1, t);
    }
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        qsort(nums1, 0, len1-1);
        qsort(nums2, 0, len2-1);
        int i = 0, j = 0;
        vector<int> r;
        while(i < len1 && j < len2) {
            if(nums1[i] == nums2[j]) {
                r.push_back(nums1[i]);
                i++; j++;
            }
            else if(nums1[i] < nums2[j]) i++;
            else j++;
        }
        return r;
    }
};