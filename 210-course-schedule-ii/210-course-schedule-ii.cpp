class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);
        for(int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        
        vector<int> ordering;
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()) {
            int precourse = q.front();
            q.pop();
            ordering.push_back(precourse);
            for(int &course : graph[precourse]) {
                if(--indegree[course] == 0)
                    q.push(course);
            }
        }
        
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] > 0)
                return {};
        }
        
        return ordering;
    }
};