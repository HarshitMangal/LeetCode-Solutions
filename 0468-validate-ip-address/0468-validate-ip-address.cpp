class Solution {
public:

    bool isIPv4(string &s) {
        if(s.empty()) return false;

        int n = s.length();
        int count = 0;

        for(int i = 0; i < n; i++) {

            int num = 0;
            string temp = "";

            while(i < n && s[i] != '.') {

                if(!isdigit(s[i]))
                    return false;

                temp += s[i];

                if(temp.length() > 3)
                    return false;

                num = num * 10 + (s[i] - '0');

                i++;
            }

            if(i < n - 1 && s[i] == '.' && s[i + 1] == '.')
                return false;

            if(temp.length() == 0)
                return false;

            if(temp.length() > 1 && temp[0] == '0')
                return false;

            if(num < 0 || num > 255)
                return false;

            count++;
        }

        if(s[n - 1] == '.')
            return false;

        return count == 4;
    }

    bool isipv6(string &s) {
        if(s.empty()) return false;

        int n = s.length();
        int count = 0;

        for(int i = 0; i < n; i++) {

            string temp = "";

            while(i < n && s[i] != ':') {

                if(!((s[i] >= '0' && s[i] <= '9') ||
                     (s[i] >= 'a' && s[i] <= 'f') ||
                     (s[i] >= 'A' && s[i] <= 'F')))
                    return false;

                temp += s[i];
                i++;
            }

            if(i < n - 1 && s[i] == ':' && s[i + 1] == ':')
                return false;

            if(temp.length() == 0 || temp.length() > 4)
                return false;

            count++;
        }

        if(s[n - 1] == ':')
            return false;

        return count == 8;
    }

    string validIPAddress(string queryIP) {

        if(isIPv4(queryIP))
            return "IPv4";

        if(isipv6(queryIP))
            return "IPv6";

        return "Neither";
    }
};