#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Function to find the second largest element with minimum comparisons
int findSecondLargest(const vector<int>& arr) {
    int first = numeric_limits<int>::min(), second = numeric_limits<int>::min();
    for (int num : arr) {
        if (num > first) {
            second = first;
            first = num;
        } else if (num > second && num != first) {
            second = num;
        }
    }
    return second;
}

// Function to find the first repeated element
int findFirstRepeated(const vector<int>& arr) {
    unordered_set<int> seen;
    for (int num : arr) {
        if (seen.count(num)) return num;
        seen.insert(num);
    }
    return -1; // No repetition found
}

// Function to find the sum of distinct elements
int sumDistinct(const vector<int>& arr) {
    unordered_set<int> uniqueElements(arr.begin(), arr.end());
    int sum = 0;
    for (int num : uniqueElements) {
        sum += num;
    }
    return sum;
}

// Function to separate positive and negative numbers
void separateNumbers(vector<int>& arr) {
    vector<int> positive, negative;
    for (int num : arr) {
        if (num >= 0) positive.push_back(num);
        else negative.push_back(num);
    }
    cout << "Positive numbers: ";
    for (int num : positive) cout << num << " ";
    cout << "\nNegative numbers: ";
    for (int num : negative) cout << num << " ";
    cout << endl;
}

// Function to find or insert a number in a sorted list
void findOrInsert(vector<int>& arr, int target) {
    auto it = lower_bound(arr.begin(), arr.end(), target);
    if (it != arr.end() && *it == target) {
        cout << "Found at index: " << distance(arr.begin(), it) << endl;
    } else {
        arr.insert(it, target);
        cout << "Inserted at index: " << distance(arr.begin(), it) << endl;
    }
}

int main() {
    vector<int> arr1 = {12, 35, 1, 10, 34, 1};
    cout << "Second Largest: " << findSecondLargest(arr1) << endl;

    vector<int> arr2 = {1, 2, 4, 5, 6, 3, 7, 2, 4, 6, 7};
    cout << "First Repeated: " << findFirstRepeated(arr2) << endl;

    vector<int> arr3 = {1, 2, 3, 2, 4, 3, 5, 6, 7, 7, 2, 4};
    cout << "Sum of Distinct Elements: " << sumDistinct(arr3) << endl;

    vector<int> arr4 = {1, -3, 2, -5, 6, -7, 4};
    separateNumbers(arr4);

    vector<int> arr5 = {1, 3, 5, 7, 9, 11, 12, 13, 35, 67};
    findOrInsert(arr5, 14);
    return 0;
}
