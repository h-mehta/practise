

// Code for binary search algorithm

int binarySearch(int *input, int n, int val)
{
    int start = 0;
    int end = n-1;
    int mid = (start+end)/2;
    while(start<=end){
            if( input[mid] == val ){
                    return mid;
            }
            else if( input[mid] > val ){
                    end = mid-1;
            }else{
                    start = mid+1;
            }
            mid = (start+end)/2;
    }
    return -1;
}

