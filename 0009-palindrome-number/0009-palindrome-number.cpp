class Solution {
public:
    bool isPalindrome(int x) {
        string temp=to_string(x);
        string temp1=temp;
        reverse(temp.begin(),temp.end());
        if(temp==temp1) return true;
        return false;
    }
};