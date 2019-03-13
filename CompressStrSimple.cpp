#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string solution(string s) {

    cout << "Processing " << s << endl;

    if (s.length() <= 1) {
        return s;
    }

    string o;

    int count = 1;

    for (int i = 0; i < s.length(); i++) {
        //cout << "i = " << i << endl;
        //cout << "char: " << s.at(i) << endl;

        if ((i + 1) == s.length() || s.at(i) != s.at(i+1)) {
            //cout << "Appending " + s.at(i) << endl;
            o.append(1, s.at(i));
            //cout << "size: " << to_string(count) << endl;
            o.append(to_string(count));

            count = 1;

        } else {
            count++;
        }
    }

    return o.length() < s.length() ? o : s;
}

int main() {

    cout << "Enter a string to compress: ";
    string input;
    cin >> input;
    string output = solution(input);
    cout << "Result: " << output << endl;

    return 0;
}
