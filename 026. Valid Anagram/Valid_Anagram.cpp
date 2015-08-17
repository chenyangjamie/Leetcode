/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.
*/


//44ms solution with hash table
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char,int> hash_table;
        int index[26] = {0};
        for(int i = 0; i < s.length(); i++){
            index[(int)s[i]-'a']++;
            hash_table[s[i]] = index[(int)s[i]-'a'];
        }
        for(int i = 0; i < t.length(); i++){
            auto got = hash_table.find(t[i]);
            if( got == hash_table.end() )
                return false;
            else{
                if(got->second > 0)
                    got->second--;
                else return false;
            }
        }
        return true;
    }
};

/* 12ms solution with array
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int count[26] = {0};
        for(int i = 0; i < s.length(); i++){
            count[s[i]-'a']++;
        }
        for(int i = 0; i < t.length(); i++){
            count[t[i]-'a']--;
        }
        for(int i = 0; i < t.length(); i++){
            if(count[t[i]-'a'] != 0)
                return false;
        }
        return true;
    }
};
*/
