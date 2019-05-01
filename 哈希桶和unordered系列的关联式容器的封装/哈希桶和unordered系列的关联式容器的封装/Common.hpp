#pragma once

//查表寻找下一个素数
size_t GetNextPrime(size_t prime);

template<class T>
class KeyToInt
{
public:
	const T& operator()(const T& data)
	{
		return data;
	}
};