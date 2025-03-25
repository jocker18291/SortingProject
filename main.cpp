#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include "algo.hpp"

int main() {
    int size;
    std::cout << "Enter the size of an array: ";
    std::cin >> size;

    std::vector<int> original(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 100000);
    for(int i = 0; i < size; i++) {
        original[i] = dis(gen);
    }

    std::vector<int> arrTim = original;
    std::vector<int> arrDual = original;
    std::vector<int> arrIntro = original;

    auto start = std::chrono::high_resolution_clock::now();
    timSort(arrTim);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout <<"Timsort: " << elapsed.count() << " s. Correctly sorted? " << (isSorted(arrTim) ? "Yes" : "No") << std::endl;

    start = std::chrono::high_resolution_clock::now();
    dualPivotQuickSort(arrDual, 0, arrDual.size() - 1);
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "Dual-Pivot Quicksort: " << elapsed.count() << " s. Correctly sorted? " << (isSorted(arrDual) ? "Yes" : "No") << std::endl;

    start = std::chrono::high_resolution_clock::now();
    introSort(arrIntro);
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "Introspective Sort: " << elapsed.count() << " s. Correctly sorted? " << (isSorted(arrIntro) ? "Yes" : "No") << std::endl;

    return 0;
}