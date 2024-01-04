#include <iostream>
#include <climits>

using namespace std;

int second_largest(int *input, int n){
	int largest = INT_MIN;
	int s_largest = INT_MIN;

	for(int i=0; i<n; i++){
		if( input[i] > largest ){
			s_largest = largest;
			largest = input[i];
		}
	}
	return s_largest;
}

int main() {

	int n;
	cin >> n;

	int* input = new int[n];

	for(int i=0; i<n; i++) {
		cin >> input[i];
	}

	cout << "\n Answer : " <<second_largest(input, n);
}

