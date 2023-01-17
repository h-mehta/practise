/*

Minimum Characters for Words

WAP that takes in an array of words and returns the smallest array of 
characters needed to form all the of the words. The characters don't need to be in any particular order.

For example, the characters ["y", "r","o""u"] are needed to form the words ["yor", "you", "or", "yo"].

*/

#include <vector>
using namespace std;

vector<char> minimumCharactersForWords(vector<string> words) {
    // Write your code here.
    vector<char> ans;
    map<char, int> global_map;
  
    while(!words.empty()){
        string temp = words.back();
        map<char, int> local_map;
        for(int i=0; i<temp.length(); i++){

            if( local_map.find( temp[i] ) == local_map.end() ){
                // key does not exist in local map
                if( global_map.find( temp[i] ) == global_map.end() ){
                    // key DNE in global map
                    local_map[ temp[i] ] = 1;
                    global_map[ temp[i] ] = 1;
                    ans.push_back( temp[i] );
                }
                else{
                    // key exists in global map but DNE in local map
                    local_map[ temp[i] ] = 1;
                }
            }
            else{
                // key exists in local map
                // it must exist in global map
                // just checking the count
                if( local_map[ temp[i] ] == global_map[ temp[i] ] ){
                    // this is repeated character
                    // need to increase count 
                    local_map[ temp[i] ]++;
                    global_map[ temp[i] ]++;
                    ans.push_back( temp[i] );
                }
                else{
                    // local_map occurences would be less so update
                    local_map[ temp[i] ]++;
                }
            }
            /*
            if( count( ans.begin(), ans.end(), temp[i] ) == 0 )
            {
                ans.push_back( temp[i] );
            } */
        }
        words.pop_back();
    }
    return ans;
}



/*

Learnings:

1. How to find a key in a map :

	if( map.find( key ) == map.end() )
		// Key not found

2. How to find a key in a vector :

	if( count( vector.begin(), vector.end(), key ) == 0 )
		// key DNE in the vector

To check if a particular key in the map exists, use the count member function in one of the following ways:

m.count(key) > 0
m.count(key) == 1
m.count(key) != 0
The documentation for map::find says: "Another member function, map::count, can be used to just check whether a particular key exists."

The documentation for map::count says: "Because all elements in a map container are unique, the function can only return 1 (if the element is found) or zero (otherwise)."

To retrieve a value from the map via a key that you know to exist, use map::at:

value = m.at(key)

Refer:

https://stackoverflow.com/questions/1939953/how-to-find-if-a-given-key-exists-in-a-c-stdmap 


*/
