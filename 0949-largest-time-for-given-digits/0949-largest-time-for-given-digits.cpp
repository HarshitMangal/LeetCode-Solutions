class Solution {
public:
     string ans="";
     int best=-1;
     void solve(vector<int>&arr,int idx){
        if(idx==4){
            int hour=arr[0]*10+arr[1];
            int minut=arr[2]*10+arr[3];
            if(hour<24&&minut<60){
                  int total=hour*60+minut;
            if(total>best){
                best=total;
                ans="";
                if(hour<10) ans+='0';
                ans+=to_string(hour);
                ans+=':';
                if(minut<10) ans+='0';
                 ans+=to_string(minut);
            }
            }
            return;
        }
        for(int i=idx;i<4;i++){
            swap(arr[idx],arr[i]);
            solve(arr,idx+1);
            swap(arr[idx],arr[i]);
        }
     }
    string largestTimeFromDigits(vector<int>& arr) {
        int n=arr.size();
        solve(arr,0);
        return ans;

    }
};