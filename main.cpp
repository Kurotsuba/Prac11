/*
 * main.cpp
 *
 *  Created on: 2017Äê5ÔÂ8ÈÕ
 *      Author: kanneco98
 */
#include<set>
#include<vector>
#include<map>
#include<string>
#include <fstream>
#include<iostream>
#include<stack>
using namespace std;

int main(){
	set<string> wordSet;
	map<string,set<string>> wordSetMap;
	ifstream ifs("dictionary.txt");
	while(ifs){
		string tempStr;
		getline(ifs, tempStr);
		wordSet.insert(tempStr);
	}


	int suffixNumber;
	cout << "Please input the number of letters of suffix:";
	cin >> suffixNumber;

	set<string> suffixSet;

	for(string i : wordSet){
		if(suffixNumber < i.size()){
			string suffix = i.substr(i.size()-suffixNumber, suffixNumber);
			wordSetMap[suffix].insert(i);
			if(suffixSet.size() < 10){
				suffixSet.insert(suffix);
			}else{
				for(string i:suffixSet){
					if( wordSetMap[i].size() < wordSetMap[suffix].size()){
						suffixSet.erase(i);
						suffixSet.insert(suffix);
					}
				}
			}
		}
	}

	//print biggest suffix
	for(string i : suffixSet){
		cout << i << " : " << wordSetMap[i].size() << endl;
	}





	//query
	cout << "Please input the query suffix:";
	string querySuffix;
	cin >> querySuffix;
	if(querySuffix.size() != suffixNumber){
		cout << "Bad query suffix, the program will exit.";
		return 0;
	}

	stack<string> queryStack;
	for(string i : wordSetMap[querySuffix]){
		queryStack.push(i);
	}

	cout << queryStack.size() << " words of this suffix."<< endl;

	for(int i=0; i<queryStack.size(); i++){
		string outputStr;
		outputStr = queryStack.top();
		queryStack.pop();
		cout << outputStr << endl;
	}


	return 0;
}


