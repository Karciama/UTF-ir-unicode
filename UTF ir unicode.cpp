#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "");

    int skaicius;
    char symbol;

    if (argc > 1) {
        skaicius = atoi(argv[1]);
    }
    else {
        cout << "skaicius: ";
        cin >> skaicius;
    }
    symbol = skaicius;

    cout << "Unicode: " << "U+" << setfill('0') << setw(4) << hex << skaicius << endl;

    cout << "UTF-8: ";
    if (skaicius <= 127)
    {
        cout << setw(2) << hex << skaicius << endl;
    }
    else if (skaicius <= 2047)
    {
        cout << setw(2) << hex << ((skaicius >> 6) | 0b11000000) << ' ';
        cout << setw(2) << hex << ((skaicius & 0b00111111) | 0b10000000) << endl;
    }
    else if (skaicius <= 65535)
    {
        cout << setw(2) << hex << ((skaicius >> 12) | 0b11100000) << ' ';
        cout << setw(2) << hex << (((skaicius >> 6) & 0b00111111) | 0b10000000) << ' ';
        cout << setw(2) << hex << ((skaicius & 0b00111111) | 0b10000000) << endl;
    }
    else if (skaicius <= 1114111)
    {
        cout << setw(2) << hex << ((skaicius >> 18) | 0b11110000) << ' ';
        cout << setw(2) << hex << (((skaicius >> 12) & 0b00111111) | 0b10000000) << ' ';
        cout << setw(2) << hex << (((skaicius >> 6) & 0b00111111) | 0b10000000) << ' ';
        cout << setw(2) << hex << ((skaicius & 0b00111111) | 0b10000000) << endl;
    }
    cout << "Char: " << symbol;

    return 0;
}
