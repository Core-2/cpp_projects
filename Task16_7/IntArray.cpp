#include "IntArray.h"
#include <cassert>
#include <initializer_list>

IntArray::IntArray(int length) :
	m_length{ length }
{
	assert(length >= 0);

	if (length > 0)
		m_data = new int[length] {};
}

IntArray::IntArray(std::initializer_list<int> list) :
	IntArray(static_cast<int>(list.size()))
{
	int count{ 0 };
	for (auto element : list)
	{
		m_data[count] = element;
		++count;
	}
}

IntArray::~IntArray()
{
	delete[] m_data;
}

void IntArray::erase()
{
	delete[] m_data;

	m_data = nullptr;
	m_length = 0;
}

int& IntArray::operator[](int index)
{
	assert(index >= 0 && index < m_length);
	return m_data[index];
}

IntArray& IntArray::operator=(std::initializer_list<int> list)
{
	int length{ static_cast<int>(list.size()) };

	if (length != m_length)
	{
		delete[] m_data;
		m_length = length;
		m_data = new int[length] {};
	}

	int count{ 0 };
	for (auto element : list)
	{
		m_data[count] = element;
		++count;
	}

	return *this;
}

int IntArray::getLength() const
{
	return m_length;
}

void IntArray::reallocate(int newLength)
{
	erase();

	if (newLength <= 0)
		return;

	m_data = new int[newLength];
	m_length = newLength;
}

void IntArray::resize(int newLength)
{
	if (newLength == m_length)
		return;

	if (newLength <= 0)
	{
		erase();
		return;
	}

	int* data{ new int[newLength] };

	if (m_length > 0)
	{
		int elementsToCopy{ (newLength > m_length) ? m_length : newLength };

		for (int index{ 0 }; index < elementsToCopy; ++index)
			data[index] = m_data[index];
	}

	delete[] m_data;

	m_data = data;
	m_length = newLength;
}

void IntArray::insertBefore(int value, int index)
{
	assert(index >= 0 && index <= m_length);

	int* data{ new int[m_length + 1] };

	for (int before{ 0 }; before < index; ++before)
		data[before] = m_data[before];

	data[index] = value;

	for (int after{ index }; after < m_length; ++after)
		data[after + 1] = m_data[after];

	delete[] m_data;
	m_data = data;
	++m_length;
}

void IntArray::remove(int index)
{
	assert(index >= 0 && index < m_length);

	if (m_length == 1)
	{
		erase();
		return;
	}

	int* data{ new int[m_length - 1] };

	for (int before{ 0 }; before < index; ++before)
		data[before] = m_data[before];

	for (int after{ index }; after < m_length; ++after)
		data[after - 1] = m_data[after];

	delete[] m_data;
	m_data = data;
	--m_length;
}

void IntArray::insertAtBeginning(int value)
{
	insertBefore(value, 0);
}

void IntArray::insertAtEnd(int value)
{
	insertBefore(value, m_length);
}