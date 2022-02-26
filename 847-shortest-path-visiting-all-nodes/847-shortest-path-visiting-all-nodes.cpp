class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n==1) return 0; // if there is only one element than the shorted path to itself is 0
        int final_mask= (1<<n)-1; // if n=3 the max we can go is 111 or 7
        queue<pair<int,int>> q; // pair<element,mask>
         vector<vector<bool>> seen(n,vector<bool>(final_mask+1,false));
        for(int i=0;i<n;i++){
		//store <element,mask> we are storing all of them because the initial state is not fixed and we are just interested in shortest path covering all nodes
            q.push({i,(1<<i)}); 
            seen[i][1<<i]=true; // as we have visited this node(inserted in queue)
        }
        int ans=0;
		//traditional BFS
        while(!q.empty()){
            int sz=q.size();
            ans++;
            while(sz--){
                pair<int,int> pq=q.front();
                q.pop();
                int element=pq.first;
                int curr_mask=pq.second;
                for(int& child:graph[element]){
				//creating a new mask using new element and old mask, ex- if we have visited 1st and 2nd and now its our third element then 011 | 100=111 
                     int new_mask=(1<<child) | curr_mask;  
                    if(new_mask==final_mask) return ans; 
                    if(!seen[child][new_mask]){ //important , this way we are stopping infinite loops
                        q.push({child,new_mask});
                       seen[child][new_mask]=true;
                    }
                }     
            } 
        }     return -1;
    }
};