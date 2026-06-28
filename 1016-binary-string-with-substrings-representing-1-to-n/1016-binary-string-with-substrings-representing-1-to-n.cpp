class Solution {
public:
    string bin(int n){
        string temp = "";

        while(n){
            temp += (n % 2) + '0';
            n /= 2;
        }

        reverse(temp.begin(), temp.end());
        return temp;
    }

    bool queryString(string s, int n) {

        for(int num = 1; num <= n; num++){

            string temp = bin(num);

            if(s.find(temp) == string::npos)
                return false;
        }

        return true;
    }
};