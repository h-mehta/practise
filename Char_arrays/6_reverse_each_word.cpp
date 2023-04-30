
/*

Reverse Each Word
Aadil has been provided with a sentence in the form of a string as a function parameter. The task is to implement a function so as to print the sentence such that each word in the sentence is reversed.

Example:

Input Sentence: "Hello, I am Aadil!"

The expected output will print, ",olleH I ma !lidaA".

*/



void reverseEachWord(char input[]) {
    int i=0, start_word=0;
    bool flag = false;
    while(input[i]!='\0' or flag){
            if(input[i]==' ' or flag){
                    int end_word = i-1;
                    while(end_word>start_word){
                            char temp = input[end_word];
                            input[end_word--] = input[start_word];
                            input[start_word++] = temp;
                    }
                    start_word = i+1;
            }
            i++;
            if(flag){
                break;
            }
            if(input[i]=='\0'){
                    flag = true;
            }
    }
}

