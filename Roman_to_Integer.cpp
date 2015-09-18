/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/


class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> table = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int result = 0;
        for(int i = 0; i<s.size(); i++){
            if(i<s.size() && table[s[i]] < table[s[i+1]]){ //add right
                result -= table[s[i]];
            }
            else{ //sub left
                result += table[s[i]];
            }
        }
        return result;
    }
};
