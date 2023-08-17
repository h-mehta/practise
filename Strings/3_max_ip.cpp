#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

int main() {

	char file[] = "logs.txt";

	ifstream file1(file);

	if(file.open()){

		string line;

		getline(file1, line);

		while(line[0]==0){
			getline(file1, line);
		}

		int num_logs = atoi(line.c_str());

		unordered_map<string, int> dict;

		for(int i=0 ; i<num_logs; i++){
			getline( file1, line);
			c_line = line.c_str();
			char temp[] = strtok( c_line, " ");
			if(dict.count( to_string(temp) ) > 0){
				dict[to_string(temp) ] += 1;
			} else {
				dict[to_string(temp) ] = 1;
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

	}else {
		cout << "\n Could not open file";
		exit(0);
	}

	return 0;
}


