#ifndef ALGO_HPP
#define ALGO_HPP


#include <vector>


void insertionSort(std::vector<int>& arr, int left, int right);
void merge(std::vector<int>& arr, int left, int mid, int right);
void timSort(std::vector<int>& arr);
void dualPivotQuickSort(std::vector<int>& arr, int low, int high);
int partition(std::vector<int>& arr, int low, int high);
void heapify(std::vector<int>& arr, int low, int high, int i);
void heapSort(std::vector<int>& arr, int low, int high);
void introsortUtil(std::vector<int>& arr, int low, int high, int depthLimit);
void introSort(std::vector<int>& arr);
bool isSorted(std::vector<int>& arr);
void partSort(std::vector<int>& arr, float percent);
void convert(std::vector<int>& arr);
double calculateAverage(const std::vector<int>& arr);
std::vector<int> generateRandom(int size);
void measure(void (*sortFunc)(std::vector<int>&), int size);
void measurePivot(void (*sortFunc)(std::vector<int>&, int low, int high), int size);


#endif

