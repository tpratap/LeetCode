/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        queue<int> q;
        
        q.push(id);
        unordered_set<int> visited;
        int sum = 0;
        
        unordered_map<int, Employee*> mp;
        
        for(int i = 0; i < employees.size(); i++) {
            mp[employees[i]->id] = employees[i];
        }
        
        visited.insert(id);
        
        while(!q.empty()) {
            int i = q.front();
            q.pop();
            
            sum += mp[i]->importance;
            
            for(int empid : mp[i]->subordinates) {
                if(visited.find(empid) == visited.end()) {
                    q.push(empid);
                    visited.insert(empid);
                }
            }
        }
        return sum;
    }
};