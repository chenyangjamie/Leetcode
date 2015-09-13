// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int mid = n/2;
        int start = 1;
        int end = n;
        while(start != end){
            if(isBadVersion(mid))
                end = mid;
            else start = mid+1;
            mid = (end-start)/2+start;
        }
        return start;
    }
};
