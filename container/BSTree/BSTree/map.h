#pragma once

#include "RBTree.hpp"

namespace Test
{
	template<class K, class V>
	class map
	{
		typedef std::pair<K, V> ValueType;
		struct KOFD
		{
			const K& operator()(const ValueType& data)
			{
				return data.first;
			}
		};

		typedef RBTree<ValueType, KOFD> RBT;
	public:
		//如果在此处不进行任何的说明，则编译器就不知道iterator是红黑树中的类型还是静态成员变量
		typedef typename RBT::iterator iterator;
	public:

		map()
			:_t()
		{}

		// 迭代器
		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		// 容量
		size_t size()const
		{
			return _t.size();
		}

		bool empty()const 
		{
			return _t.empty();
		}

		// 下标
		V& operator[](const K& data)
		{
			return (*(_t.Insert(std::make_pair(data, V()))).first).second;
		}

		// 插入
		std::pair<iterator, bool> insert(const ValueType& data)
		{
			return _t.Insert(data);
		}

		void swap(map<K, V>& m)
		{
			_t.Swap(m._t);
		}

		void clear()
		{
			_t.Clear();
		}

		iterator find(const K& data)
		{
			return _t.Find(std::make_pair(data, V()));
		}
	private:
		RBT _t;
	};
}

#include <string>
#include <iostream>

void TestMap()
{
	Test::map<std::string, std::string> m;
	m.insert(std::make_pair("teacher", "老师"));
	m.insert(std::make_pair("student", "学生"));
	m.insert(std::make_pair("son", "儿子"));

	std::cout << m.size() << std::endl;

	m["dad"] = "爸爸";

	auto it = m.begin();
	while (it != m.end())
	{
		std::cout << it->first << " " << it->second << std::endl;
		++it;
	}
	std::cout << std::endl;

	it = m.find("sister");
	if (it != m.end())
	{
		std::cout << "sister is in m" << std::endl;
	}
	else
	{
		std::cout << "sister is not in m" << std::endl;
	}

	m.clear();
	std::cout << m.size() << std::endl;
}