#pragma once

#include "DataTableManager.h"

template <class A_Type> class WiringClass
{
public:
	WiringClass(char *val, DataTableManager dataTableManager);
	WiringClass(DataTableManager dataTableManager);
};


//Constructor
template <class A_Type>
WiringClass<A_Type>::WiringClass(char *val, DataTableManager dataTableManager)
{
	//dataTableManager.Add(0, val);
}
//Constructor
template <class A_Type>
WiringClass<A_Type>::WiringClass(DataTableManager dataTableManager)
{
	//dataTableManager.Add(0, val);
}