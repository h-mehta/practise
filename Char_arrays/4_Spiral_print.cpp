
/*

Spiral Print

For a given two-dimensional integer array/list of size (N x M), print it in a spiral form. That is, you need to print in the order followed for every iteration:
a. First row(left to right)
b. Last column(top to bottom)
c. Last row(right to left)
d. First column(bottom to top)

Mind that every element will be printed only once.

Input:

1 -> 2  -> 3  -> 4
                 |
		 V
14-> 15 -> 16    5
^	   |	 |
|	   V	 V
13   20    17    6
^    ^	   |	 |
|    |	   V	 V
12   19 <- 18    7
^         	 |
|		 V
11 <-10 <- 9  <- 8


Output:
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

*/


void spiralPrint(int **input, int nRows, int nCols)
{
    //Write your code here
    int i = 0;
    int counter = 0;
    while(counter < nRows*nCols){
            
            for(int j = i; j< nCols-i; j++){
                        cout << input[i][j] << ' ';
                        counter++;
            }

            if(counter >= nRows*nCols){
                    break;
            }

            for(int j = i+1; j<= nRows-i-1; j++){
                        cout << input[j][nCols-i-1]<< ' ';
                        counter++;
            }

            if(counter >= nRows*nCols){
                    break;
            }


            for(int j = nCols-i-2; j>=i; j--){
                        cout << input[nRows-i-1][j]<< ' ';
                        counter++;
            }

            if(counter >= nRows*nCols){
                    break;
            }


            for(int j = nRows-i-2; j>i; j--){
                        cout << input[j][i]<< ' ';
                        counter++;
            }

            if(counter >= nRows*nCols){
                    break;
            }


            i++;
    }
}
