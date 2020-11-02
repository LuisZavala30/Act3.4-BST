// =================================================================
// File: main.cpp
// Author: Luis Angel Zavala Robles
// Date: 31/Oct/2020
//
// Description: Reads "bitacora.txt" file and store the ip access into BST
//              to determine the five most accessed IPs.
// ================================================================
#include <iostream>
#include <fstream>
#include <vector>
#include "BST.h"
#include <string.h> 

using namespace std; 

#define filename "bitacora.txt"

vector<string> split(const string &s, char delimiter);

// Reads "bitacora.txt" file and add items into Binary Search Tree.
int main(int argc, char* arg[]){
	BST<string> bst;
    vector<string> aux;
    ifstream input;
    ofstream output;
    string line;
  
    input.open(filename);
	if (input.is_open()) {
		while (getline(input, line)) {
			aux = split(line, ' ');
			bst.add(aux[3]);
		}
	}
	cout << bst.mostAccessed()<<endl;;
}


// Function to split the items of "bitacora.txt" file.
vector<string> split(const string &s, char delimiter)
{
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   while ( getline(tokenStream, token, delimiter) ) {
      tokens.push_back(token);
   }
   return tokens;
}

