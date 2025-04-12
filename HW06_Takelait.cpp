#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

/******************************************************************************
 * EXERCISE 1: Print Parenthesis Number
 * For each pair of parentheses, assign a unique number. When we see '(',
 * we push an ID onto a stack; when we see ')', we pop and use the same ID.
 * Example: For the expression "((a+b)+(c+d))",
 *   indices of parentheses might be: (0='(',1='(',5=')',6='+',7='(',10=')',11=')')
 *   One possible labeling: '(' at index0 => 1, '(' at index1 => 2, ')' at index5 => 2, etc.
 * We'll print the ID for each parenthesis in the order they appear.
 ******************************************************************************/
void printParenthesisNumber(const string &expr) {
    stack<int> st;         // will hold the ID for each '('
    int currentID = 0;     // increments each time we see '('
    // We store the ID of each character (or -1 if it's not a parenthesis)
    vector<int> parenID(expr.size(), -1);

    for (int i = 0; i < (int)expr.size(); i++) {
        if (expr[i] == '(') {
            currentID++;
            st.push(currentID);
            parenID[i] = currentID;
        }
        else if (expr[i] == ')') {
            if (!st.empty()) {
                int topID = st.top();
                st.pop();
                parenID[i] = topID;
            }
        }
        // else ignore non-parenthesis characters
    }

    // Print only the IDs for the parentheses, in the order they appear
    cout << "Parenthesis IDs: ";
    for (int i = 0; i < (int)expr.size(); i++) {
        if (parenID[i] != -1) {
            cout << parenID[i] << " ";
        }
    }
    cout << "\n";
}

/******************************************************************************
 * EXERCISE 2: Stock Analysis
 * We have stock prices given in reverse order (most recent first).
 * A "shock pivot point" is any price that is greater than its previous two prices
 * (in normal chronological order).
 * Steps:
 *  1) Reverse the reversed list to get the correct chronological order.
 *  2) For i >= 2, check if price[i] > price[i-1] and price[i] > price[i-2].
 *  3) Print those pivot points (or do whatever analysis is needed).
 ******************************************************************************/
void stockAnalysis(const vector<int> &reversedPrices) {
    // 1) Reverse them to get chronological order
    vector<int> normalOrder = reversedPrices;
    reverse(normalOrder.begin(), normalOrder.end());

    // 2) Identify shock pivot points
    //    A pivot at index i if normalOrder[i] > normalOrder[i-1]
    //    and normalOrder[i] > normalOrder[i-2].
    cout << "Shock pivot points (chronological order): ";
    for (int i = 2; i < (int)normalOrder.size(); i++) {
        if (normalOrder[i] > normalOrder[i-1] &&
            normalOrder[i] > normalOrder[i-2]) {
            cout << normalOrder[i] << " ";
        }
    }
    cout << "\n";
}

/******************************************************************************
 * EXERCISE 3: Palindrome Check using a Stack
 * A palindrome reads the same forwards and backwards.
 * We push all characters on a stack, then pop and compare with original.
 ******************************************************************************/
bool isPalindromeStack(const string &s) {
    stack<char> st;
    // Push every character onto the stack
    for (char c : s) {
        st.push(c);
    }

    // Now pop and compare
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] != st.top()) {
            return false;
        }
        st.pop();
    }
    return true;
}

/******************************************************************************
 * EXERCISE 4: Prefix to Infix Conversion
 * Example: prefix = "*-AB-CD"
 * Steps:
 *   - Read from right to left.
 *   - If operand, push it (as a string) on stack.
 *   - If operator, pop top two strings -> left, right, combine => "(left op right)"
 *   - Push combined string back.
 *   - End: top of stack is the infix expression.
 * For '*-AB-CD':
 *   => "((A-B)*(C-D))"
 ******************************************************************************/
bool isOperator(char c) {
    // For simplicity, let's assume +, -, *, / are the only operators
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string prefixToInfix(const string &prefix) {
    stack<string> st;
    // Read from right to left
    for (int i = prefix.size() - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isOperator(c)) {
            // pop two items
            if (!st.empty()) {
                string left = st.top();
                st.pop();
                if (!st.empty()) {
                    string right = st.top();
                    st.pop();
                    // combine
                    string combined = "(" + left + c + right + ")";
                    st.push(combined);
                }
            }
        } else {
            // operand => push as string
            // (we assume single-letter operands)
            string op(1, c);
            st.push(op);
        }
    }

    // At the end, top of stack is the result
    return st.empty() ? "" : st.top();
}


int main() {
    // 1) Print Parenthesis Number
    cout << "EXERCISE 1: Print Parenthesis Number\n";
    string expr = "((a+b)+(c+d))";
    cout << "Expression: " << expr << "\n";
    printParenthesisNumber(expr);
    cout << "\n";

    // 2) Stock Analysis
    cout << "EXERCISE 2: Stock Analysis (Shock Pivot Points)\n";
    // Reversed prices: most recent first
    vector<int> reversedPrices = {50, 20, 39, 45, 39, 20, 21, 19, 20};
    cout << "Reversed prices = [50, 20, 39, 45, 39, 20, 21, 19, 20]\n";
    stockAnalysis(reversedPrices);
    cout << "\n";

    // 3) Palindrome Check using a Stack
    cout << "EXERCISE 3: Palindrome Check\n";
    vector<string> testStrings = {"AAABBCCCBBAAA", "ABA", "ABBA", "ABC"};
    for (auto &str : testStrings) {
        bool isPal = isPalindromeStack(str);
        cout << "String \"" << str << "\" => "
             << (isPal ? "Palindrome" : "Not Palindrome") << "\n";
    }
    cout << "\n";

    // 4) Prefix to Infix Conversion
    cout << "EXERCISE 4: Prefix to Infix\n";
    string prefixExpr = "*-AB-CD"; 
    cout << "Prefix: " << prefixExpr << "\n";
    string infix = prefixToInfix(prefixExpr);
    cout << "Infix:  " << infix << "\n";

    return 0;
}
