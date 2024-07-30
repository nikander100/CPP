#pragma once

#include <type_traits>
#include <cstddef>
#include <iostream>

template <typename T, typename Function>
void iter(T *array, size_t size, Function f) {
	if (array == nullptr) return;
	for (size_t i = 0; i < size; i++) f(array[i]);
}

template<typename T>
void print(T &i) {
	std::cout << i << std::endl;
}

template<typename T>
void increment(T &value) {
	value++;
}

template<typename T>
void doubleValue(T &value) {
	value *= 2;
}

template<typename T>
void capitalize(T &value) {
	if (std::is_same<T, char>::value) {
		if (value >= 'a' && value <= 'z') {
			value -= 32;
		}
	}
}