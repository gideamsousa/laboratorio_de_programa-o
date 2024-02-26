#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    cout << "Digite uma string: ";
    string input;
    getline(cin, input);

    for (char &c : input) {
        if (islower(c)) {
            c = toupper(c);
        } else if (isdigit(c)) {
            int num = c - '0';
            c = '0' + static_cast<char>(sqrt(num));
        }
    }
    
    cout << "String modificada: " << input << endl;

    return 0;
}
