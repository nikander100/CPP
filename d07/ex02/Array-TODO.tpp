#include "Array.hpp"

template <typename T>
Array<T>::Array() : _arr(new T[0]), _size(0) {
}

template <typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]), _size(n) {
}

template <typename T>
Array<T>::Array(const Array &rhs) : _arr(new T[rhs.size()]), _size(rhs.size()) {
	for (unsigned int i = 0; i < _size; i++)
		_arr[i] = rhs._arr[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& rhs) {
	if (&rhs == this) {
		return *this;
	}
	delete[] _arr;
	_arr = new T[rhs.size()];
	_size = rhs._size;
	for (unsigned int i = 0; i < _size; i++ ) {
		_arr[i] = rhs._arr[i];
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int i) const {
	if (i >= _size)
		throw OutOfBoundsException();
	return _arr[i];
}

template <typename T>
unsigned int Array<T>::size() const {
	return _size;
}

template <typename T>
Array<T>::~Array() {
	delete [] _arr;
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const noexcept {
	return "Index is out of bounds";
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const Array<T> &arr) {
	for (unsigned int i = 0; i < arr.size(); i++)
		out << arr[i] << " ";
	return out;
}