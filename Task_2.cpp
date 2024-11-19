#include <iostream>
#include <stack> // Include stack from STL
using namespace std;

// Function to reverse a string using a stack
string reverseStringUsingStack(const string& input) {
    stack<char> charStack; // Create a stack to store characters
    string reversedString;

    // Push each character of the string onto the stack
    for (char ch : input) {
        charStack.push(ch);
    }

    // Pop characters from the stack to reverse the string
    while (!charStack.empty()) {
        reversedString += charStack.top();
        charStack.pop();
    }

    return reversedString;
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str); // Get the string from the user

    string reversedStr = reverseStringUsingStack(str);

    cout << "Original string: " << str << endl;
    cout << "Reversed string: " << reversedStr << endl;

    return 0;
}
