/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/

class Solution {
public:
    string convertToTitle(int n) {
        string s;
        if(n == 1) return "A";
        while(n != 0){
            n = n-1;
            int letter;
            letter = n % 26;
            s.insert(s.begin(), (char)letter+65);
            n = n / 26;
        }
        return s;
    }
};
