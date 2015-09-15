/*
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
Hint:

Did you see a pattern in dividing the number into chunk of words? For example, 123 and 123000.
Group the number by thousands (3 digits). You can write a helper function that takes a number less than 1000 and convert just that chunk to words.
There are many edge cases. What are some good test cases? Does your code work with input such as 0? Or 1000010? (middle chunk is zero and should not be printed out)
*/


class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string result;
        int temp;
        int i = 1;
        int j = 0;
        while(num != 0){
            temp = num % 10;
            if(i == 1 && j > 0 && (temp != 0 || (num / 10) % 10 != 0 || ((num / 10) / 10) % 10 != 0)){
                string word;
                word = trans_times(j);
                result.insert(0,word);
            }
            if(i == 1){
                string word;
                int tens = num / 10;
                tens = tens % 10;
                if(tens == 1)
                    word = trans1_digi(temp);
                else word = trans_digi(temp);
                result.insert(0,word);
            }
            if(i == 2){
                string word;
                word = transtens_digi(temp);
                result.insert(0,word);
            }
            if(i == 3){
                if(temp != 0)
                    result.insert(0," Hundred");
                string word;
                word = trans_digi(temp);
                result.insert(0,word);
            }
            num /= 10;
            if(i == 3){
                i = 1;
                j += 1;
            }
            else i++;
        }
        result.erase(result.begin());
        return result;
    }
    string trans_digi(int digi){
        switch (digi){
            case 0: return "";
            case 1: return " One";
            case 2: return " Two";
            case 3: return " Three";
            case 4: return " Four";
            case 5: return " Five";
            case 6: return " Six";
            case 7: return " Seven";
            case 8: return " Eight";
            case 9: return " Nine";
        }
    }
    string trans1_digi(int digi){
        switch (digi){
            case 0: return " Ten";
            case 1: return " Eleven";
            case 2: return " Twelve";
            case 3: return " Thirteen";
            case 4: return " Fourteen";
            case 5: return " Fifteen";
            case 6: return " Sixteen";
            case 7: return " Seventeen";
            case 8: return " Eighteen";
            case 9: return " Nineteen";
        }
    }
    string transtens_digi(int tens_digi){
        switch (tens_digi){
            case 0: return "";
            case 1: return "";
            case 2: return " Twenty";
            case 3: return " Thirty";
            case 4: return " Forty";
            case 5: return " Fifty";
            case 6: return " Sixty";
            case 7: return " Seventy";
            case 8: return " Eighty";
            case 9: return " Ninety";
        }
    }
    string trans_times(int times){
        switch (times){
            //case 0: return "";
            case 1: return " Thousand";
            case 2: return " Million";
            case 3: return " Billion";
        }
    }
};
