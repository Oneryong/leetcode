/*************************************************************
 * >Author: zhongwanyong
 * >Email:  zwy249348626@163.com
 * >Create Time: 2015/07/01 11:44:03
 * >File Name: implement_trie_Prefix_Tree.cpp
 * >Description: 
 *************************************************************/

#include <iostream>
#include <cstring>

using namespace std;

/*
 * Implement a trie(字典树，单词查找树) with insert, search, and startsWith methods.
 *
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 */

class TrieNode
{
	public:
		char ch;
		bool isWord;
		TrieNode* children[26];    //we can use unordered_map instead of it, that can save memory.
		
		// Initialize your data structure here.
		TrieNode() : ch(0), isWord(false)
		{
			memset(children, 0, sizeof(TrieNode*) * 26);
		}
		
		TrieNode(char c) : ch(c), isWord(false)
		{
			memset(children, 0, sizeof(TrieNode*) * 26);
		}
};

class Trie
{
	public:
		Trie()
		{
			root = new TrieNode();
		}

		// Inserts a word into the trie.
		void insert(string word)
		{
			TrieNode* p = root;
			int len = word.size();
			if(len <= 0)
			{
				return;
			}

			char temp;
			for(int i = 0; i < len; ++i)
			{
				temp = word[i];
				TrieNode* q;
				if(p -> children[temp - 'a'] == 0)
				{
					q = new TrieNode(temp);
					p -> children[temp - 'a'] = q;
				}
				p = p -> children[temp - 'a'];
			}
			p -> isWord = true;
		}

		// Returns if the word is in the trie.
		bool search(string word)
		{
			TrieNode* p = root;
			int len = word.size();
			if(len <= 0)
				return true;

			char temp;
			for(int i = 0; i < len; ++i)
			{
				temp = word[i];
				p = p -> children[temp - 'a'];
				if(p == 0)
					return false;
			}
			return p -> isWord;
		}

		// Returns if there is any word in the trie
		// that starts with the given prefix.
		bool startsWith(string prefix)
		{
			TrieNode* p = root;
			int len = prefix.size();
			if(len <= 0)
				return true;

			char temp;
			for(int i = 0; i < len; ++i)
			{
				temp = prefix[i];
				p = p -> children[temp - 'a'];
				if(p == 0)
					return false;
			}
			return true;
		}

		//free Trie memory
		void freeTrieNode(TrieNode* p)
		{
			if(p == NULL)
				return;
			for(int i = 0; i < 26; ++i)
			{
				TrieNode* pChild = p -> children[i];
				if(pChild != 0)
				{
					freeTrieNode(pChild);
				}
			}
			delete p;
		}

		~Trie()
		{
			freeTrieNode(root);
		}
	
	private:
		TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main()
{
	return 0;
}
