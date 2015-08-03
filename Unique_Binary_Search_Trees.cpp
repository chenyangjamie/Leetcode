/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

class Solution {
public:
    int numTrees(int n) {
        int sum = 0;
        if(n == 0 || n == 1)
            return 1;
        if((n % 2) == 0){
            for(int i = 1; i <= n/2; i++){
                if(n == 0 || n == 1)
                    return 1;
                sum += numTrees(i-1) * numTrees(n-i);
            }
            sum = sum * 2;
            return sum;
        }
        else{
            if(n > 2){
                for(int i = 1; i <= (int)(n/2); i++){
                  if(n == 0 || n == 1)
                      return 1;
                   sum += (numTrees(i-1) * numTrees(n-i));
                }
            }
            sum = sum * 2;
            int i = (int)(n/2+1);
            if(n == 0 || n == 1)
                return 1;
            sum += numTrees(i-1) * numTrees(n-i);
            return sum;
        }
        
    }
};
