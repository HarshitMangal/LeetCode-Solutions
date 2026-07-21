class NumArray {
public:
    vector<int> segmentTree;
    int n;

    // Build Segment Tree
    void build(int i, int l, int r, vector<int>& nums) {

        if (l == r) {
            segmentTree[i] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * i + 1, l, mid, nums);
        build(2 * i + 2, mid + 1, r, nums);

        segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
    }

    // Point Update
    void Update(int index, int val, int i, int l, int r) {

        if (l == r) {
            segmentTree[i] = val;
            return;
        }

        int mid = l + (r - l) / 2;

        if (index <= mid)
            Update(index, val, 2 * i + 1, l, mid);
        else
            Update(index, val, 2 * i + 2, mid + 1, r);

        segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
    }

    // Range Query
    int Query(int left, int right, int i, int l, int r) {

        // No Overlap
        if (l > right || r < left)
            return 0;

        // Complete Overlap
        if (left <= l && r <= right)
            return segmentTree[i];

        // Partial Overlap
        int mid = l + (r - l) / 2;

        return Query(left, right, 2 * i + 1, l, mid) +
               Query(left, right, 2 * i + 2, mid + 1, r);
    }

    NumArray(vector<int>& nums) {

        n = nums.size();

        segmentTree.resize(4 * n);

        build(0, 0, n - 1, nums);
    }

    void update(int index, int val) {

        Update(index, val, 0, 0, n - 1);
    }

    int sumRange(int left, int right) {

        return Query(left, right, 0, 0, n - 1);
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