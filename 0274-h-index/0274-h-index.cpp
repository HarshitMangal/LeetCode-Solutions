class Solution {
public:
    int hIndex(vector<int>& arr) {
         int n=arr.size();
         sort(arr.rbegin(),arr.rend());
         int i=0;
         int count=0;
         while(i<n&&arr[i]>i){
            count++;
            i++;
         }

         return count;
    }
};