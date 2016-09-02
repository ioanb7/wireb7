#pragma once

template<typename T> struct argument_type;
template<typename T, typename U> struct argument_type<T(U)> { typedef U type; };
#define WIREDVAR(t,name) argument_type<void(t)>::type name