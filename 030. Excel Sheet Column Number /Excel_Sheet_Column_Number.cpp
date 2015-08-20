/*
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/

class Solution {
public:
    int titleToNumber(string s) {
        if(s.empty()) return 0;
        int result = 0;
        int i = 0;
        for(i=0; i < s.length(); i++){
            result += ((int)s[i]-64)*pow(26,s.length()-1-i);
        }
        return result;
    }
};
