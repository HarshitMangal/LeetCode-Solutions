class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });
        int n=courses.size();
        int ans=0;
        // using max heap se karnge
        priority_queue<int>pq;
        int time=0;
        for(auto it:courses){
            int duration=it[0];
            int deadline=it[1];
            time+=duration;
            pq.push(duration);
            if(time>deadline){
                time-=pq.top();
                pq.pop();
            }

        }
        return pq.size();

        
    }
};