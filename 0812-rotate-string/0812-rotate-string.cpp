class Solution {
public:
    bool rotateString(string s, string goal) {
         if (s.length() != goal.length()) return false;  // If lengths are different, they can't be rotations of each other
    return (s + s).find(goal) != string::npos;  // Check if goal is a substring of s + s
    }
};