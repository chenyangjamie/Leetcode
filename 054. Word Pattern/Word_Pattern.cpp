/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if(pattern.empty() || str.empty()) return false;
        unordered_map<char, string> dict;
        unordered_map<string, char> dict2;
        vector<string> strs;
        strs = split(str);
        if(pattern.size() != strs.size()) return false;
        for (int i = 0; i < pattern.size(); i++) {
            if (dict.find(pattern[i]) != dict.end()){
                if(dict[pattern[i]] != strs[i])
                    return false;
            }
            else if (dict2.find(strs[i]) != dict2.end()){
                if(dict2[strs[i]] != pattern[i])
                    return false;
            }
            else {
                dict[pattern[i]] = strs[i];
                dict2[strs[i]] = pattern[i];
            }
        }
        return true;
    }
    
    vector<string> split(string str){
        vector<string> result;
        string s;
        for (int i = 0; i < str.size(); i++){
            if(str[i] != ' '){
                s.push_back(str[i]);
            }
            else{
                result.push_back(s);
                s.clear();
            }
        }
        result.push_back(s);
        return result;
    }
};
