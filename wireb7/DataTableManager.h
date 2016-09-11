#pragma once

#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

enum Type {
	_bool = 2 ^ 0,
	_int = 2 ^ 1,
	_float = 2 ^ 2
};

class DataTableManager
{
public:
	DataTableManager(int entityId, int entityGlobalUId) {
		memoryAddresses = std::map<int, void*>();
		addressSizes = std::map<void*, int>();
		memoryAddressTypes = std::map<void*, Type>();
		m_entityId = entityId;
		m_entityGlobalUId = entityGlobalUId;

		std::ostringstream ss;

		ss.precision(3);
		//ss << endl;
		ss << (char)(entityGlobalUId); // limit to 0..255
		ss << m_entityId;
		//ss << endl;


		std::cout << ss.str();
	}

	void Add(int n, Type t, void *ptr)
	{
		auto search = addressSizes.find(ptr);
		if (search == addressSizes.end()) {
			memoryAddresses[n] = ptr;
			memoryAddressTypes[ptr] = t;
			addressSizes[ptr] = n;

			Changed(ptr);
		};
	}


	void Changed(void *ptr)
	{
		auto search = addressSizes.find(ptr);
		if (search != addressSizes.end()) {
			std::ostringstream ss;

			ss << m_entityId;
			ss << (char)(search->second);

			Type t = memoryAddressTypes[ptr];
			if (t == Type::_bool) {
				ss << *(bool*)ptr;
			}
			if (t == Type::_int) {
				ss << *(int*)ptr;
			}
			if (t == Type::_float) {
				ss.precision(3);
				ss << fixed;
				ss << *(float*)ptr;
			}

			std::cout << ss.str();
		}
	}

private:
	std::map<int, void*> memoryAddresses;
	std::map<void*, int> addressSizes;
	std::map<void*, Type> memoryAddressTypes;
	
	int m_entityId;
	int m_entityGlobalUId;
};