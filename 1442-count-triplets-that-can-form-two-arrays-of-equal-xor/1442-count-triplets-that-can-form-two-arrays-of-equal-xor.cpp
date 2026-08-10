class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        //triple te for using three loop
        for(int i=0;i<n;i++){
            int a=0;
            for(int j=i+1;j<n;j++){
                a^=arr[j-1];
                int b=0;
                for(int k=j;k<n;k++){
                    b^=arr[k];
                  
                    if(a==b) ans++;
                    
                }
            }
        }
        return ans;


    }
};