class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        int ans = 0;
		
		for(auto &it : words)
		{
			int i = 0;         
			while( it[i] == pref[i]){    
            count++;
            i++;
            
            if(i==pref.size()){       
                break;                  
            }
        }
        if(count == pref.size()){    
            ans++;                   
        }
        count=0;      
      }

return ans;
    }
};