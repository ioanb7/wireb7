#pragma once

#define NCHANGE(variable, value) \
	variable = value; \
	dataTableManager->Changed(&##variable);

#define N0CHANGED(variable) \
	dataTableManager->Changed(&##variable);

/*
template<typename T> struct argument_type;
template<typename T, typename U> struct argument_type<T(U)> { typedef U type; };

#define DECLARE_CLASS( className ) \
	typedef className ThisClass;

#define WIREDVAR(t,name) \
	NETWORK_VAR_START(argument_type<void(t)>::type,name) \
	NETWORK_VAR_END(argument_type<void(t)>::type,name,CNetworkVarBase)

*/