
/*

Balanced Brackets - to check if expression is well formed.

*/


using namespace std;

bool balancedBrackets(string str) {
  // Write your code here.
  vector<char> st1;
  bool conflict = false;
  cout << " String : "<<str<<endl;
  for(int i=0; i<str.length(); i++){
      char ch = str[i];
      if(ch=='(' or ch=='[' or ch=='{' ){
          cout << " Pushed : "<< ch <<endl;
          st1.push_back(ch);
      }
      else if( ch==')' or ch==']' or ch=='}'  ) 
      {
          if(st1.empty()){
              // faulty string - can't pop if stack empty
              return false;
          }
          char temp = st1.back();
          cout << " Poped : "<< temp <<endl;
          st1.pop_back();
          if(ch==')')
          {
              if(temp=='('){
                  continue;  
              }else{
                  conflict = true;
                  break;
              }
          }
          else if(ch==']')
          {
              if(temp=='['){
                  continue;  
              }else{
                  conflict = true;
                  break;
              }            
          }
          else if(ch=='}'){
              if(temp=='{'){
                  continue;  
              }else{
                  conflict = true;
                  break;
              }            
          }
          else{
                  conflict = true;
                  break;
          }
      }
      else{
          continue;
      }
      
  }
  //cout << "Exited from loop";
  if( conflict or !st1.empty() ){
    return false;
  }
  else{
    return true;
  }
}



