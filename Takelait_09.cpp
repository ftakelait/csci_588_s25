#include <iostream>
#include <vector>
using namespace std;

int fibonacciSearch(vector<int>& arr, int x) {
    int n = arr.size();
    int fib2 = 0;          // (m-2)th Fibonacci
    int fib1 = 1;          // (m-1)th Fibonacci
    int fib = fib1 + fib2; // mth Fibonacci

    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    int offset = -1;
    while (fib > 1) {
        int i = min(offset + fib2, n - 1);
        if (arr[i] < x) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        } else if (arr[i] > x) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        } else return i;
    }
    if (fib1 && arr[offset + 1] == x) return offset + 1;
    return -1;
}

int main() {
    vector<int> arr = {10, 22, 35, 40, 45, 50, 55, 70, 80, 82, 85, 90};
    int target = 55;
    int index = fibonacciSearch(arr, target);
    if (index != -1) cout << "Found at index " << index << endl;
    else cout << "Element not found." << endl;
    return 0;
}