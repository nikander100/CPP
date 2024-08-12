#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <chrono>
#include <iterator>
#include <sstream>

#define RESET "\033[0m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define BRIGHTRED "\033[31m"
#define TEAL "\033[36m"
#define BLUE "\033[1;34m"

class PmergeMe {
    public:
        PmergeMe(int ac, char **av);

        void sortAndPrint();
    
    private:
        std::vector<int> _numbers;
        std::vector<int> _sortedVector;
        std::deque<int> _sortedDeque;
        std::chrono::duration<double, std::micro> _vectorDuration;
        std::chrono::duration<double, std::micro> _dequeDuration;

        void parseInput(int ac, char **av);
        void printUnsortedSequence();
        void sortUsingVector();
        void sortUsingDeque();
        void printSortedSequence();
        void printTimingInformation();

        template <typename T>
        void printContainer(const T &container) {
        for (const auto &elem : container) {
            std::cout << elem << " ";
            }
            std::cout << std::endl;
        }

        void fordJohnsonSort(std::vector<int> &vec);

        void fordJohnsonSort(std::deque<int> &deq);
};