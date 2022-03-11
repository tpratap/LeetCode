class Solution {
public:
    int lengthOfLIS( vector<int> &nums ) {
        /*
        Patient Sort Algo
         [10,9,2,5,3,7,101,18]
         col1: 10 -> 9 -> 2 //Go until upper value is present in col, and update column 
         col2: 5 -> 3
         col3: 7
         col4: 101 -> 18
         
         In TreeSet, we can understand as follows:
         Got 10, make a node,  
         Set = {10}
         got 9 tree already have a node greater than 9 it can't contribute in lis, so update 10 to 9,  Set = {9}
         got 2, agin lesser value so update tree 9 will also not contribue
         Set = {2}
         got 5 , Now got greater value it can contribute to lis add it
         Set = {2, 5}
         got 3, Now a smaller value so update because we can get a new lis
         and so on
        */
        set<int> lis;
		for ( auto num : nums ) {
			
            if(lis.count( num )) continue; //If duplicates do nothing
            
			lis.insert( num ); // If new number is found insert it
			auto it = lis.upper_bound( num ); // check if any number greater than current number is present
			if( it != lis.end() ) //If present then remove it
                lis.erase( it );
		}
        for(auto &x: lis)
            cout<<x<<" ";
        cout<<"\n";
		return lis.size(); //return the length of tree
    }
};