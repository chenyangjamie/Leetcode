/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Subscribe to see which companies asked this question
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                sta.push(s[i]);
            }
            else {
                if(sta.empty()) return false;
                switch (s[i]){
                    case ')': 
                        if(sta.top()=='('){
                            sta.pop();
                        }
                        else return false;
                        break;
                    case ']':
                        if(sta.top()=='['){
                            sta.pop();
                        }
                        else return false;
                        break;
                    case '}':
                        if(sta.top()=='{'){
                            sta.pop();
                        }
                        else return false;
                        break;
                }
            }
        }
        if(sta.empty()) return true;
        return false;
    }
};
