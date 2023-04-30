/*

Reverse the given string word wise. That is, the last word in given string should come at 1st place, last second word at 2nd place and so on. Individual words should remain as it is.

Sample Input:
Always indent your code
Sample Output:
code your indent Always

*/

void reverseStringWordWise(char input[]) {
    // Write your code here

    // first let's reverse the whole string

    int i = 0, size = 0;
    while(input[size] != 0){
            size++;
    }
   //std::cout << size;
   size--;

    while(i<size){
            char temp = input[i];
            input[i] = input[size];
            input[size] = temp;
            i++;
            size--;
            //std::cout << i;
    }

    // now let's reverese each word to get word wise reversed line
    
    i = 0;
    int word_start = 0;
    bool flag = false;
    while(flag or input[i] != '\0'){
            // input[i]!='\0' ensures that loop is run for all characters
            // but we need to run the one last time when '\0' is encountred to reverse the last word - hence flag is used
            if(flag or input[i] == ' ' ){
                    // reverse the word starting from word_start to i-1
                    int word_end = i-1;
                    while(word_end>word_start){
                            int temp = input[word_start];
                            input[word_start++] = input[word_end];
                            input[word_end--] = temp;
                    }
                    word_start = i+1;
            }
            i++;
            if(flag){
                    // reversed the last word
                    break;
            }

            if(input[i] == '\0' ){
                    // reached the end? flag = true
                    // last word needs to be reversed
                    flag = true;
            }
    }
    
}


