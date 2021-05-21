#pragma once

#include <iostream>
#include <vector>

#include "Common.h"


template<class T, class KOFD, class DToI = Str2Int>
struct HashBucket;

template<class T>
struct HashBucketNode
{
	HashBucketNode(const T& data = T())
	: next(nullptr)
	, val(data)
	{}

	HashBucketNode<T>* next;
	T val;
};

// 封装迭代器
template<class T, class KOFD, class DToI = Str2Int>
struct HashBucketIterator
{
	typedef HashBucketNode<T> Node;
	typedef HashBucketIterator<T, KOFD, DToI> Self;

	HashBucketIterator(Node* node = nullptr, HashBucket<T, KOFD, DToI>* ht = nullptr)
	: _node(node)
	, _ht(ht)
	{}

	// 具有指针类似的行为
	T& operator*()
	{
		return _node->val;
	}

	T* operator->()
	{
		return &(operator*());
	}

	Self& operator++()
	{
		Next();
		return *this;
	}

	Self operator++(int)
	{
		Node* temp(*this);
		Next();
		return temp;
	}

	bool operator== (const Self& s)
	{
		return _node == s._node;
	}

	bool operator!= (const Self& s)
	{
		return _node != s._node;
	}

private:
	void Next()
	{
		if (_node->next)
			_node = _node->next;
		else
		{
			// 计算出桶号
			size_t bucketNo = _ht->HashFunc(_ht->BucketCount(), _node->val) + 1;
			for (; bucketNo < _ht->BucketCount(); ++bucketNo)
			{
				_node = _ht->_table[bucketNo];
				if (_node)
					return;
			}
			_node = nullptr;
		}
	}

private:
	HashBucket<T, KOFD, DToI>* _ht;
	Node* _node;
};



template<class T, class KOFD, class DToI>
struct HashBucket
{
	friend HashBucketIterator<T, KOFD, DToI>;
	typedef HashBucketNode<T> Node;
public:
	typedef HashBucketIterator<T, KOFD, DToI> iterator;

public:
	HashBucket(int capacity = 10)
		: _table(GetNextPrime(capacity))
		, _size(0)
	{}

	~HashBucket()
	{
		Clear();
	}

	// 迭代器
	iterator begin()
	{
		for (size_t bucketNo = 0; bucketNo < BucketCount(); ++bucketNo)
		{
			if (_table[bucketNo])
			{
				return iterator(_table[bucketNo], this);
			}
		}
		return end();
	}

	iterator end()
	{
		return iterator(nullptr, this);
	}

	// 不能插入重复的数字
	std::pair<iterator, bool> InsertUnique(const T& data)
	{
		CheckCapacity();
		KOFD kofd;
		size_t BucketNo = HashFunc(_table.capacity(), data);
		// 1. 找是否有重复的，如果有，返回false
		Node* cur = _table[BucketNo];
		while (cur)
		{
			if (kofd(cur->val) == kofd(data))
				return std::make_pair(iterator(cur, this), false);
			cur = cur->next;
		}
		// 2.选择头插的方式，可以提高效率
		cur = new Node(data);
		cur->next = _table[BucketNo];
		_table[BucketNo] = cur;
		++_size;
		return std::make_pair(iterator(cur, this), true);
	}

	// 可以插入重复的数字
	bool Insert(const T& data)
	{
		CheckCapacity();
		size_t BucketNo = HashFunc(_table.capacity(), data);
		// 选择头插的方式，可以提高效率
		Node* cur = new Node(data);
		cur->next = _table[BucketNo];
		_table[BucketNo] = cur;
		++_size;
		return true;
	}

	size_t EraseUnique(const T& data)
	{
		size_t BucketNo = HashFunc(_table.capacity(), data);
		Node* cur = _table[BucketNo];
		Node* prev = nullptr;
		while (cur)
		{
			if (KOFD()(cur->val) == KOFD()(data))
			{
				if (nullptr == prev)
				{
					_table[BucketNo] = cur->next;
				}
				else
				{
					prev->next = cur->next;
				}
				delete cur;
				cur = nullptr;
				--_size;
				return 1;
			}
			else
			{
				prev = cur;
				cur = cur->next;
			}
		}
		return 0;
	}

	size_t Erase(const T& data)
	{
		return 0;
	}

	iterator Find(const T& data)
	{
		size_t BucketNo = HashFunc(data);
		Node* cur = _table[BucketNo];
		while (cur)
		{
			if (KOFD()(cur->val) == KOFD()(data))
				return iterator(cur, true);
			cur = cur->next;
		}
		return end();
	}

	size_t Size()const
	{
		return _size;
	}

	bool Empty()const
	{
		return 0 == _size;
	}

	size_t BucketCount()const
	{
		return _table.capacity();
	}

	void Print()
	{
		for (size_t bucketNo = 0; bucketNo < _table.capacity(); ++bucketNo)
		{
			std::cout << "[" << bucketNo << "]";
			Node* cur = _table[bucketNo];
			while (cur)
			{
				std::cout << cur->val << "-->";
				cur = cur->next;
			}
			std::cout << "NULL" << std::endl;
		}
	}

	void Swap(HashBucket<T, DToI>& newHt)
	{
		_table.swap(newHt._table);
		std::swap(_size, newHt._size);
	}

	size_t BucketSize(size_t bucketNo)
	{
		size_t count = 0;
		Node* cur = _table[bucketNo];
		while (cur)
		{
			cur = cur->next;
			count++;
		}
		return count;
	}

	size_t Bucket(const T& data)
	{
		return HashFunc(_table.capacity, KOFD()(data));
	}

	void Clear()
	{
		for (size_t bucketNo = 0; bucketNo < _table.capacity(); ++bucketNo)
		{
			Node* cur = _table[bucketNo];
			while (cur)
			{
				_table[bucketNo] = cur->next;

				delete cur;
				cur = _table[bucketNo];
			}
		}
		_size = 0;
	}


private:
	void CheckCapacity()
	{
		if (_size == _table.capacity())
		{
			std::vector<Node*> newTable(GetNextPrime(_table.capacity()) * 2);
			for (size_t i = 0; i < _table.capacity(); ++i)
			{
				Node* cur = _table[i];
				while (cur)
				{
					_table[i] = cur->next;

					// 先计算新的桶号
					size_t bucketNo = HashFunc(newTable.capacity(), cur->val);
				    // 采用头插的方式
					cur->next = newTable[bucketNo];
					newTable[bucketNo] = cur;

					// 取哈希桶中的下一个节点
					cur = _table[i];
				}
			}
			_table.swap(newTable);
		}
	}

	size_t HashFunc(size_t capacity, const T& data)
	{
		DToI dToInt;
		return dToInt(KOFD()(data)) % capacity;
	}

private:
	std::vector<Node*> _table;
	size_t _size;
};
#if 0
void TestHashBucket()
{
	HashBucket<int> ht(7);
	int arr[] = { 19, 14, 23, 1, 68, 20, 84, 27, 55, 11 };
	for (auto& e : arr)
		ht.Insert(e);

	ht.Print();
}


////////////////////////////////////////////////////////
void TestHashBucket1()
{
	int array[] = { 19, 14, 23, 1, 68, 20, 84, 27, 55, 11 };
	HashBucket<int> ht;

	for (auto e : array)
		ht.Insert(e);


	ht.Print();

	ht.Insert(10);
	ht.Insert(79);
	ht.Print();

	auto it = ht.begin();
	while (it != ht.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	for (auto e : ht)
		std::cout << e << " ";
	std::cout << std::endl;
}


#include <string>

void TestHashBucket2()
{
	HashBucket<std::string, Str2Int> ht;
	ht.Insert("apple");
	ht.Insert("orange");
	ht.Insert("banana");
	for (auto e : ht)
		std::cout << e << std::endl;
	std::cout << std::endl;
}

#endif