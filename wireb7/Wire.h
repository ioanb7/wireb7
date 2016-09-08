#pragma once
#include "WireVar.h"
#include "WiringClass.h"

template<typename T> struct argument_type;
template<typename T, typename U> struct argument_type<T(U)> { typedef U type; };

#define DECLARE_CLASS( className ) \
	typedef className ThisClass;

#define WIREDVAR(t,name) \
	NETWORK_VAR_START(argument_type<void(t)>::type,name) \
	NETWORK_VAR_END(argument_type<void(t)>::type,name,CNetworkVarBase)

#define NETWORK_VAR_START( type, name ) \
	class NetworkVar_##name; \
	friend class NetworkVar_##name; \
	typedef ThisClass MakeANetworkVar_##name; \
	class NetworkVar_##name \
	{ \
	public: \
		NetworkVar_##name() {\
		}\
		template<typename T, typename C> \
		static inline void NetworkStateChanged(CNetworkVarBase<T, C> *ptr) \
		{ \
			ThisClass::dataTableManager->Add(sizeof(T), ptr); \
			ThisClass::dataTableManager->Changed(ptr); \
		} \
	};

#define NETWORK_VAR_END( type, name, base ) \
	base< type, NetworkVar_##name > name;