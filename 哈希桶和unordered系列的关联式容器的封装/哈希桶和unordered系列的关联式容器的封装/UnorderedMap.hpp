#pragma once
#include "HashTable.hpp"

template<class K, class V>
class Unordered_Map
{
public:
	typedef pair<K, V> ValueType;
	struct KeyOfValue
	{
		const K& operator()(const ValueType& data)
		{
			return data.first;
		}
	};
	typedef HashTable<ValueType, KeyOfValue, KeyToInt<K>> HashTable;
	typedef HashTable* pHashTable;
	typename typedef HashTable::Iterator Iterator;
public: 
	Unordered_Map()
		:_pHT()
	{}

	Iterator Begin()
	{
		return _pHT.Begin();
	}

	Iterator End()
	{
		return _pHT.End();
	}

	pair<Iterator, bool> Insert(const ValueType& data)
	{
		return _pHT.InsertUnique(data);
	}

	size_t Erase(const K& key)
	{
		return _pHT.EraseUnique(make_pair(key, V()));
	}

	Iterator Find(const K& key) const
	{
		return _pHT.Find(make_pair(key, V()));
	}

	size_t Size()const
	{
		return _pHT.Size();
	}

	bool Empty() const
	{
		return _pHT.Empty();
	}

	size_t BucketCount()const
	{
		return _pHT.BucketCount();
	}

	size_t BucketSize(size_t num)
	{
		return _pHT.BucketSize(num);
	}

	V& operator[](const K& kay)
	{
		Iterator it = _pHT.Find(make_pair(key, v()));
		assert(it != _pHT.End());

		return it->second;
	}

private:
	HashTable _pHT;
};