#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <climits>

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

// Exercise 1: Find 2nd largest with minimum comparisons
void exercise1() {
    vector<int> arr = {12, 35, 1, 10, 34, 1};
    cout << "Exercise 1: 2nd Largest" << endl;
    cout << "Input array: ";
    printArray(arr);

    if (arr.size() < 2) {
        cout << "Invalid input!" << endl;
        return;
    }

    int largest = max(arr[0], arr[1]);
    int secondLargest = min(arr[0], arr[1]);

    for (size_t i = 2; i < arr.size(); ++i) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    cout << "Second largest: " << secondLargest << endl;
}

// Exercise 2: Find first repeated element
void exercise2() {
    vector<int> arr = {1, 2, 4, 5, 6, 3, 7, 2, 4, 6, 7};
    cout << "\nExercise 2: First Repeated" << endl;
    cout << "Input array: ";
    printArray(arr);

    unordered_set<int> seen;
    int result = -1;

    for (int num : arr) {
        if (seen.count(num)) {
            result = num;
            break;
        }
        seen.insert(num);
    }

    if (result != -1) {
        cout << "First repeated element: " << result << endl;
    } else {
        cout << "No repeated elements" << endl;
    }
}

// Exercise 3: Sum distinct (non-consecutive duplicates)
void exercise3() {
    vector<int> arr = {1, 2, 3, 2, 4, 3, 5, 6, 7, 7, 2, 4};
    cout << "\nExercise 3: Sum Distinct" << endl;
    cout << "Input array: ";
    printArray(arr);

    if (arr.empty()) {
        cout << "Sum: 0" << endl;
        return;
    }

    int sum = arr[0];
    int prev = arr[0];

    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] != prev) {
            sum += arr[i];
            prev = arr[i];
        }
    }

    cout << "Sum of distinct elements: " << sum << endl;
}

// Exercise 4: Separate negative and positive numbers
void exercise4() {
    vector<int> arr = {1, -3, 2, -5, 6, -7, 4};
    cout << "\nExercise 4: Separate Negatives" << endl;
    cout << "Input array: ";
    printArray(arr);

    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        if (arr[left] < 0 && arr[right] < 0) {
            left++;
        } else if (arr[left] >= 0 && arr[right] < 0) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        } else if (arr[left] >= 0 && arr[right] >= 0) {
            right--;
        } else {
            left++;
            right--;
        }
    }

    cout << "Separated array: ";
    printArray(arr);
}

// Exercise 5: Find or insert in sorted array
void exercise5() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 12, 13, 35, 67};
    int target = 14;
    cout << "\nExercise 5: Find or Insert" << endl;
    cout << "Input array: ";
    printArray(arr);
    cout << "Target: " << target << endl;

    auto it = lower_bound(arr.begin(), arr.end(), target);
    int index = it - arr.begin();

    if (it != arr.end() && *it == target) {
        cout << "Found at index: " << index << endl;
    } else {
        arr.insert(it, target);
        cout << "Inserted at index: " << index << endl;
        cout << "Updated array: ";
        printArray(arr);
    }
}

int main() {
    cout << "\n Fouzi Takelait\n CSCI 588\n Homework #3\n" << endl;

    exercise1();
    cout << "------------------------------------------------------" << endl;

    exercise2();
    cout << "------------------------------------------------------" << endl;

    exercise3();
    cout << "------------------------------------------------------" << endl;

    exercise4();
    cout << "------------------------------------------------------" << endl;

    exercise5();

    return 0;
}