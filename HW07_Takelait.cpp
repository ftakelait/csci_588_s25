#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Problem 1: Count islands with at least one 2x2 block of 1s
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Problem 1: Count islands with at least one 2x2 block of 1s
// DFS to mark all connected cells of land (grid[r][c] == 1)
void dfsIsland(const vector<vector<int>> &grid,
               vector<vector<bool>> &visited,
               int r, int c)
{
    static int dr[4] = {-1, 1, 0, 0}; // up/down
    static int dc[4] = {0, 0, -1, 1}; // left/right

    visited[r][c] = true;
    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        // Check boundaries
        if(nr >= 0 && nr < 8 && nc >= 0 && nc < 8) {
            // If it's land and not visited, continue DFS
            if(grid[nr][nc] == 1 && !visited[nr][nc]) {
                dfsIsland(grid, visited, nr, nc);
            }
        }
    }
}

// Counts the number of islands in an 8×8 grid of 0s and 1s
int countIslands(const vector<vector<int>> &grid) {
    vector<vector<bool>> visited(8, vector<bool>(8, false));
    int islandCount = 0;

    // Scan every cell
    for(int r = 0; r < 8; r++) {
        for(int c = 0; c < 8; c++) {
            // If it's land (1) and not visited
            if(grid[r][c] == 1 && !visited[r][c]) {
                islandCount++;
                dfsIsland(grid, visited, r, c);
            }
        }
    }
    return islandCount;
}

// Problem 2: Convert X to Y using multiply by 2 or subtract 1
vector<int> findPath(int X, int Y) {
    if (X == Y) return {X};
    queue<int> q;
    unordered_map<int, int> parent;
    q.push(X);
    parent[X] = -1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        vector<int> nexts = {curr * 2, curr - 1};
        for (int next : nexts) {
            if (parent.find(next) == parent.end() && next >= 0) {
                parent[next] = curr;
                q.push(next);
                if (next == Y) {
                    // Backtrack to find path
                    vector<int> path;
                    int node = Y;
                    while (node != -1) {
                        path.push_back(node);
                        node = parent[node];
                    }
                    reverse(path.begin(), path.end());
                    return path;
                }
            }
        }
    }
    return {};
}

// Problem 3: Minimum of maximum values in sliding windows
int minOfMaxSlidingWindow(const vector<int>& arr, int k) {
    vector<int> maxValues;
    for (int i = 0; i <= arr.size() - k; ++i) {
        int currentMax = arr[i];
        for (int j = i; j < i + k; ++j) {
            currentMax = max(currentMax, arr[j]);
        }
        maxValues.push_back(currentMax);
    }
    return *min_element(maxValues.begin(), maxValues.end());
}

// Problem 4: First negative in sliding windows
vector<int> firstNegativeSlidingWindow(const vector<int>& arr, int k) {
    vector<int> result;
    for (int i = 0; i <= arr.size() - k; ++i) {
        bool found = false;
        for (int j = i; j < i + k; ++j) {
            if (arr[j] < 0) {
                result.push_back(arr[j]);
                found = true;
                break;
            }
        }
        if (!found) result.push_back(0);
    }
    return result;
}

int main() {
    // Problem 1
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0, 1, 1, 0},
        {1, 1, 0, 0, 0, 1, 1, 0},
        {0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 1, 1},
        {1, 0, 0, 1, 1, 0, 1, 0}, // Corrected to 8 elements
        {1, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 1, 1},
        {0, 0, 1, 1, 0, 1, 1, 0}  // Corrected to 8 elements
    };

    cout << "Problem 1: " << countIslands(grid) << endl;

    // Problem 2
    int X = 5, Y = 27;
    vector<int> path = findPath(X, Y);
    cout << "Problem 2: Steps: " << (path.size() - 1) << ", Path: [";
    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i < path.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    // Problem 3
    vector<int> arr3 = {11, 2, 75, 92, 59, 90, 55};
    int k3 = 3;
    cout << "Problem 3: " << minOfMaxSlidingWindow(arr3, k3) << endl;

    // Problem 4
    vector<int> arr4 = {13, -2, -6, 10, -14, 50, 14, 21};
    int k4 = 3;
    vector<int> negatives = firstNegativeSlidingWindow(arr4, k4);
    cout << "Problem 4: [";
    for (size_t i = 0; i < negatives.size(); ++i) {
        cout << negatives[i];
        if (i < negatives.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}