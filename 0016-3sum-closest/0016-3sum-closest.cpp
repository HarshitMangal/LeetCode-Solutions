class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
     int mindiff=INT_MAX;
     int res=0;
        for(int i=0;i<n-2;i++){
            int j=i+1;
            int k=n-1;
           
            while(j<k){
                int sum=arr[i]+arr[j]+arr[k];
                
                int diff=abs(target-sum);
               if(mindiff>diff){
                mindiff=diff;
                res=sum;
               }
              if(sum==target) return sum;
                else if(sum<target) j++;
                else k--;
            }
        }
        return res;
    }
};