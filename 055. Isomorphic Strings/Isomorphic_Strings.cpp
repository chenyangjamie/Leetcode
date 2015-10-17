/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (!s.compare(t)) return true;
        string sm = mapFunc(s);
        string tm = mapFunc(t);
        return !(sm.compare(tm));
    }
    string mapFunc(string str) {
        unordered_map<char,char> strMap;
        char n = '1';
        for (int i=0; i<str.size(); i++) {
            if (strMap.find(str[i]) == strMap.end()) {
                strMap[str[i]] = n;
                str[i] = n;
                n++;
            } else {
                str[i] = strMap[str[i]];
                n++;
            }
        }
        return str;
    }
};
