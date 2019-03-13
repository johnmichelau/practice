#include <iostream>
#include <sstream>

using namespace std;

int solution(string &S) {

    int nestLevel = 0;

    for (unsigned int i = 0; i < S.length(); i++) {
        switch (S.at(i)) {
            case '(':
                nestLevel++;
                break;
            case ')':
                if (nestLevel <= 0) {
                    return 0;
                }
                nestLevel--;
                break;
            default:
                ostringstream err;
                err << "Not a valid char: " << S.at(i);
                throw invalid_argument(err.str());
        }
    }

    return nestLevel == 0 ? 1 : 0;
}

int main() {

    cout << "Enter a string of parens: ";
    string input;
    cin >> input;
    int output = solution(input);
    cout << "Result: " << output << endl;

    return 0;
}