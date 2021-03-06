#ifndef TRIEDICTIONARY_H_
#define TRIEDICTIONARY_H_

#include <iostream>
#include <string>
#include <vector>

class TrieDictionary
{
	private:
		
		static const int ALPHABET_SIZE = 26;
		static const int LOWER_CASE = 'a';
		static const int UPPER_CASE = 'A';
		
		/**Keep track of the current case*/
		int currentCase;
	
		struct TrieNode
		{
			TrieNode* parent;
			TrieNode* children[ALPHABET_SIZE];
			int occurrences;					
		};
		
		/**Keeps track of the root of the Trie tree*/
		TrieNode* root;
		
		/**Used to keep track of the characters in each word when displaying*/
		std::vector<char> charsInWord;
		
		/**
		* Keeps track of all the memory allocations for a quicker way to release memory
		* when the object is destroyed
		* */
		std::vector<TrieNode*> mallocs;
		
		/**
		* Add a word to the dictionary
		*
		* @param currentNode the currentNode in traversing the Trie tree
		* @param word the word to be added to the dictionary
		* */
		void insert(TrieNode* currentNode, const char* word);
		
		/**
		* Deletes the node in question based on the return value of the search method
		*
		* @param currentNode the current node in traversing the Trie tree
		* @param word the word to be deleted from the Trie tree
		* */
		void remove(TrieNode* currentNode, const char* word);
		
		/**
		* Displays the Trie tree in lexicographical order (pre-order)
		*
		* @param currentNode the node that will be used in traversal		
		* */
		void lexiDisplay(TrieNode* currentNode);
		
		/**
		* Determine if the character in question (TrieNode) belongs to the Trie structure
		*
		* @param node the node in question
		* @param word the word in question
		*
		* @return if found: the node that was found in the search; else: null;
		* */
		TrieNode* search(TrieNode* currentNode, const char* word);
		
		/**
		* Takes in a character and parses it to the state of the current case
		*
		* @param c the character in question
		* */
		char toCase(char c);
	
	public:
	
		TrieDictionary();
		
		/**
		* Overload constructor to allow the user to specify the case that the dictionary handles
		*
		* @param isLower determines if the case of each character will be treated as lowercase or uppercase
		* */
		TrieDictionary(bool isLower);
		
		/**
		* Sets the current case to the specified case based on the boolean outcome of the parameter
		*
		* @param isLower determines if the case of each character will be treated as lowercase or uppercase
		* */
		void setCase(bool isLower);
	
		/**
		* Add a word to the dictionary		*
		* 
		* @param word the word to be added to the dictionary
		* */
		void insert(const char* word);		
		
		/**
		* Deletes the node in question based on the return value of the search method
		*
		* @param word the word to be deleted from the Trie tree
		* */
		void remove(const char* word);
		
		/**
		* Displays the Trie tree in lexicographical order (pre-order)
		* */
		void lexiDisplay();		
		
		~TrieDictionary();
	
};

#endif /*TRIEDICTIONARY_H_*/