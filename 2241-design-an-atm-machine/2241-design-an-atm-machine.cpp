class ATM {
public:
   vector<long long>cnt;
   vector<int>note;
  
    ATM() {
        cnt=vector<long long>(5,0);
        note={20,50,100,200,500};

        
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i=0;i<5;i++){
            cnt[i]+=banknotesCount[i];
        }
        
    }
    
    vector<int> withdraw(int amount) {
        vector<int>ans(5,0);
        //reverse lenege bada note utana he
        long long rem=amount;
        for(int i=4;i>=0;i--){
          long long take=min(cnt[i],rem/note[i]);
          ans[i]=take;
          rem-=take*note[i];

        }
        if(rem!=0){
            return {-1};
        }
        for(int i=0;i<5;i++){
            cnt[i]-=ans[i];
        }
        return ans;
        
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */