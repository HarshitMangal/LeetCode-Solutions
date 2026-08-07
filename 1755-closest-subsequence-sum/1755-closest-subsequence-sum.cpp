class Solution {
public:
//its very famoyus mitm template yar

    int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size();
        int n1=n/2;
        int n2=n-n/2;
        //inko half me vatyke add karenge yar
        vector<int>sumA(1<<n1);
        //ab subset dlanege yar isne
        for(int mask=0;mask<1<<n1;mask++){
            int s=0;
            for(int i=0;i<n1;i++){
                //set bit dekhjenge uar
                if(mask&(1<<i)){
                    s+=nums[i];
                }

            }
            sumA[mask]=s; 
        }
        vector<int>sumB(1<<n2);
           for(int mask=0;mask<1<<n2;mask++){
            int s=0;
            for(int i=0;i<n2;i++){
                //set bit dekhjenge uar
                if(mask&(1<<i)){
                    s+=nums[n1+i];
                }

            }
            sumB[mask]=s; 
        }
        //ab hum sumsof bko sort karte he yar
        sort(sumB.begin(),sumB.end());
        //abs (sum-goal ) ko minimize karna heyar
        int minval=INT_MAX;
        for(auto sum1:sumA){
            int need=goal-sum1;
            int low=lower_bound(sumB.begin(),sumB.end(),need)-sumB.begin();
            if(low<sumB.size()){
                int sum2=sumB[low];
                int total=sum1+sum2;
                minval=min(minval,abs(goal-total));
            }
            //ab low -1 vala case bhi check kerebge yar
            if(low>0){
                int sum2=sumB[low-1];
                int total=sum1+sum2;
                minval=min(minval,abs(goal-total));
            }
        }
        return minval;

        
    }
};