class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
           vector<int>ans;
                vector<bool>prime(right+1,true);
                prime[0]=false;
                prime[1]=false;
                for(int i=2;i*i<=right;i++){
                    if(prime[i]){
                        for(int j=i*i;j<=right;j+=i){
                            prime[j]=false;
                        }
                    }
                }
                int mindiff=INT_MAX;
                int a=-1;
                int b=-1;
                int pre=-1;
                for(int i=left;i<=right;i++){
                    if(prime[i]){
                        if(pre!=-1){
                            if(i-pre<mindiff){
                                mindiff=i-pre;
                                a=pre;
                                b=i;
                            }
                        }
                        pre=i;
                    }
                }
                return {a,b};

    }
};