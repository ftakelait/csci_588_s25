#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>

using namespace std;

// Helper function to print arrays
template<typename T>
void printArray(const vector<T>& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i != arr.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// Exercise 1: Minimum swaps to bring elements less than pivot to the front
void exercise1() {
    vector<int> arr = {7, 2, 9, 1, 6, 8, 3, 5, 12, 4, 11, 10};
    int pivot = 5;
    cout << "Exercise 1: Minimum swaps" << endl;
    cout << "Input array: ";
    printArray(arr);
    cout << "Pivot: " << pivot << endl;
    
    int swaps = 0;
    int left = 0;
    int right = arr.size() - 1;
    
    // Use two pointers to find elements to swap
    while (left < right) {
        // Find left element >= pivot
        while (left < right && arr[left] < pivot) {
            left++;
        }
        // Find right element < pivot
        while (left < right && arr[right] >= pivot) {
            right--;
        }
        if (left < right) {
            swap(arr[left], arr[right]);
            swaps++;
            left++;
            right--;
        }
    }
    
    cout << "Output: Minimum swaps = " << swaps << endl << endl;
}

// Exercise 2: Sort array based on A*X^2 (assuming A=1)
void exercise2() {
    vector<int> arr = {3, -2, 1, -4, 0};
    cout << "Exercise 2: Equation sort" << endl;
    cout << "Input array: ";
    printArray(arr);
    
    // Sort using custom comparator based on X^2
    sort(arr.begin(), arr.end(), [](int a, int b) {
        return (a * a) < (b * b);
    });
    
    cout << "Output sorted array: ";
    printArray(arr);
    cout << endl;
}

// Exercise 3: Sort 0s and 1s with 1s first
void exercise3() {
    vector<int> arr = {0, 1, 0, 1, 1, 0, 0, 1};
    cout << "Exercise 3: Sort 0s and 1s" << endl;
    cout << "Input array: ";
    printArray(arr);
    
    // Count number of 1s and fill the rest with 0s
    int ones = count(arr.begin(), arr.end(), 1);
    fill(arr.begin(), arr.begin() + ones, 1);
    fill(arr.begin() + ones, arr.end(), 0);
    
    cout << "Output sorted array: ";
    printArray(arr);
    cout << endl;
}

// Exercise 4: Sort array and find min, max, median
void exercise4() {
    vector<int> arr = {10, 3, 5, 2, 8, 7, 6};
    cout << "Exercise 4: Sort and find min, max, median" << endl;
    cout << "Input array: ";
    printArray(arr);
    
    sort(arr.begin(), arr.end());
    int min = arr.front();
    int max = arr.back();
    int median = arr[arr.size() / 2]; // For odd-sized array
    
    cout << "Output sorted array: ";
    printArray(arr);
    cout << "Min: " << min << ", Max: " << max << ", Median: " << median << endl << endl;
}

// Exercise 5: Sort priority strings using bucket sort
void exercise5() {
    vector<string> arr = {"Low", "Mid", "High", "Low", "High", "Mid", "Low", "High"};
    cout << "Exercise 5: Sort priority strings" << endl;
    cout << "Input array: ";
    printArray(arr);
    
    vector<string> high, mid, low;
    // Bucket elements by priority
    for (const string& s : arr) {
        if (s == "High") high.push_back(s);
        else if (s == "Mid") mid.push_back(s);
        else low.push_back(s);
    }
    // Concatenate buckets
    vector<string> sorted;
    sorted.insert(sorted.end(), high.begin(), high.end());
    sorted.insert(sorted.end(), mid.begin(), mid.end());
    sorted.insert(sorted.end(), low.begin(), low.end());
    
    cout << "Output sorted array: ";
    printArray(sorted);
    cout << endl;
}

// Exercise 6: Find union and intersection of two arrays
void exercise6() {
    vector<int> arr1 = {10, 23, 45, 67, 89, 12, 34, 56, 78, 90, 11, 22, 33, 44, 55};
    vector<int> arr2 = {55, 66, 77, 88, 99, 10, 22, 44, 66, 21, 43, 65, 87, 32, 54};
    
    cout << "Exercise 6: Union and Intersection" << endl;
    cout << "Input array1: ";
    printArray(arr1);
    cout << "Input array2: ";
    printArray(arr2);
    
    // Compute union
    unordered_set<int> union_set(arr1.begin(), arr1.end());
    union_set.insert(arr2.begin(), arr2.end());
    vector<int> union_vec(union_set.begin(), union_set.end());
    sort(union_vec.begin(), union_vec.end());
    
    // Compute intersection (without duplicates)
    unordered_set<int> set1(arr1.begin(), arr1.end());
    vector<int> intersection;
    for (int num : arr2) {
        if (set1.count(num)) {
            intersection.push_back(num);
            set1.erase(num); // Avoid duplicates
        }
    }
    sort(intersection.begin(), intersection.end());
    
    cout << "Output Union: ";
    printArray(union_vec);
    cout << "Output Intersection: ";
    printArray(intersection);
    cout << endl;
}

int main() {
    exercise1();
    exercise2();
    exercise3();
    exercise4();
    exercise5();
    exercise6();
    return 0;
}