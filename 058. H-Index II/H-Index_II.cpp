/*
Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?

Hint:

Expected runtime complexity is in O(log n) and the input is sorted.
*/

/*
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        int index = 0;
        bool iflarge1st = false;
        for(int k = 0; k<size; k++){
            if(citations[k] > size - k && iflarge1st == false){
                index = size - k;
                iflarge1st = true;
            }
            if(citations[k] == size - k)
                index = size - k;
        }
        return index;
    }
};
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty()) return 0;
        if(citations[citations.size()-1] == 0) return 0;
        int size = citations.size();
        int index = 1;
        int mid = (size-1)/2;
        int front = 0;
        int end = size-1;
        while(front <= end){
            if(citations[mid] == size - (mid)){
                index = size - (mid);
                return index;
            }
            if(citations[mid] > size - (mid)){
                end = mid-1;
                index = size - (mid);
            }
            if(citations[mid] < size - (mid)){
                front = mid+1;
                //index = citations[mid-1];
            }
            mid = (end - front) / 2 + front;
        }
        return index;
    }
};
