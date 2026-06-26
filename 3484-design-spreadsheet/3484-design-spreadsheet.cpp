class Spreadsheet {
public:

   unordered_map<string,int> mp;
    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
          mp[cell]=value;
    }
    
    int get(string &s){
        if(isdigit(s[0])){
            return stoi(s);
        }
         if(mp.count(s))
        return mp[s];

        return 0;
    }
    void resetCell(string cell) {
            mp.erase(cell);
    }
    
    int getValue(string formula) {
         string left = "";
            string right = "";

            int i = 1;

            // Left operand
            while(formula[i] != '+')
            {
                left += formula[i];
                i++;
            }

            i++; // '+' skip

            // Right operand
            while(i < formula.size())
            {
                right += formula[i];
                i++;
            }
            return get(left)+get(right);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */