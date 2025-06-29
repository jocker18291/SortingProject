#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>
#include <chrono>
#include "../include/algo.hpp"


const int RUN = 32;


void insertionSort(std::vector<int>& arr, int left, int right) {
    for(int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while(j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}


void merge(std::vector<int>& arr, int left, int mid, int right) {
    int len1 = mid - left + 1, len2 = right - mid;
    std::vector<int> leftArr(len1), rightArr(len2);
    for(int i = 0; i < len1; i++)
        leftArr[i] = arr[left + i];
    for(int i = 0; i < len2; i++)
        rightArr[i] = arr[mid + 1 + i];


    int i = 0, j = 0, k = left;
    while(i < len1 && j < len2) {
        if(leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }
    while(i < len1)
        arr[k++] = leftArr[i++];
    while(j < len2)
        arr[k++] = rightArr[j++];
}


void timSort(std::vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n; i += RUN)
        insertionSort(arr, i, std::min(i + RUN - 1, n - 1));


    for(int size = RUN; size < n; size *= 2){
        for(int left = 0; left < n; left += 2 * size) {
            int mid = std::min(left + size - 1, n - 1);
            int right = std::min(left + 2 * size - 1, n - 1);
            if(mid < right)
                merge(arr, left, mid, right);
        }
    }
}


void dualPivotQuickSort(std::vector<int>& arr, int low, int high) {
    if(low < high) {
        if(arr[low] > arr[high])
            std::swap(arr[low], arr[high]);
        int pivot1 = arr[low], pivot2 = arr[high];
        int i = low + 1, lt = low + 1, gt = high - 1;
        while(i <= gt) {
            if(arr[i] < pivot1) {
                std::swap(arr[i], arr[lt]);
                lt++;
                i++;
            }
            else if(arr[i] > pivot2) {
                std::swap(arr[i], arr[gt]);
                gt--;
            }
            else {
                i++;
            }
        }
        lt--; gt++;
        std::swap(arr[low], arr[lt]);
        std::swap(arr[high], arr[gt]);
        dualPivotQuickSort(arr, low, lt - 1);
        dualPivotQuickSort(arr, lt + 1, gt - 1);
        dualPivotQuickSort(arr, gt + 1, high);
    }
}


int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low;
    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            std::swap(arr[i], arr[j]);
            i++;
        }
    }
    std::swap(arr[i], arr[high]);
    return i;
}


void heapify(std::vector<int>& arr, int low, int high, int i) {
    int largest = i;
    int left = 2 * (i - low) + 1 + low;
    int right = 2 * (i - low) + 2 + low;
    if (left <= high && arr[left] > arr[largest])
        largest = left;
    if(right <= high && arr[right] > arr[largest])
        largest = right;
    if(largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, low, high, largest);
    }
}


void heapSort(std::vector<int>& arr, int low, int high) {
    int n = high - low + 1;
    for(int i = low + n / 2 - 1; i >= low; i--)
        heapify(arr, low, high, i);
    for(int i = high; i > low; i--) {
        std::swap(arr[low], arr[i]);
        heapify(arr, low, i - 1, low);
    }
}


void introsortUtil(std::vector<int>& arr, int low, int high, int depthLimit) {
    int size = high - low + 1;
    if(size < 16) {
        insertionSort(arr, low, high);
        return;
    }
    if(depthLimit == 0) {
        heapSort(arr, low, high);
        return;
    }
    int p = partition(arr, low, high);
    introsortUtil(arr, low, p - 1, depthLimit - 1);
    introsortUtil(arr, p + 1, high, depthLimit - 1);
}


void introSort(std::vector<int>& arr) {
    int n = arr.size();
    int depthLimit = 2 * log(n);
    introsortUtil(arr, 0, n - 1, depthLimit);
}


bool isSorted(std::vector<int>& arr) {
    for(size_t i = 1; i < arr.size(); i++) {
        if(arr[i] < arr[i - 1])
            return false;
    }
    return true;
}


void partSort(std::vector<int>& arr, float percent) {
    int n = static_cast<int>((percent / 100.0) * arr.size());


    if(n > 0 && n <= arr.size()) {
        std::sort(arr.begin(), arr.begin() + n);
    }
    else {
        std::cout << "Not valid percentage." << std::endl;
    }
}


void convert(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end(), std::greater<int>());
}


double calculateAverage(const std::vector<double>& times) {
    double sum = 0;
    for(double time : times) {
        sum += time;
    }
    return sum / times.size();
}


template <typename Func>
double measureTime(Func&& func, std::vector<int>& arr) {
    auto start = std::chrono::high_resolution_clock::now();
    func(arr);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();
}




std::vector<int> generateRandom(int size) {
    std::vector<int> original(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 100000);
    for(int i = 0; i < size; i++) {
        original[i] = dis(gen);
    }
    return original;
}


void measure(void (*sortFunc)(std::vector<int>&), int size) {
    std::vector<double> times;
    for(int i = 0; i < 100; i++) {
        std::vector<int> arr = generateRandom(size);
        partSort(arr, 100);
        times.push_back(measureTime(sortFunc, arr));
    }


    double average = calculateAverage(times);
    std::cout << "Average time: " << average << " s." << std::endl;
}


template <typename Func>
double measurePivotTime(Func&& func, std::vector<int>& arr) {
    auto start = std::chrono::high_resolution_clock::now();
    func(arr, 0, arr.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();
}


void measurePivot(void (*sortFunc)(std::vector<int>&, int low, int high), int size) {
    std::vector<double> times;
    for(int i = 0; i < 100; i++) {
        std::vector<int> arr = generateRandom(size);
        partSort(arr, 100);
        times.push_back(measurePivotTime(sortFunc, arr));
    }


    double average = calculateAverage(times);
    std::cout << "Average time: " << average << " s." << std::endl;
}

