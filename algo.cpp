#include <iostream>
#include <vector>
#include <random>

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

bool isSorted(std::vector<int>& arr) {
    for(size_t i = 1; i < arr.size(); i++) {
        if(arr[i] < arr[i - 1])
            return false;
    }
    return true;
}

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
}