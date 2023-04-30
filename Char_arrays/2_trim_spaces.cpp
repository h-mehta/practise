

/*

Given an input string S that contains multiple words, you need to remove all the spaces present in the input string.

There can be multiple spaces present after any word.

Sample Input :
abc def g hi

Sample Output :
abcdefghi

*/

void trimSpaces(char input[]) {
    int wptr = 0;
    int current = 0;
    while(input[wptr]!='\0'){
            if(input[wptr]==' '){
                    wptr++;
            }
            else{
                    input[current++] = input[wptr++];
            }
    }
    input[current] = '\0';
	// alternatively, could have written:
	// input[current] = 0;
	// Because ASCII value of null character is 0
	// Also, note that we need to make sure that char array ends with null character or '\0'
}


