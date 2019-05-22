#pragma once
#include "HashTable.hpp"

template<class K>
class UnorderedMulti_Set
{
public:
	typedef K ValueType;
	struct KeyOfValue
	{
		const K& operator()(const ValueType& data)
		{
			return data;
		}
	};
	typedef HashTable<ValueType, KeyOfValue, KeyToInt<K>> HashTable;
	typedef HashTable* pHashTable;
	typename typedef HashTable::Iterator Iterator;
public:
	UnorderedMulti_Set()
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

	Iterator Insert(const ValueType& data)
	{
		return _pHT.InsertEqual(data);
	}

	size_t Erase(const K& key)
	{
		return _pHT.EraseEqual(key);
	}

	Iterator Find(const K& key) const
	{
		return _pHT.Find(key);
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

private:
	HashTable _pHT;
};