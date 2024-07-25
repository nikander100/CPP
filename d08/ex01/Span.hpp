#pragma once

#include <algorithm>
#include <vector>
#include <string>
#include <exception>
#include <limits>

class Span {
	public:
		Span(uint32_t n);
		Span(const Span &src);
		virtual ~Span();

		Span &operator=(const Span &rhs);

		void addNumber(int n);
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan();
		int longestSpan();

		class SpanException : public std::exception {
		public:
			SpanException(std::string const &msg) : _msg(msg) {}
			~SpanException() override = default;
			const char *what() const noexcept override { return _msg.c_str(); }
		private:
			std::string _msg;
		};

	private:
		uint32_t _n;
		std::vector<int> _v;
		int _shortestSpan;
		int _longestSpan;
		Span();
};