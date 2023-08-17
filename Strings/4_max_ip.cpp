#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

int main() {



                string line;

                getline(cin, line);

                while(line[0]==0){
                        getline(cin, line);
                }

                int num_logs = atoi(line.c_str());

                unordered_map<string, int> dict;

                for(int i=0 ; i<num_logs; i++){
                        getline( cin, line);
                        char* c_line = new char[line.length() + 5];
                        strcpy(c_line, line.c_str());
                        char* temp = strtok( c_line, " ");
                        string st1="";
                        char ch=temp[0];
                    	int j = 1;
                        while(ch!=0){
                        		st1 = st1 + ch;
                        		ch = temp[j];
                        		j++;
                        }
                     
                        
                        if(dict.count( st1 ) > 0){
                                dict[ st1 ] += 1;
                        } else {
                                dict[ st1 ] = 1;
                        }
                }

                unordered_map<string, int> :: iterator it = dict.begin();
                int max_occur = 0;
                string max_ip = "";
                while(it != dict.end() ){
                        if( it->second > max_occur ){
                                max_occur = it->second;
                                max_ip = it->first;
                        }
                        it++;
                }

                cout << "\n Max occuring IP : " << max_ip << endl;
                
                return 0;
}                

