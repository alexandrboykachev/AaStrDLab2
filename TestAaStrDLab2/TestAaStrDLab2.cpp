#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include "..//AaStrDLab2/HaffmanAlgorithm.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestAaStrDLab2
{
	TEST_CLASS(TestAaStrDLab2)
	{
	public:      
		TEST_METHOD(different_chars) 
		{ 
			string str = "Hello";   
			string encoded;

			HaffmanTree* haffmanTree = new HaffmanTree(str);  
			Map<char, string>* hoffman = haffmanTree->get_codes_map();  
			List<haffman<char, int>>* list_symbol = haffmanTree->get_list_of_chars();
			for (size_t i = 0; i < str.size(); i++)    
				encoded += hoffman->find(str[i]);
			Assert::AreEqual(encoded, string("1001111100"));
		}   
		TEST_METHOD(same_chars) 
		{ 
			string str = "gty";  
			string encoded;

			HaffmanTree* haffmanTree = new HaffmanTree(str); 
			Map<char, string>* hoffman = haffmanTree->get_codes_map();   
			List<haffman<char, int>>* list_symbol = haffmanTree->get_list_of_chars(); 
			for (size_t i = 0; i < str.size(); i++)    
				encoded += hoffman->find(str[i]);
			Assert::AreEqual(encoded, string("000"));
		}   
		TEST_METHOD(text_decoding) 
		{ 
			string str = "I can't stop being lazy";  
			string encoded;

			HaffmanTree* haffmanTree = new HaffmanTree(str); 
			Map<char, string>* hoffman = haffmanTree->get_codes_map();  
			List<haffman<char, int>>* list_symbol = haffmanTree->get_list_of_chars(); 
			for (size_t i = 0; i < str.size(); i++)
				encoded += hoffman->find(str[i]);
			string decoded = haffmanTree->decode_string(encoded);
			Assert::AreEqual(str, decoded); 
		}

	};
}
