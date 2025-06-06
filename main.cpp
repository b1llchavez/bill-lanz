// main.cpp
#include "stack_queue.h"
#include <iostream>
#include <limits>
using namespace std;

// ANSI color codes
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"
#define WHITE   "\033[37m"

// Helper function to get validated integer input within a range
int getValidatedInput(int min, int max, const string& prompt) {
    int choice;
    while (true) {
        cout << CYAN << prompt << RESET;
        if (cin >> choice && choice >= min && choice <= max) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        } else {
            cout << RED << "Invalid input. Please enter a number between " << min << " and " << max << ".\n" << RESET;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Function to print the big ASCII art title
void printBigTitle() {
    cout << BOLD << BLUE;
    cout << " _____ ___    _    __  __    ____ _____ __  __ ___ _   _ ___ \n";
    cout << "|_   _| __|  / \\  |  \\/  |  / ___| ____|  \\/  |_ _| \\ | |_ _|\n";
    cout << "  | | |  _| / _ \\ | |\\/| | | |  _|  _| | |\\/| || ||  \\| || | \n";
    cout << "  | | | |__/ ___ \\| |  | | | |_| | |___| |  | || || |\\  || | \n";
    cout << "  |_| |___/_/   \\_\\_|  |_|  \\____|_____|_|  |_|___|_| \\_|___|\n";
    cout << RESET;
}

int main() {
    StaticStack staticStack;
    DynamicStack dynamicStack;
    StaticQueue staticQueue;
    DynamicQueue dynamicQueue;

    int mainChoice, subChoice;
    string input;

    printBigTitle();

    do {
        cout << BOLD << MAGENTA << "\n====================================\n";
        cout << "              MAIN MENU\n";
        cout << "====================================\n" << RESET;
        cout << YELLOW << "[1] Static Stack\n";
        cout << "[2] Dynamic Stack\n";
        cout << "[3] Static Queue\n";
        cout << "[4] Dynamic Queue\n";
        cout << "[5] Exit\n" << RESET;
        cout << "------------------------------------\n";
        mainChoice = getValidatedInput(1, 5, "Select an option [1-5]: ");

        switch (mainChoice) {
            case 1:
                do {
                    cout << BOLD << GREEN << "\n---------- Static Stack Menu ----------\n" << RESET;
                    cout << CYAN << "[1] Push\n[2] Pop\n[3] Display\n[4] Back\n" << RESET;
                    cout << "---------------------------------------\n";
                    subChoice = getValidatedInput(1, 4, "Select an option [1-4]: ");
                    if (subChoice == 1) {
                        cout << YELLOW << "Enter item to push: " << RESET;
                        getline(cin, input);
                        if (input.empty()) {
                            cout << RED << "Input cannot be empty.\n" << RESET;
                        } else {
                            staticStack.push(input);
                        }
                    } else if (subChoice == 2) {
                        staticStack.pop();
                    } else if (subChoice == 3) {
                        staticStack.display();
                    }
                } while (subChoice != 4);
                break;

            case 2:
                do {
                    cout << BOLD << GREEN << "\n---------- Dynamic Stack Menu ----------\n" << RESET;
                    cout << CYAN << "[1] Push\n[2] Pop\n[3] Display\n[4] Back\n" << RESET;
                    cout << "----------------------------------------\n";
                    subChoice = getValidatedInput(1, 4, "Select an option [1-4]: ");
                    if (subChoice == 1) {
                        cout << YELLOW << "Enter item to push: " << RESET;
                        getline(cin, input);
                        if (input.empty()) {
                            cout << RED << "Input cannot be empty.\n" << RESET;
                        } else {
                            dynamicStack.push(input);
                        }
                    } else if (subChoice == 2) {
                        dynamicStack.pop();
                    } else if (subChoice == 3) {
                        dynamicStack.display();
                    }
                } while (subChoice != 4);
                break;

            case 3:
                do {
                    cout << BOLD << GREEN << "\n---------- Static Queue Menu ----------\n" << RESET;
                    cout << CYAN << "[1] Enqueue\n[2] Dequeue\n[3] Display\n[4] Back\n" << RESET;
                    cout << "---------------------------------------\n";
                    subChoice = getValidatedInput(1, 4, "Select an option [1-4]: ");
                    if (subChoice == 1) {
                        cout << YELLOW << "Enter caller name: " << RESET;
                        getline(cin, input);
                        if (input.empty()) {
                            cout << RED << "Caller name cannot be empty.\n" << RESET;
                        } else {
                            staticQueue.enqueue("Caller: " + input);
                        }
                    } else if (subChoice == 2) {
                        staticQueue.dequeue();
                    } else if (subChoice == 3) {
                        staticQueue.display();
                    }
                } while (subChoice != 4);
                break;

            case 4:
                do {
                    cout << BOLD << GREEN << "\n---------- Dynamic Queue Menu ----------\n" << RESET;
                    cout << CYAN << "[1] Enqueue\n[2] Dequeue\n[3] Display\n[4] Back\n" << RESET;
                    cout << "----------------------------------------\n";
                    subChoice = getValidatedInput(1, 4, "Select an option [1-4]: ");
                    if (subChoice == 1) {
                        cout << YELLOW << "Enter caller name: " << RESET;
                        getline(cin, input);
                        if (input.empty()) {
                            cout << RED << "Caller name cannot be empty.\n" << RESET;
                        } else {
                            dynamicQueue.enqueue("Caller: " + input);
                        }
                    } else if (subChoice == 2) {
                        dynamicQueue.dequeue();
                    } else if (subChoice == 3) {
                        dynamicQueue.display();
                    }
                } while (subChoice != 4);
                break;

            case 5:
                cout << BOLD << GREEN << "\nThank you for using the program. Goodbye!\n" << RESET;
                break;
        }
    } while (mainChoice != 5);

    return 0;
}