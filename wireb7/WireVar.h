#pragma once


template< class Type, class Changer >
class CNetworkVarBase
{
public:
	inline CNetworkVarBase()
	{
		m_Value = Type(0);
	}

	template< class C >
	const Type& operator=(const C &val)
	{
		return Set((const Type)val);
	}

	template< class C >
	const Type& operator=(const CNetworkVarBase< C, Changer > &val)
	{
		return Set((const Type)val.m_Value);
	}

	const Type& Set(const Type &val)
	{
		if (memcmp(&m_Value, &val, sizeof(Type)))
		{
			NetworkStateChanged();
			m_Value = val;
		}
		return m_Value;
	}

	Type& GetForModify()
	{
		NetworkStateChanged();
		return m_Value;
	}

	template< class C >
	const Type& operator+=(const C &val)
	{
		return Set(m_Value + (const Type)val);
	}

	template< class C >
	const Type& operator-=(const C &val)
	{
		return Set(m_Value - (const Type)val);
	}

	template< class C >
	const Type& operator/=(const C &val)
	{
		return Set(m_Value / (const Type)val);
	}

	template< class C >
	const Type& operator*=(const C &val)
	{
		return Set(m_Value * (const Type)val);
	}

	template< class C >
	const Type& operator^=(const C &val)
	{
		return Set(m_Value ^ (const Type)val);
	}

	template< class C >
	const Type& operator|=(const C &val)
	{
		return Set(m_Value | (const Type)val);
	}

	const Type operator!()
	{
		return !m_Value;
	}

	const Type& operator++()
	{
		return (*this += 1);
	}

	Type operator--()
	{
		return (*this -= 1);
	}

	Type operator++(int) // postfix version..
	{
		Type val = m_Value;
		(*this += 1);
		return val;
	}

	Type operator--(int) // postfix version..
	{
		Type val = m_Value;
		(*this -= 1);
		return val;
	}

	// For some reason the compiler only generates type conversion warnings for this operator when used like 
	// CNetworkVarBase<unsigned char> = 0x1
	// (it warns about converting from an int to an unsigned char).
	template< class C >
	const Type& operator&=(const C &val)
	{
		return Set(m_Value & (const Type)val);
	}

	operator const Type&() const
	{
		return m_Value;
	}

	const Type& Get() const
	{
		return m_Value;
	}

	const Type* operator->() const
	{
		return &m_Value;
	}

	Type m_Value;

protected:
	inline void NetworkStateChanged()
	{
		Changer::NetworkStateChanged(this);
	}
};

























