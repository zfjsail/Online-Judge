#include<iostream>
using namespace std;

class Solution {
public:
    void qsort(string& s, int st, int ed) {
        if(st < ed) {
            int i = st, j = ed;
            char pvt = s[st];
            while(i < j) {
                while(pvt < s[j] && i < j) j--;
                if(i < j) s[i++] = s[j];
                while(pvt > s[i] && i < j) i++;
                if(i < j) s[j--] = s[i];
            }
            s[i] = pvt;
            qsort(s, st, i-1);
            qsort(s, i+1, ed);
        }
    }
    bool isAnagram(string s, string t) {
        int lens = s.length();
        int lent = t.length();
        if(lens != lent) return false;
        qsort(s, 0, lens-1);
        qsort(t, 0, lent-1);
        cout << s << endl << t << endl;
        if(s.compare(t) == 0) return true;
        else return false;
    }
};

int main() {
    Solution solution;
    string s = "a";
    string t = "b";
    cout << solution.isAnagram(s, t);
}
