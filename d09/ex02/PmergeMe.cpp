#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av) {
    parseInput(ac, av);
}

void PmergeMe::sortAndPrint() {
    printUnsortedSequence();
    sortUsingVector();
    sortUsingDeque();
    printSortedSequence();
    printTimingInformation();
}

void PmergeMe::parseInput(int ac, char **av) {
    for (int i = 1; i < ac; ++i) {
        int num;
        try {
            num = std::stoi(av[i]); // todo ask if it displays the throw
            if (num < 0) throw std::invalid_argument("Non-positive integer");
        } catch (const std::invalid_argument &e) {
            std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
            exit(EXIT_FAILURE);
        } catch (...) {
            std::cerr << RED << "Error" << RESET << std::endl;
            exit(EXIT_FAILURE);
        }
        _numbers.push_back(num);
    }
}

void PmergeMe::printUnsortedSequence() {
    std::cout << BLUE << "Before: " << RESET;
    printContainer(_numbers);
}

void PmergeMe::sortUsingVector() {
    _sortedVector = _numbers;
    auto start = std::chrono::high_resolution_clock::now();
    fordJohnsonSort(_sortedVector);
    auto end = std::chrono::high_resolution_clock::now();
   _vectorDuration = end - start;
}

void PmergeMe::sortUsingDeque() {
    _sortedDeque = std::deque<int>(_numbers.begin(), _numbers.end());
    auto start = std::chrono::high_resolution_clock::now();
    fordJohnsonSort(_sortedDeque);
    auto end = std::chrono::high_resolution_clock::now();
    _dequeDuration = end - start;
}

void PmergeMe::printSortedSequence() {
    std::cout << TEAL << "After: " << RESET;
    printContainer(_sortedVector);
    // printContainer(_sortedDeque);
}

void PmergeMe::printTimingInformation() {
    std::cout << GREEN << "Time to process a range of " << RESET << _numbers.size() << GREEN << " elements with std::vector: " << _vectorDuration.count() << " µs" << std::endl;
    std::cout << GREEN << "Time to process a range of " << RESET << _numbers.size() << GREEN << " elements with std::deque:  " << _dequeDuration.count() << " µs" << std::endl;
}

void PmergeMe::fordJohnsonSort(std::vector<int> &vec) {
    // Base case: if the vector has 1 or 0 elements, it's already sorted
    if (vec.size() <= 1) {
        return;
    }

    std::vector<int> firstElements;
    std::vector<int> secondElements;

    // Pairing and sorting pairs
    // Iterate through the vector in pairs
    for (size_t i = 0; i + 1 < vec.size(); i += 2) {
        // Compare each pair and store the smaller element in firstElements
        // and the larger element in secondElements
        if (vec[i] > vec[i + 1]) {
            firstElements.push_back(vec[i + 1]);
            secondElements.push_back(vec[i]);
        } else {
            firstElements.push_back(vec[i]);
            secondElements.push_back(vec[i + 1]);
        }
    }
    
    // Handle the case where the vector has an odd number of elements
    if (vec.size() % 2 != 0) {
        firstElements.push_back(vec.back());
    }

    // Recursively sort the first elements of each pair
    fordJohnsonSort(firstElements);

    // Merge the sorted first elements with the second elements
    for (const int& elem : secondElements) {
        // Find the position where the element should be inserted
        auto pos = std::upper_bound(firstElements.begin(), firstElements.end(), elem);
        // Insert the element at the found position
        firstElements.insert(pos, elem);
    }

    // Replace the original vector with the sorted list
    vec = firstElements;
}

void PmergeMe::fordJohnsonSort(std::deque<int>& deq) {
    if (deq.size() <= 1) {
        return;
    }

    std::deque<int> firstElements;
    std::deque<int> secondElements;

    for (size_t i = 0; i + 1 < deq.size(); i += 2) {
        if (deq[i] > deq[i + 1]) {
            firstElements.push_back(deq[i + 1]);
            secondElements.push_back(deq[i]);
        } else {
            firstElements.push_back(deq[i]);
            secondElements.push_back(deq[i + 1]);
        }
    }

    if (deq.size() % 2 != 0) {
        firstElements.push_back(deq.back());
    }

    fordJohnsonSort(firstElements);

    for (const int& elem : secondElements) {
        auto pos = std::upper_bound(firstElements.begin(), firstElements.end(), elem);
        firstElements.insert(pos, elem);
    }
    
    deq = firstElements;
}