class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations);
        int size = citations.size();
        for(int k = 0; k<citations.size(); k++){
            if(k+1 > citations[k])
                return k;
        }
        return size;
    }
    void sort(vector<int>& array){
        for(int i = 0; i<array.size(); i++){
            for(int j = i+1; j<array.size(); j++){
                if(array[i] < array[j]){
                    int temp = array[j];
                    array[j] = array[i];
                    array[i] = temp;
                }
            }
        }
    }
};
