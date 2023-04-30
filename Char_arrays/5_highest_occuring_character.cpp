
/*

Highest Occuring character

For a given a string(str), find and return the highest occurring character.
Example:
Input String: "abcdeapapqarr"
Expected Output: 'a'
Since 'a' has appeared four times in the string which happens to be the highest frequency character, the answer would be 'a'.
If there are two characters in the input string with the same frequency, return the character which comes first.

*/


#include <map>

char highestOccurringChar(char input[]) {
    map<char, int> dict;
    for(char c='a'; c<='z'; c++){
            dict[c] = 0;
    }

    int i=0;
    while(input[i]!=0){
            dict[ input[i++] ]++;
    }

    int max_count = 0;
    char max_char;
    for(char c='a'; c<='z'; c++){
            if(dict[c] > max_count){
                    max_count = dict[c];
                    max_char = c;
            }
    }
    return max_char;
}


