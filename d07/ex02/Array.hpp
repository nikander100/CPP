#pragma once

#include <iostream>
#include <exception>

template <typename T>
class Array {
private:
	T *_arr;
	uint64_t _size;

public:
	Array();
	Array(unsigned int n);
	Array(const Array &copy);
	Array &operator=(const Array& rhs);
	T& operator[](unsigned int i) const;
	unsigned int size() const;
	~Array();

	class OutOfBoundsException : public std::exception {
	public:
		const char* what() const noexcept override;
	};
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const Array<T> &arr);

#include "Array.tpp"

// #pragma once

// #include <iostream>

// template <typename T>
// class Array {

// private:
// 	T *_arr;
// 	uint64_t _size;

// public:
// 	Array() : _arr(new T([0])), _size(0) {
// 	};

// 	Array(unsigned int n) : _arr(new T[n]), _size(n) {
// 	};

// 	Array(const Array &copy) : _arr(new T[rhs.size()]), _size(rhs.size()) {
// 		for (unsigned int i = 0; i < _size; i++)
// 			_arr[i] = rhs._arr[i];
// 	};

// 	Array &operator=(const Array& rhs) {
// 		if (this != &rhs) {
// 			delete[] _arr;
// 			_arr = new T[rhs.size()];
// 			_size = rhs._size;
// 			for (unsigned int i = 0; i < _size; i++ )
// 				_arr[i] = rhs._arr[i];
// 		}
// 		return *this;
// 	} q

// 	T& operator[]( unsigned int i ) const {
// 		if ( i >= _size )
// 			throw OutOfBoundsException();
// 		return _arr[i];
// 	}

// 	unsigned int  size( void ) const { return _size; }

// 	~Array( void ) { delete [] _arr; }

// 	class OutOfBoundsException : public std::exception {
// 		public:
// 			const char* what() const noexcept override {
// 				return "Index is out of bounds";
// 			}
// 	};
// };

// template <typename T>
// std::ostream &operator<<( std::ostream& out, const Array<T> &arr ) {
// 	for ( unsigned int i = 0; i < arr.size(); i++ )
// 		out << arr[i] << " ";
// 	return out;
// }