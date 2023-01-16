/*
Qns. Implement RLE
Some rules: 
the run "AAAAAAAAAAAA" (12 A) should be split into 9A3A
i.e. runs of more than 10 should be split up.
 
*/

using namespace std;

string runLengthEncoding(string str) {
  // Write your code here.
  string ans;

  int len = str.length(), counter = 0;

  int run_len = 0;

  // remember str[i] returns a character
  char curr_ch = str[0];
  
  while(counter<len){
    if(curr_ch == str[counter]){
        if(run_len < 10){
          run_len++;
        }else{
          ans += '9';
          ans += curr_ch;
          run_len = 2;
        }
    }else{
      cout << run_len <<"\t"<< curr_ch<<endl;
      //ans += run_len;
      ans += to_string(run_len);
      ans += curr_ch;
      cout << ans <<endl;
      curr_ch = str[counter];
      run_len = 1;
    }
    counter++;
  }
  if(run_len==10){
    //ans += "9"+to_string(curr_ch)+"1";
    ans += "9";
    ans += curr_ch;
    ans += "1";
  }else{
    ans += to_string(run_len);
  }
  ans += curr_ch;
  return ans;
}


/*
Learnings :
1. string1[index] returns a character
2. use to_string() to convert anything to string
3. to_string('a') will be "97" and NOT "a"
4. string1 += 'c'  ---> appends character to string ----> + is overloaded for (string,character) case only
5. Something like string1 += 'c' + string2 ----> ERROR : + NOT overloaded for (char, string) case
*/
