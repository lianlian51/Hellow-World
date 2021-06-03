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
		//����ڴ˴��������κε�˵������������Ͳ�֪��iterator�Ǻ�����е����ͻ��Ǿ�̬��Ա����
		typedef typename RBT::iterator iterator;
	public:

		map()
			:_t()
		{}

		// ������
		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		// ����
		size_t size()const
		{
			return _t.size();
		}

		bool empty()const 
		{
			return _t.empty();
		}

		// �±�
		V& operator[](const K& data)
		{
			return (*(_t.Insert(std::make_pair(data, V()))).first).second;
		}

		// ����
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
	m.insert(std::make_pair("teacher", "��ʦ"));
	m.insert(std::make_pair("student", "ѧ��"));
	m.insert(std::make_pair("son", "����"));

	std::cout << m.size() << std::endl;

	m["dad"] = "�ְ�";

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