class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
          if (a.size() > b.size()) return findMedianSortedArrays(b, a);
    
    int n = a.size(), m = b.size();
    int low = 0, high = n;
    
    while (low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = (n + m + 1)/2 - cut1;
        
        int leftA = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
        int leftB = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
        int rightA = (cut1 == n) ? INT_MAX : a[cut1];
        int rightB = (cut2 == m) ? INT_MAX : b[cut2];
        
        if (leftA <= rightB && leftB <= rightA) {
            if ((n + m) % 2 == 0)
                return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
            else
                return max(leftA, leftB);
        }
        else if (leftA > rightB)
            high = cut1 - 1;
        else
            low = cut1 + 1;
    }
    return 0.0; 
    }
};