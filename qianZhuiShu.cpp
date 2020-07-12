#include<string>
#include<unordered_map>
using namespace std;

class trienode
{
public:
	trienode() : isWord(false) {};
	unordered_map<char, trienode*> children;
	bool isWord;
};

class Trie
{
public:
	Trie() 
	{
		root = new trienode();// void head
	};


	void insert(string s)
	{
		if (s.size() <= 0) return;
		trienode* node = root;
		for (int i = 0; i < s.length(); i++)
		{
			if (node->children.find(s[i])==node->children.end())
			{   
				node->children[s[i]]= new trienode();
			}
			node = node->children[s[i]];
		}
		node->isWord = true;
	}

	bool search(string word)
	{
		return retrive(word, true);
	}
	
	bool isprefix(string word)
	{
		return retrive(word, false);
	}
private:
	inline bool retrive(const string& key, bool isword)
	{
		if (key.size() <= 0) return;
		trienode* node = root;
		for (int i = 0; i < key.length(); i++)
		{
			if (node->children.find(key[i]) == node->children.end())
			{
				return false;
			}
			node = node->children[key[i]];
		}
		return isword?node->isWord:true;//e.g here is ¡®input¡¯in dic but search 'in'.
	}
	trienode* root;
};



