

/*

Remove Consecutive Duplicates
For a given string(str), remove all the consecutive duplicate characters.
Example:
Input String: "aaaa"
Expected Output: "a"

Input String: "aabbbcc"
Expected Output: "abc"

*/

void removeConsecutiveDuplicates(char input[]) {
    int i=1, current_pos = 1;
    char current_char = input[0];
    while(input[i]!=0){
            if(input[i] != current_char){
                    current_char = input[i];
                    input[current_pos++] = current_char;
            }
            i++;
    }
    input[current_pos] = 0;
}


