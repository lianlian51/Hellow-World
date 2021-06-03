#pragma once

#include <string>

template<class T>
class DToIntDef
{
public:
	size_t operator()(const T& data)
	{
		return data;
	}
};

class Str2Int
{
public:
	size_t operator()(const std::string& s)
	{
		return BKDRHash(s.c_str());
	}
	size_t BKDRHash(const char* str)
	{
		size_t seed = 131;
		size_t hash = 0;
		while (*str)
		{
			hash = hash * seed + (*str++);
		}
		return (hash & 0x7FFFFFFF);
	}
};


const int _PrimeSize = 28;
int GetNextPrime(int value)
{
	static const unsigned long _PrimeList[_PrimeSize] =
	{
		53ul, 97ul, 193ul, 389ul, 769ul,

		1543ul, 3079ul, 6151ul, 12289ul, 24593ul,

		49157ul, 98317ul, 196613ul, 393241ul, 786433ul,

		1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,

		50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,

		1610612741ul, 3221225473ul, 4294967291ul
	};
	for (size_t i = 0; i < _PrimeSize; i++)
	{
		if (_PrimeList[i] > value)
			return _PrimeList[i];
	}
	return _PrimeList[_PrimeSize - 1];
}