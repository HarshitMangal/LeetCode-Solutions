class BrowserHistory {
public:
   stack<string>backward;
   stack<string>Forward;
   string curr;
    BrowserHistory(string homepage) {
        curr=homepage;
        
    }
    
    void visit(string url) {
        backward.push(curr);
        curr=url;
        while(!Forward.empty()){
              Forward.pop();
        }
        


    }
    
    string back(int steps) {
        while(steps>0&&!backward.empty()){
         Forward.push(curr);
         curr=backward.top();
         backward.pop();
         steps--;
        }
         return curr;
    }
    
    string forward(int steps) {
        while(steps>0&&!Forward.empty()){
            backward.push(curr);
            curr=Forward.top();
            Forward.pop();
            steps--;
        }
        return curr;
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */