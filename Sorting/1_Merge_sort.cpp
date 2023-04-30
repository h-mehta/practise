void display(int* input, int start, int end){
		int i=start;
		std::cout << "array : ";
		for(;i<=end; i++){
				std::cout << input[i] <<" ";
		}
		std::cout << std::endl;
}

void merge(int *input, int start, int mid, int end) {

	int wptr1 = start;
	int wptr2 = mid+1;
	int counter = 0;
	
	int *arr = new int[end-start+1];

	while(wptr1<=mid and wptr2<=end){
			if( input[wptr1] < input[wptr2] ) {
					arr[counter++] = input[wptr1++];
			}else {
					arr[counter++] = input[wptr2++];
			}
	}

    while(wptr1 <= mid) {
			arr[counter++] = input[wptr1++];
	}

	while(wptr2 <= end) {
			arr[counter++] = input[wptr2++];
	}

	counter = 0;
	for(int i =start; i<=end; i++){
			input[i] = arr[counter++];
	}
}

void mSort(int input[], int start, int end) {

	int si = start;
	int ei = end;
    if(si<ei){
			int mid = (si+ei)/2;
			mSort(input, si, mid);
			mSort(input, mid+1, ei);
			merge(input, si, mid, ei);
	}
}

void mergeSort(int input[], int size){
	// Write your code here
	mSort(input, 0, size-1);
}

