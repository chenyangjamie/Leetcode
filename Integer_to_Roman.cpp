/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,char> table={{1,'I'},{5,'V'},{10,'X'},{50,'L'},{100,'C'},{500,'D'},{1000,'M'}};
        int n, temp, temp2, i = 0;
        string result;
        while(num > 0){
            n = num % 10;
            if(0<n && n<4){
                temp = table[1*pow(10,i)];
                for(int j=0;j<n;j++){
                    result.insert(result.begin(),temp);
                }
            }
            if(n == 4){
                temp = table[1*pow(10,i)];
                temp2 = table[5*pow(10,i)];
                result.insert(result.begin(),temp2);
                result.insert(result.begin(),temp);
            }
            if(4<n && n<9){
                temp = table[1*pow(10,i)];
                temp2 = table[5*pow(10,i)];
                for(int j=0;j<n-5;j++){
                    result.insert(result.begin(),temp);
                }
                result.insert(result.begin(),temp2);
            }
            if(n == 9){
                temp = table[1*pow(10,i)];
                temp2 = table[10*pow(10,i)];
                result.insert(result.begin(),temp2);
                result.insert(result.begin(),temp);
            }
            num /= 10;
            i++;
        }
        return result;
    }
};
