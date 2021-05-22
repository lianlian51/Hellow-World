#pragma once
#include <iostream>
#include <string>
#include <vector>

class Trie
{
public:
	Trie() : children(26), isEnd(false) {}

	void insert(std::string prefix)
	{
		Trie* node = this;
		for (char ch : prefix)
		{
			ch -= 'a';
			if (node->children[ch] == nullptr)
			{
				node->children[ch] = new Trie();
			}
			node = node->children[ch];
		}
		node->isEnd = true;
	}

	bool search(std::string prefix)
	{
		Trie* node = this->searchPrefix(prefix);
		return node != nullptr && node->isEnd;
	}

	bool startsWith(std::string prefix)
	{
		return this->searchPrefix(prefix) != nullptr;
	}

private:
	Trie* searchPrefix(std::string prefix)
	{
		Trie* node = this;
		for (char ch : prefix)
		{
			ch -= 'a';
			if (node->children[ch] == nullptr)
				return nullptr;
			node = node->children[ch];
		}
		return node;
	}

private:
	std::vector<Trie*> children;
	bool isEnd;
};

void TestTrie()
{
	Trie* trie = new Trie();
	trie->insert("apple");
	std::cout << trie->search("apple") << std::endl;   // 返回 True
	std::cout << trie->search("app") << std::endl;       // 返回 False
	std::cout << trie->startsWith("app") << std::endl; // 返回 True
	trie->insert("app");
	std::cout << trie->search("app") << std::endl;     // 返回 True
}