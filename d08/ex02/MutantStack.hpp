#pragma once

#include <algorithm>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T>> {
	public:

	typedef typename std::deque<T>::iterator iterator;

	iterator begin() { 
		return c.begin();
		}

	iterator end() { 
		return c.end();
	}

	void clear() {
		c.clear();
	}
};