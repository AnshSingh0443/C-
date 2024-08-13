#include <iostream>
#include <string>
using namespace std;

class TuringMachine {
private:
    enum State { START, SCAN_A, SCAN_B, SCAN_C, REWIND, ACCEPT, REJECT };
    State currentState;
    int head;
    string tape;

    void moveLeft() {
        head--;
        if (head < 0) {
            tape = "B" + tape;
            head = 0;
        }
    }

    void moveRight() {
        head++;
        if (head >= tape.size()) {
            tape += "B";
        }
    }

public:
    TuringMachine() {
        currentState = START;
        head = 0;
        tape = "B";
    }

    void run(string input) {
        tape += input;
        while (currentState != ACCEPT && currentState != REJECT) {
            char currentSymbol = tape[head];
            switch (currentState) {
                case START:
                    if (currentSymbol == 'a') {
                        tape[head] = 'X';
                        moveRight();
                        currentState = SCAN_A;
                    } else {
                        currentState = REJECT;
                    }
                    break;

                case SCAN_A:
                    if (currentSymbol == 'a') {
                        moveRight();
                    } else if (currentSymbol == 'B') {
                        currentState = REJECT; // Reject if 'b' or 'c' is encountered before 'a'
                    } else {
                        currentState = SCAN_B;
                    }
                    break;

                case SCAN_B:
                    if (currentSymbol == 'b') {
                        moveRight();
                    } else if (currentSymbol == 'B') {
                        currentState = REJECT; // Reject if 'c' is encountered before 'b'
                    } else {
                        currentState = SCAN_C;
                    }
                    break;

                case SCAN_C:
                    if (currentSymbol == 'c') {
                        moveRight();
                    } else if (currentSymbol == 'B') {
                        currentState = REWIND;
                    } else {
                        currentState = REJECT; // Reject if 'c' is not found
                    }
                    break;

                case REWIND:
                    if (currentSymbol == 'X') {
                        moveLeft();
                    } else if (currentSymbol == 'a') {
                        currentState = REJECT; // Reject if 'a' is found after 'c'
                    } else if (currentSymbol == 'b') {
                        currentState = REJECT; // Reject if 'b' is found after 'c'
                    } else if (currentSymbol == 'c') {
                        currentState = SCAN_C; // Continue scanning 'c's
                    } else if (currentSymbol == 'B') {
                        currentState = ACCEPT; // Accept if tape is fully scanned
                    }
                    break;
            }
        }
        if (currentState == ACCEPT) {
            cout << "String accepted!" << endl;
        } else {
            cout << "String rejected!" << endl;
        }
    }
};

int main() {
    TuringMachine tm;
    string input;
    cout << "Enter a string of 'a's, 'b's, and 'c's: ";
    cin >> input;
    tm.run(input);
    return 0;
}

