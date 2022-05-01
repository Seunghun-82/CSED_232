/* CSED232 OOP Assgin 4 Skeleton Code
This code is made based on Prof.Sunghyun Cho's code.
Do not modify outline of the code.*/
#ifndef __SMARTPTR_H__
#define __SMARTPTR_H__

#include <iostream>
#include <cassert>

template<typename ObjectType>
void Deallocator(ObjectType* ptr)
{
#ifdef DeallocMessage
	std::cout << "Deallocate an object" << std::endl;
#endif
	delete ptr;
}

template<typename ObjectType>
void ArrayDeallocator(ObjectType* ptr)
{
#ifdef DeallocMessage
	std::cout << "Deallocate an array" << std::endl;
#endif
	delete[] ptr;
}

template<typename T>
using DeallocatorFuncType = void(T*);

//SmartPtr Decralation
template<typename ObjectType, DeallocatorFuncType<ObjectType> Dealloc = Deallocator<ObjectType> >
class SmartPtr
{
	class CountedObjectContainer
	{
	private:
		~CountedObjectContainer() { if (m_object) { Dealloc(m_object); } }

	public:
		CountedObjectContainer() : m_ref_count(0), m_object(nullptr) {}
		CountedObjectContainer(ObjectType* obj) : m_ref_count(1), m_object(obj) {}

		void increase_ref_count() { ++m_ref_count; }
		void decrease_ref_count() { if (--m_ref_count == 0) delete this; }
		const ObjectType* get_object() const { return m_object; }
		ObjectType* get_object() { return m_object; }
		int get_ref_count() const { return m_ref_count; }

	private:
		int m_ref_count;
		ObjectType* m_object;
	};

private:
	CountedObjectContainer* m_ref_object;
public:
	SmartPtr() : m_ref_object(nullptr) {}
	SmartPtr(ObjectType* object)
	{
		if (object != NULL)
		{
			m_ref_object = new CountedObjectContainer(object);
		}
		else
		{
			m_ref_object = NULL;
		}
	}
	SmartPtr(const SmartPtr& pointer)
	{
		if (pointer.m_ref_object != NULL)
		{
			m_ref_object = pointer.m_ref_object;
			pointer.m_ref_object->increase_ref_count();
		}
		else
		{
			m_ref_object = pointer.m_ref_object;
		}
	}
	~SmartPtr()
	{
		m_ref_object->decrease_ref_count();
	}
	SmartPtr& operator=(ObjectType* object)
	{
		if (m_ref_object == NULL)
		{
			m_ref_object = new CountedObjectContainer(object);
		}
		else
		{
			m_ref_object->decrease_ref_count();
			m_ref_object = new CountedObjectContainer(object);
		}
		return *this;
	}
	SmartPtr& operator=(const SmartPtr& ref_pointer)
	{
		if (m_ref_object == NULL)
		{
			m_ref_object = ref_pointer.m_ref_object;
			m_ref_object->increase_ref_count();
		}
		else
		{
			m_ref_object->decrease_ref_count();
			m_ref_object = ref_pointer.m_ref_object;
			m_ref_object->increase_ref_count();
		}
		return *this;
	}

	int ref_count()
	{
		return m_ref_object->get_ref_count();
	}

	const ObjectType* operator->() const
	{
		assert(m_ref_object);
		return m_ref_object->get_object();
	}

	ObjectType* operator->()
	{
		assert(m_ref_object);
		return m_ref_object->get_object();
	}

	const ObjectType& operator*() const
	{
		assert(m_ref_object);
		return *(m_ref_object->get_object());
	}

	ObjectType& operator*()
	{
		assert(m_ref_object);
		return *(m_ref_object->get_object());
	}

	const ObjectType& operator[](int i) const
	{
		assert(m_ref_object);
		return (m_ref_object->get_object())[i];
	}

	ObjectType& operator[](int i)
	{
		assert(m_ref_object);
		return (m_ref_object->get_object())[i];
	}

	operator ObjectType const* () const
	{
		assert(m_ref_object);
		return m_ref_object->get_object();
	}

	operator ObjectType* ()
	{
		assert(m_ref_object);
		return m_ref_object->get_object();
	}
};
template<typename T>
using SmartArray = SmartPtr<T, ArrayDeallocator<T> >;

#endif

//SmartMatrix Declartion.
#ifndef __SMARTMATRIX_H__
#define __SMARTMATRIX_H__

template<typename T>
class SmartMatrix
{
private:
	int m_rows, m_cols;
	SmartArray<T> m_values;
public:
	SmartMatrix() : m_rows(0), m_cols(0), m_values(nullptr) {}
	SmartMatrix(int rows, int cols)
	{
		m_rows = rows;
		m_cols = cols;
		m_values = new T[rows * cols];
	}
	SmartMatrix(const SmartMatrix<T>& mtx)
	{
		m_rows = mtx.m_rows;
		m_cols = mtx.m_cols;
		m_values = new T[m_rows * m_cols];
		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_cols; j++)
			{
				m_values[i * m_cols + j] = mtx.m_values[i * m_cols + j];
			}
		}
	}
	SmartMatrix(int rows, int cols, const T* values)
	{
		m_rows = rows;
		m_cols = cols;
		m_values = new T[m_rows * m_cols];
		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_cols; j++)
			{
				m_values[i * m_cols + j] = values[i * m_cols + j];
			}
		}
	}
	~SmartMatrix() {}
	// You don't have to implement Destructor because SmartMatrix use Smart Pointer.

	SmartMatrix<T>& operator=(const SmartMatrix<T>& mtx)
	{
		//Assignment operator
		m_rows = mtx.m_rows;
		m_cols = mtx.m_cols;
		m_values = mtx.m_values;
		return *this;
	}
	void AddRow(const T* values)
	{
		m_rows++;

		SmartArray<T> new_values = new T[m_rows * m_cols];
		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_cols; j++)
			{
				new_values[i * m_cols + j] = m_values[i * m_cols + j];
			}
		}
		for (int i = 0; i < m_cols; i++)
		{
			new_values[(m_rows - 1) * m_cols + i] = values[i];
		}
		m_values = new_values;
	}
	void AddCol(const T* values)
	{
		m_cols++;

		SmartArray<T> new_values = new T[m_rows * m_cols];
		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_cols; j++)
			{
				if (j != m_cols - 1)
				{
					new_values[i * m_cols + j] = m_values[i * (m_cols - 1) + j];
				}
				else
				{
					new_values[i * m_cols + j] = values[i];
				}
			}
		}
		m_values = new_values;
	}
	const SmartMatrix<T> Inverse()
	{
		assert(m_rows == 2 && m_cols == 2);
		T determinant = m_values[0] * m_values[3] - m_values[1] * m_values[2];
		assert(determinant != 0);
		T tempt = m_values[0];
		m_values[0] = m_values[3];
		m_values[3] = tempt;

		m_values[1] = -1 * m_values[1];
		m_values[2] = -1 * m_values[2];

		m_values[0] = m_values[0] / determinant;
		m_values[1] = m_values[1] / determinant;
		m_values[2] = m_values[2] / determinant;
		m_values[3] = m_values[3] / determinant;

		SmartMatrix<T> ret(2, 2, m_values);
		return ret;
	}

	T* operator[](int r)
	{
		return &m_values[r * m_cols];
	}

	const T* operator[](int r) const
	{
		return &m_values[r * m_cols];
	}

	int rows() const { return m_rows; }
	int cols() const { return m_cols; }

	const SmartMatrix<T> clone() const
	{
		return SmartMatrix<T>(m_rows, m_cols, (const T*)m_values);
	}
};

//Operator Overloading

template<typename T>
std::ostream& operator<<(std::ostream& os, const SmartMatrix<T>& m)
{
	//Stream extraction operator overloading
	//Now you can print SmartMatrix
	for (int r = 0; r < m.rows(); r++) {
		for (int c = 0; c < m.cols(); c++) {
			os << m[r][c] << " ";
		}
		os << std::endl;
	}

	return os;
}

template<typename T>
const SmartMatrix<T> operator+(const SmartMatrix<T>& a, const SmartMatrix<T>& b)
{
	assert(a.cols() == b.cols());
	assert(a.rows() == b.rows());
	SmartArray<T> new_values = new T[a.rows() * a.cols()];
	for (int i = 0; i < a.rows(); i++)
	{
		for (int j = 0; j < a.cols(); j++)
		{
			new_values[i * a.cols() + j] = a[i][j] + b[i][j];
		}
	}
	SmartMatrix<T> ret(a.rows(), a.cols(), new_values);
	return ret;
}

template<typename T>
const SmartMatrix<T> operator-(const SmartMatrix<T>& a, const SmartMatrix<T>& b)
{
	assert(a.cols() == b.cols());
	assert(a.rows() == b.rows());
	SmartArray<T> new_values = new T[a.rows() * a.cols()];
	for (int i = 0; i < a.rows(); i++)
	{
		for (int j = 0; j < a.cols(); j++)
		{
			new_values[i * a.cols() + j] = a[i][j] - b[i][j];
		}
	}
	SmartMatrix<T> ret(a.rows(), a.cols(), new_values);
	return ret;
}

template<typename T>
const SmartMatrix<T> operator*(const SmartMatrix<T>& a, T s)
{
	SmartArray<T> new_values = new T[a.rows() * a.cols()];
	for (int i = 0; i < a.rows(); i++)
	{
		for (int j = 0; j < a.cols(); j++)
		{
			new_values[i * a.cols() + j] = a[i][j] * s;
		}
	}
	SmartMatrix<T> ret(a.rows(), a.cols(), new_values);
	return ret;
}

template<typename T>
inline const SmartMatrix<T> operator*(T s, const SmartMatrix<T>& a)
{
	/*
	Multiply Operator Overloading
	You Don't have to implement here.
	*/
	return a * s;
}
template<typename T>
inline const SmartMatrix<T> operator*(const SmartMatrix<T>& a, const SmartMatrix<T>& b)
{
	assert(a.cols() == b.rows());
	SmartArray<T> new_values = new T[a.rows() * b.cols()];
	for (int i = 0; i < a.rows(); i++)
	{
		for (int j = 0; j < b.cols(); j++)
		{
			T sum_values = 0;
			for (int k = 0; k < a.cols(); k++)
			{
				sum_values = sum_values + a[i][k] * b[k][j];
			}
			new_values[i * b.cols() + j] = sum_values;
		}
	}
	SmartMatrix<T> ret(a.rows(), b.cols(), new_values);
	return ret;
}
#endif