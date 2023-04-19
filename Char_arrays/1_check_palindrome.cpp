

// Program to check palindrome

bool checkPalindrome(char str[]) {
    int start = 0;
    int end = 0;

    char c = str[0];
    while(c!='\0'){
            end++;
            c= str[end];
    }
    end--;
    
    while(start<end){
            if(str[start] != str[end]){
                    return false;
            }
            start++;
            end--;
    }
    return true;
}


