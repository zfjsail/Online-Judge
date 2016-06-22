class Solution {
public:
    string reverseString(string s) {
        string t;
        for(int i = 0; i < s.size(); i++) {
            t = s[i] + t;
        }
        return t;
    }
};