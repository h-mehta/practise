
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main(){
	char file[] = "input_file.txt";
	
	ifstream file1(file);
	
	if(file1.is_open())
	{
		
		string line;
		
		while( line[0]=='\0' ){

			// this loop skips empty lines
			// IMPORTANT
			// Note : if line is empty ---> we do not check for line[0]=='\n'
			//	  INFACT we are checking for line[0]=='\0'	

			getline(file1, line);
		}		
		
		/* Input file:
			2
			25 75
			1000 24
		*/
		
		// Now, line contains succeding number of lines I want to add

		// atoi() function converts char array to integer
		// Example, char num[] = "25"
		//  	    int number = atoi( num  )
		// 	    cout << number ; 	
		// OUTPUT : 25

		// But note that it can only convert char arrays and not strings to integers
		// getline stores the output as a string in it's second argument
		// thus the second argument, i.e. "line" in this scenario, is a string
		// so we need to convert string "line" to char array
		// string is converted to char array using c_str() function
		// Usage : string1.c_str() this returns a char array
   			
		int numeric_rows = atoi(line.c_str());

		// now we know next number of numeric_rows need to be added
		// to extract 2 numbers from a single string line we will use "strtok"
		
		while( numeric_rows > 0 ){
			
			getline( file1, line );

			stringstream ss;

			ss.str(line);

			int num1, num2, result;
			
			ss >> num1 >> num2 ;

			result = num1 + num2;
			
			cout << "Result of Line : "<<result<<endl;
			numeric_rows--;
		}
		
	}
	else
	{
		
		cout << "\n Could not open file";
		exit(0);
		
	}
	
	return 0;
}

