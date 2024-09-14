class Solution {
public:
    bool rotateString(string s, string goal) {
        return ((s+s).contains(goal) && s.length()==goal.length());
    }
};