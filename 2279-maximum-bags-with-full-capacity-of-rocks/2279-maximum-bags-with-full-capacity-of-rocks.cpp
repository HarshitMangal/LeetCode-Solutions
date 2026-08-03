class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=capacity.size();
        //using diff sorting yar
        vector<int>diff;
        for(int i=0;i<n;i++){
            diff.push_back(capacity[i]-rocks[i]);
        }
        //ab hum sort karenge
        sort(diff.begin(),diff.end());
        int count=0;
        for(int i=0;i<n;i++){
            if(diff[i]==0){
                count++;
            }
            else{
                if(additionalRocks>=diff[i]){
                    additionalRocks-=diff[i];
                    count++;
                }
                else{
                    break;

                }
            }
        }
        return count;
    }
};