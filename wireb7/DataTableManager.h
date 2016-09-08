#pragma once

#include <iostream>
#include <map>
#include "WireVar.h"
#include <string>
#include <sstream>

using namespace std;

class DataTableManager
{
public:
	DataTableManager(int entityId, int entityGlobalUId) {
		memoryAddresses = std::map<int, void*>();
		addressSizes = std::map<void*, int>();
		m_entityId = entityId;
		m_entityGlobalUId = entityGlobalUId;

		std::ostringstream ss;

		ss.precision(3);
		ss << (char)(entityGlobalUId); // limit to 0..255
		ss << m_entityId;
		ss << endl;

		std::cout << ss.str() << endl;
	}

	void Add(int s, void *ptr)
	{
		auto search = addressSizes.find(ptr);
		if (search == addressSizes.end()) {
			memoryAddresses[p] = ptr;
			addressSizes[ptr] = p;
			p += s;
		};
	}


	template<typename T, typename C>
	void Changed(CNetworkVarBase<T, C> *ptr)
	{
		auto search = addressSizes.find(ptr);
		if (search != addressSizes.end()) {
			std::ostringstream ss;

			ss.precision(3);
			ss << m_entityId;
			ss << (char)(search->second);
			ss << fixed;
			ss << ptr->m_Value;

			std::cout << ss.str() << endl;
		}
	}

private:
	std::map<int, void*> memoryAddresses;
	std::map<void*, int> addressSizes;
	int p = 0;
	int m_entityId;
	int m_entityGlobalUId;
};