#include <iostream>
#include <vector>

using namespace std;

bool is_terminal(char symbol) {
    return symbol >= 'a' && symbol <= 'z';
}

bool is_non_terminal(char symbol) {
    return symbol >= 'A' && symbol <= 'Z';
}

bool is_valid_grammar(const vector<string>& productions) {
    for (const auto& production : productions) {
        bool lhs = true;
        for (char symbol : production) {
            if (lhs) {
                if (!is_non_terminal(symbol))
                    return false;
                lhs = false;
            } else if (symbol != '-' && symbol != '>' && symbol != '|' &&
                       !is_terminal(symbol) && !is_non_terminal(symbol) && symbol != 'ε') {
                return false;
            }
        }
    }
    return true;
}

string identify_grammar_type(const vector<string>& productions) {
    if (!is_valid_grammar(productions))
        return "Invalid Grammar";

    bool has_start_symbol = false;
    bool is_regular = true;

    for (const auto& production : productions) {
        bool has_terminal = false;
        bool has_non_terminal = false;

        for (char symbol : production) {
            if (is_terminal(symbol)) {
                has_terminal = true;
            } else if (is_non_terminal(symbol)) {
                has_non_terminal = true;
            }
        }

        if (production[0] == 'S')
            has_start_symbol = true;

        if (!has_terminal || has_non_terminal) {
            is_regular = false;
            break;
        }
    }

    if (has_start_symbol) {
        if (is_regular)
            return "Type-3 Regular Grammar";
        return "Type-2 Context-Free Grammar";
    } else {
        return "Type-1 Context-Sensitive Grammar";
    }
}

int main() {
    vector<string> productions;
    int num_productions;

    cout << "Enter the number of productions: ";
    cin >> num_productions;
    cin.ignore(); // Consume newline

    cout << "Enter the productions of the grammar (separated by newline):\n";
    for (int i = 0; i < num_productions; i++) {
        string production;
        getline(cin, production);
        productions.push_back(production);

    }

    cout << "Grammar Type: " << identify_grammar_type(productions) << endl;

    return 0;
}
