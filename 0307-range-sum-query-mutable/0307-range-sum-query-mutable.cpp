class NumArray {
public:
     int n;
      vector<int>segmentTree;
    void build(vector<int>&nums,int l,int r,int index){
        int n=nums.size();
        if(l==r){
            segmentTree[index]=nums[l];
            return;
        }
        int mid=l+(r-l)/2;
        build(nums,l,mid,2*index+1);
        build(nums,mid+1,r,2*index+2);
        segmentTree[index]=segmentTree[2*index+1]+segmentTree[2*index+2];    
}
    void Update(int l,int r,int index,int val,int i){
        if(l==r){
            segmentTree[i]=val;
            return;
        }
        int mid=l+(r-l)/2;
        if(index<=mid){
            Update(l,mid,index,val,2*i+1);
        }
        else{
            Update(mid+1,r,index,val,2*i+2);
        }
        segmentTree[i]=segmentTree[2*i+1]+segmentTree[2*i+2];
    }
    int Query(int l,int r,int left,int right,int idx){
        //no overlap
        if(l>right||r<left) return 0;
        
        int mid=l+(r-l)/2;
        //compleete overlap
        if(l>=left&&r<=right) return segmentTree[idx];
        //partial overlap
            return Query(l,mid,left,right,2*idx+1)+Query(mid+1,r,left,right,2*idx+2);
    }
    NumArray(vector<int>& nums) {
         n=nums.size();
        segmentTree.resize(4*n);
        build(nums,0,n-1,0);
        
    }
    
    void update(int index, int val) {
        Update(0,n-1,index,val,0);
    }
    
    int sumRange(int left, int right) {
         return Query(0,n-1,left,right,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */