#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int v) : val(v) {}
};

// Inserts a value into the BST.
Node* insert(Node* root, int x) {
    if (!root) return new Node(x);
    if (x < root->val) root->left = insert(root->left, x);
    else if (x > root->val) root->right = insert(root->right, x);
    return root;
}

// Searches for a value in the BST.
bool search(Node* root, int x) {
    if (!root) return false;
    if (root->val == x) return true;
    return x < root->val ? search(root->left, x) : search(root->right, x);
}

// Finds the minimum node in the BST.
Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

// Removes a node with value x from the BST.
Node* remove(Node* root, int x) {
    if (!root) return nullptr;
    if (x < root->val)
        root->left = remove(root->left, x);
    else if (x > root->val)
        root->right = remove(root->right, x);
    else {
        if (!root->left && !root->right)
            return delete root, nullptr;
        if (!root->left) {
            Node* t = root->right;
            delete root;
            return t;
        }
        if (!root->right) {
            Node* t = root->left;
            delete root;
            return t;
        }
        Node* succ = findMin(root->right);
        root->val = succ->val;
        root->right = remove(root->right, succ->val);
    }
    return root;
}

// Performs an in-order traversal, storing values in 'out'.
void inorder(Node* root, vector<int>& out) {
    if (!root) return;
    inorder(root->left, out);
    out.push_back(root->val);
    inorder(root->right, out);
}

// Returns the kth smallest element in the BST.
int kthSmallest(Node* root, int k) {
    vector<int> v;
    inorder(root, v);
    return k > 0 && k <= v.size() ? v[k - 1] : -1;
}

// Recursively collects all root-to-leaf paths.
void getPaths(Node* root, vector<int>& path, vector<vector<int>>& all) {
    if (!root) return;
    path.push_back(root->val);
    if (!root->left && !root->right)
        all.push_back(path);
    getPaths(root->left, path, all);
    getPaths(root->right, path, all);
    path.pop_back(); // Backtrack.
}

// Prints all root-to-leaf paths.
void printPaths(Node* root) {
    vector<vector<int>> paths;
    vector<int> path; // Current path (must be vector<int>).
    getPaths(root, path, paths);
    for (const auto& p : paths) {
        for (int i = 0; i < p.size(); ++i)
            cout << p[i] << (i < p.size() - 1 ? " -> " : "\n");
    }
}

// EXERCISE 1: Build BST and print all root-to-leaf paths.
void exercise1() {
    vector<int> input = {17, 29, 15, 33, 44, 43, 13, 46, 49, 18};
    Node* root = nullptr;
    for (int x : input)
        root = insert(root, x);
    cout << "Exercise 1: BST Root-to-Leaf Paths\n";
    printPaths(root);
}

// EXERCISE 2: Search for keys 44 and 92.
void exercise2() {
    vector<int> input = {17, 29, 15, 33, 44, 43, 13, 46, 49, 18};
    Node* root = nullptr;
    for (int x : input)
        root = insert(root, x);
    cout << "Exercise 2: Search in BST\n";
    cout << "Searching 44: " << (search(root, 44) ? "Found" : "Not Found") << endl;
    cout << "Searching 92: " << (search(root, 92) ? "Found" : "Not Found") << endl;
}

// EXERCISE 3: Delete node 33 and print new root-to-leaf paths.
void exercise3() {
    vector<int> input = {17, 29, 15, 33, 44, 43, 13, 46, 49, 18};
    Node* root = nullptr;
    for (int x : input)
        root = insert(root, x);
    root = remove(root, 33);
    cout << "Exercise 3: After Deleting 33\n";
    printPaths(root);
}

// EXERCISE 4: Build a new BST and return the 3rd smallest element.
void exercise4() {
    vector<int> arr = {5, 4, 7, 2, 4, 6, 8};
    Node* root = nullptr;
    for (int x : arr)
        root = insert(root, x);
    int k = 3;
    int val = kthSmallest(root, k);
    cout << "Exercise 4: 3rd Smallest Element in BST: " << val << endl;
}

int main() {
    cout << "\nFouzi Takelait\nCSCI 588\nHomework #3\n" << endl;
    exercise1();
    cout << "------------------------------------------------------------------------------------------------------------\n";
    exercise2();
    cout << "------------------------------------------------------------------------------------------------------------\n";
    exercise3();
    cout << "------------------------------------------------------------------------------------------------------------\n";
    exercise4();
    return 0;
}
