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
