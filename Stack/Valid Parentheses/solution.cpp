#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValid(string s) {
    stack<char> char_stack;
    unordered_map<char, char> bracket_map = {{')', '('}, {'}', '{'}, {']', '['}};

    for(char c: s) {
        if(c == '(' || c == '{' || c == '[') {
            char_stack.push(c);
        } else {
            if(char_stack.empty() || bracket_map[c] != char_stack.top()) {
                return false;
            } else {
                char_stack.pop();
            }
        }
    }
    if(!char_stack.empty()) return false;
    return true;
}

int main() {
    string s;
    cout << "Enter a string of brackets: ";
    cin >> s;

    if(isValid(s)) {
        cout << "Valid" << endl;
    } else {
        cout << "Invalid" << endl;
    }

    return 0;
}
