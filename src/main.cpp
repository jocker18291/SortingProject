#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include "../include/algo.hpp"


int main() {
    int size;
    float percent;
    std::cout << "Enter the size of an array: ";
    std::cin >> size;
    // std::cout << "Enter the percentage: ";
    // std::cin >> percent;


    std::vector<int> original(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 100000);
    for(int i = 0; i < size; i++) {
        original[i] = dis(gen);
    }


    // std::vector<int> arrTim = original;
    // std::vector<int> arrDual = original;
    // std::vector<int> arrIntro = original;


    // auto start = std::chrono::high_resolution_clock::now();
    // timSort(arrTim);
    // auto end = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> elapsed = end - start;
    // std::cout <<"Timsort: " << elapsed.count() << " s. Correctly sorted? " << (isSorted(arrTim) ? "Yes" : "No") << std::endl;


    // start = std::chrono::high_resolution_clock::now();
    // dualPivotQuickSort(arrDual, 0, arrDual.size() - 1);
    // end = std::chrono::high_resolution_clock::now();
    // elapsed = end - start;
    // std::cout << "Dual-Pivot Quicksort: " << elapsed.count() << " s. Correctly sorted? " << (isSorted(arrDual) ? "Yes" : "No") << std::endl;


    // start = std::chrono::high_resolution_clock::now();
    // introSort(arrIntro);
    // end = std::chrono::high_resolution_clock::now();
    // elapsed = end - start;
    // std::cout << "Introspective Sort: " << elapsed.count() << " s. Correctly sorted? " << (isSorted(arrIntro) ? "Yes" : "No") << std::endl;


    // std::vector<int> arrTimPart = original;
    // std::vector<int> arrDualPart = original;
    // std::vector<int> arrIntroPart = original;


    // partSort(arrTimPart, percent);
    // partSort(arrDualPart, percent);
    // partSort(arrIntroPart, percent);


    // std::cout << std::endl;


    // start = std::chrono::high_resolution_clock::now();
    // timSort(arrTimPart);
    // end = std::chrono::high_resolution_clock::now();
    // elapsed = end - start;
    // std::cout << "Timsort at " << percent << "%: " << elapsed.count() << " s. Correctly sorted? " << (isSorted(arrTimPart) ? "Yes" : "No") << std::endl;


    // start = std::chrono::high_resolution_clock::now();
    // dualPivotQuickSort(arrDualPart, 0, arrDualPart.size() - 1);
    // end = std::chrono::high_resolution_clock::now();
    // elapsed = end - start;
    // std::cout << "Dual-Pivot Quicksort at " << percent << "%: " << elapsed.count() << " s. Correctly sorted? " << (isSorted(arrTimPart) ? "Yes" : "No") << std::endl;


    // start = std::chrono::high_resolution_clock::now();
    // introSort(arrIntroPart);
    // end = std::chrono::high_resolution_clock::now();
    // elapsed = end - start;
    // std::cout << "Introspective Sort at " << percent << "%: " << elapsed.count() << " s. Correctly sorted? " << (isSorted(arrTimPart) ? "Yes" : "No") << std::endl;


    // std::vector<int> arrTimGt = original;
    // std::vector<int> arrDualGt = original;
    // std::vector<int> arrIntroGt = original;


    // convert(arrTimGt);
    // convert(arrDualGt);
    // convert(arrIntroGt);


    // std::cout << std::endl;


    // start = std::chrono::high_resolution_clock::now();
    // timSort(arrTimGt);
    // end = std::chrono::high_resolution_clock::now();
    // elapsed = end - start;
    // std::cout << "Timsort: " << elapsed.count() << " s. Correctly sorted? " << (isSorted(arrTimGt) ? "Yes" : "No") << std::endl;


    // start = std::chrono::high_resolution_clock::now();
    // dualPivotQuickSort(arrDualGt, 0, arrDualGt.size() - 1);
    // end = std::chrono::high_resolution_clock::now();
    // elapsed = end - start;
    // std::cout << "Dual-Pivot Quicksort: " << elapsed.count() << " s. Correctly sorted? " << (isSorted(arrDualGt) ? "Yes" : "No") << std::endl;


    // start = std::chrono::high_resolution_clock::now();
    // introSort(arrIntroGt);
    // end = std::chrono::high_resolution_clock::now();
    // elapsed = end - start;
    // std::cout << "Introspective Sort: " << elapsed.count() << " s. Correctly sorted? " << (isSorted(arrIntroGt) ? "Yes" : "No") << std::endl;




    std::cout << "Timsort statistics: " << std::endl;
    measure(timSort, size);


    std::cout << "Introspective Sort statistics: " << std::endl;
    measure(introSort, size);
   
    // std::cout << "Dual-Pivot Quicksort statistics: " << std::endl;
    // measurePivot(dualPivotQuickSort, size);


    return 0;
}

