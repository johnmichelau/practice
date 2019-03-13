#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

int solution(string &S) {
    stack<char> expected;

    for (unsigned int i = 0; i < S.length(); i++) {
        char c = S.at(i);
        switch (c) {
            case '(':
                expected.push(')');
                break;
            case '[':
                expected.push(']');
                break;
            case '{':
                expected.push('}');
                break;
            default:
                if (expected.size() > 0) {
                    char expectedC = expected.top();
                    expected.pop();

                    if (c != expectedC) {
                        return 0;
                    }
                } else {
                    return 0;
                }
        }
    }

    return expected.size() == 0 ? 1 : 0;
}

int main() {

    cout << "Enter a string of parens/brackets: ";
    string input;
    cin >> input;
    int output = solution(input);
    cout << "Result: " << output << endl;

    return 0;
}