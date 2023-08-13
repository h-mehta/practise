
/*
 * Complete the 'pangramCheck' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

/*
 *
 * A sentence is known as a panagram because it contains every character of an alphabet
 *
 * Given a sentence, determine whether it is a panagram.
 *
 */


string pangramCheck(string s) {

        string all = "";
       
        for(char ch='a'; ch<='z'; ch++){
            all += ch;
        }
        for(int i=0; i<s.size(); i++){
            char ch = tolower(s[i]);
            
            all.erase(remove(all.begin(), all.end(), ch), all.end());
            if(all.size()==0){
                break;
            }
        }
        
        if(all.size()==0){
            return "pangram";
        }
        
        return "not pangram";
}


/*

Learnings:

1. How to remove characters from a string?

		my_string.erase(remove(my_string.begin(), my_string.end(), 'A'), my_string.end());
						|		|	    |
						-----------------	    '----> Character to remove
							|	
							'-----------> range - all occurences of character will be removed

2. tolower() - to convert character to lower case -.
						   |----> part of <bits/stdc++.h> header file.
   toupper() - to convert character to upper case -*

*/

