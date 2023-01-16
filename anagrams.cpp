/*
GROUP ANAGRAMS 
WAP that takes in an array of strings and groups anagrams together.
Anagrams are strings made up of exactly the same letters, where the order does not matter. For example, "cinema" and "iceman" are anagrams; similarly "foo" and "ofo" are anagrams.
Input :
words = ["yo","flop","olfp","oy","tac"]
Output:
[["yo","oy"],["flop","olfp"],["tac"]]
*/

#include <vector>
#include<string.h>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> words) {
    // Write your code here.
    //vector<map<char, int>> global_map;
    vector<vector<string>> ans;

    for(int i=0; i < words.size(); i++){
        string s1 = words[i];
        string temp = s1;
        // SORT can be used to sort a string
        // However note that I created a copy of the string I wanted to sort
        // this is because sort does not return the sorted string but infact sorts it in place
        // which means you will lose the original string
        // if the original string is required, create a copy
        sort(temp.begin(), temp.end());
        bool match_found = false;
        if(ans.empty()){
            vector<string> temp;
            temp.push_back(s1);
            ans.push_back(temp);
        }else{
            for(int j=0; j<ans.size(); j++){
                // checking if anagram group exists
                vector<string> v1 = ans[j];
                string str1 = v1[0];
                sort(str1.begin(), str1.end());

                //comparing strings
                if( temp == str1 ){
                    // Note strings in C++ can be compared like integers
                    // strcmp works only on char arrays
                  
                    // strings equal
                    match_found = true;
                    ans[j].push_back(s1);
                    break;
                }
            }
            // If no match found
            if( ! match_found ){
                vector<string> temp;
                temp.push_back(s1);
                ans.push_back(temp);
            }
        }
    }
    return ans;
}
