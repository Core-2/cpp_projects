#ifndef INTARRAY_H
#define INTARRAY_H

#include <initializer_list>

class IntArray
{
private:
	int m_length{};
	int* m_data{};

public:
	IntArray() = default;

	IntArray(int length);

	IntArray(std::initializer_list<int> list);

	IntArray(const IntArray&) = delete;

	~IntArray();

	void erase();

	int& operator[](int index);

	IntArray& operator=(std::initializer_list<int> list);

	IntArray& operator=(const IntArray& list) = delete;

	int getLength() const;

	void reallocate(int newLength);

	void resize(int newLength);

	void insertBefore(int value, int index);

	void remove(int index);

	void insertAtBeginning(int value);

	void insertAtEnd(int value);
};

#endif // !INTARRAY_H