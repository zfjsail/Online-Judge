class Solution {
public:
    int titleToNumber(string s) {
        if(s.empty()) return 0;
        int r = 0;
        for(int i = 0; i < s.size(); i++) {
            r = r * 26 + (s[i] - 'A' + 1);
        }
        return r;
    }
};