#include<iostream>
#include"Map.h"
#include<string>
#include"HaffmanAlgorithm.h"

using namespace std;

int main() {

	string str;
	string encoded;


	cout << "input string: ";

	getline(cin, str);

	HaffmanTree* haffmanTree = new HaffmanTree(str);

	Map<char, string>* haffman_codes_map = haffmanTree->get_codes_map();

	List<haffman<char, int>>* list_symbol = haffmanTree->get_list_of_chars();

	cout << "Code table:" << endl;

	cout << "Symbol <---> Code" << endl;

	for (int i = 0; i < list_symbol->get_size(); i++)

		cout << "   " << list_symbol->at(i).symbol << "   <---> " 
		     << haffman_codes_map->find(list_symbol->at(i).symbol) 
		     << " <---> occurrences in a string: " << list_symbol->at(i).num_of_entry << endl;

	cout << "Old line: " << str << endl;

	for (int i = 0; i < str.size(); i++)

		encoded += haffman_codes_map->find(str[i]);

	cout << "New line: " << encoded << endl;

	string decoded = haffmanTree->decode_string(encoded);

	cout << "Size of the source string = " << decoded.size() * 8 << " bit" << endl;

	cout << "Size of the encoded string = " << encoded.size() << " bit" << endl;

	delete haffmanTree;

	return 0;

}