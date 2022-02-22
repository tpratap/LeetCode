class Solution {
public:
    /*
        Topological Sorting: Linear ordering of vertices such thar if there is an
        edge u->v then u appears before v in that ordering.
    */
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);
        for(int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()) {
            int precourse = q.front();
            q.pop();
            for(int &course : graph[precourse]) {
                if(--indegree[course] == 0)
                    q.push(course);
            }
        }
        
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] > 0)
                return false;
        }
        
        return true;
    }
};