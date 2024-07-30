#include "Span.hpp"

Span::Span(uint32_t n) : _n(n), _shortestSpan(std::numeric_limits<int>::max()), _longestSpan(0) {
}


Span::Span(const Span &copy) {
	(void)copy;
}

Span& Span::operator=(const Span &rhs) {
	(void)rhs;
	return *this;
}

Span::~Span() {
}

// === V2 ===
void Span::addNumber(int n) {
	if (_v.size() >= _n)
		throw SpanException("Span is full");
	
	if (!_v.empty()) {
		int minDiff = std::numeric_limits<int>::max();
		for (int val : _v) {
			int diff = std::abs(val - n);
			if (diff < minDiff)
				minDiff = diff;
		}
		if (minDiff < _shortestSpan) {
			_shortestSpan = minDiff;
		}
		int maxVal = *std::max_element(_v.begin(), _v.end());
		int minVal = *std::min_element(_v.begin(), _v.end());
		_longestSpan = std::max({ _longestSpan, std::abs(n - maxVal), std::abs(n - minVal) });
	}

	_v.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (_v.size() + std::distance(begin, end) > _n)
		throw SpanException("Span is full");

	for (auto it = begin; it != end; ++it) {
		addNumber(*it);
	}
}

// === V1 ===
// void Span::addNumber(int n) {
//     if (_v.size() >= _n)
//         throw SpanException("Span is full");
//     _v.push_back(n);
// }

// void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
//     if (_v.size() + std::distance(begin, end) > _n)
//         throw SpanException("Span is full");
//     _v.insert(_v.end(), begin, end);
// }


// === V2 ===
int Span::shortestSpan() {
	if (_v.size() < 2)
		throw SpanException("Span is too short");
	return _shortestSpan;
}

int Span::longestSpan() {
	if (_v.size() < 2)
		throw SpanException("Span is too short");
	return _longestSpan;
}

// === V1 ===
// int Span::shortestSpan() {
//     if (_v.size() < 2)
//         throw SpanException("Span is too short");
//     std::sort(_v.begin(), _v.end());
//     int min = _v[1] - _v[0];
//     for (size_t i = 2; i < _v.size(); i++) {
//         if (_v[i] - _v[i - 1] < min)
//             min = _v[i] - _v[i - 1];
//     }
//     return min;
// }

// int Span::longestSpan() {
//     if (_v.size() < 2)
//         throw SpanException("Span is too short");
//     std::sort(_v.begin(), _v.end());
//     return _v.back() - _v.front();
// }