#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool is_terminal(char symbol) {
    return islower(symbol) && isalpha(symbol);
}

bool is_non_terminal(char symbol) {
    return isupper(symbol) && isalpha(symbol);
}

bool is_valid_type_3(const string& input) {
    for (char symbol : input) {
        if (!is_terminal(symbol) && !is_non_terminal(symbol) && symbol != ' ')
            return false;
    }
    return true;
}

bool is_valid_type_2(const string& input) {
    bool has_non_terminal = false;
    bool has_terminal = false;
    for (char symbol : input) {
        if (is_terminal(symbol)) {
            has_terminal = true;
        } else if (is_non_terminal(symbol)) {
            has_non_terminal = true;
        } else if (symbol != ' ') {
            return false;
        }
    }
    return has_terminal && has_non_terminal;
}

bool is_valid_type_1(const string& input) {
    bool is_lhs = true;
    bool has_arrow = false;
    bool has_non_terminal = false;
    for (char symbol : input) {
        if (is_lhs) {
            if (is_non_terminal(symbol)) {
                is_lhs = false;
                has_arrow = false;
                has_non_terminal = true;
            } else if (symbol == '-' && has_arrow) {
                return false;
            } else if (symbol == '-' && !has_arrow) {
                has_arrow = true;
            } else if (symbol == '>') {
                return false;
            }
        } else {
            if (symbol == '-' || symbol == '>') {
                return false;
            } else if (symbol != ' ' && !is_terminal(symbol) && !is_non_terminal(symbol)) {
                return false;
            }
        }
    }
    return has_non_terminal;
}

bool is_valid_type_0(const string& input) {
    for (char symbol : input) {
        if (symbol == '-' || symbol == '>')
            return true;
    }
    return false;
}

int main() {
    string input;
    cout << "Enter the string to check: ";
    getline(cin, input);

    if (is_valid_type_0(input)) {
        cout << "The string belongs to a Type-0 Unrestricted Grammar.\n";
    } else if (is_valid_type_1(input)) {
        cout << "The string belongs to a Type-1 Context-Sensitive Grammar.\n";
    } else if (is_valid_type_2(input)) {
        cout << "The string belongs to a Type-2 Context-Free Grammar.\n";
    } else if (is_valid_type_3(input)) {
        cout << "The string belongs to a Type-3 Regular Grammar.\n";
    } else {
        cout << "The string does not belong to any known type of grammar.\n";
    }

    return 0;
}
