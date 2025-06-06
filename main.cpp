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
#define BGREEN  "\033[92m"
#define BYELLOW "\033[93m"
#define BBLUE   "\033[94m"
#define WHITE   "\033[37m"

// Helper function to get validated integer input within a range
int getValidatedInput(int min, int max, const string& prompt) {
    int choice;
    while (true) {
        cout << prompt << RESET;
        if (cin >> choice && choice >= min && choice <= max) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        } else {
            cout << RED << endl << "  \033[31mINVALID \033[37minput. Please enter a number only between " << min << " and " << max << "." << endl << RESET;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Function to print the big ASCII art title
void printBigTitle() {
    cout << BOLD << BLUE;
    cout << BOLD <<"   _____ ___    _    __  __    ____ _____ __  __ ___ _   _ ___ " << endl;
    cout << BOLD <<"  |_   _| __|  / \\  |  \\/  |  / ___| ____|  \\/  |_ _| \\ | |_ _|" << endl;
    cout << BOLD <<"    | | |  _| / _ \\ | |\\/| | | |  _|  _| | |\\/| || ||  \\| || | " << endl;
    cout << BOLD <<"    | | | |__/ ___ \\| |  | | | |_| | |___| |  | || || |\\  || | " << endl;
    cout << BOLD <<"    |_| |___/_/   \\_\\_|  |_|  \\____|_____|_|  |_|___|_| \\_|___|" << endl;
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
        cout << BOLD << MAGENTA << endl << "  =============================================================" << endl;
        cout << BOLD << BLUE "  - " << YELLOW "- " << BLUE "- " << YELLOW "- " << BLUE "- " << YELLOW "- " << WHITE "              MAIN MENU               " << YELLOW "- " << BLUE "- " << YELLOW "- " << BLUE "- " << YELLOW "- " << BLUE "- " << endl;
        cout << BOLD << MAGENTA "  =============================================================" << endl << RESET;
        cout << " " << endl;
        cout << GREEN << "  ["<< BOLD << YELLOW "1" << RESET << GREEN"]" << WHITE << " Static Stack" << endl;
        cout << GREEN << "  ["<< BOLD << YELLOW "2" << RESET << GREEN"]" << WHITE << " Dynamic Stack" << endl;
        cout << GREEN << "  ["<< BOLD << YELLOW "3" << RESET << GREEN"]" << WHITE << " Static Queue" << endl;
        cout << GREEN << "  ["<< BOLD << YELLOW "4" << RESET << GREEN"]" << WHITE << " Dynamic Queue" << endl;
        cout << GREEN << "  ["<< BOLD << YELLOW "5" << RESET << GREEN"]" << WHITE << " Exit" << endl << RESET;
        cout << " " << endl;
        cout << BOLD << MAGENTA "  =============================================================" << RESET << endl;
        mainChoice = getValidatedInput(1, 5, "\033[0m  Select an option from\033[32m \033[1m[\033[33m1-5\033[32m]\033[37m: \033[0m");
        
        switch (mainChoice) {
            case 1:
                do {
                    cout << endl << BOLD << BLUE << "  - " << CYAN << "- " << BLUE << "- " << CYAN << "- " << WHITE << "  Static Stack Menu  " << BOLD <<  CYAN << " -" << BLUE << " -" << CYAN << " -" << BLUE << " -" << endl << RESET;
                    cout << BLUE << "  ["<< BOLD << CYAN "1" << RESET << BLUE"]" << WHITE << " Push" << endl;
                    cout << BLUE << "  ["<< BOLD << CYAN "2" << RESET << BLUE"]" << WHITE << " Pop" << endl;
                    cout << BLUE << "  ["<< BOLD << CYAN "3" << RESET << BLUE"]" << WHITE << " Display" << endl;
                    cout << BLUE << "  ["<< BOLD << CYAN "4" << RESET << BLUE"]" << WHITE << " Back" << endl;
                    cout << BOLD << BLUE "  ----" << CYAN << "----" << BLUE << "----" << CYAN << "----" << BLUE << "-----" << CYAN << "----" << CYAN << "----" << CYAN << "----" << BLUE << "----" << RESET << endl;
                    subChoice = getValidatedInput(1, 4, "\033[0m  Select an option from\033[36m \033[1m[\033[34m1-4\033[36m]\033[37m: \033[0m");
                    if (subChoice == 1) {
                        cout << RESET << "  Enter an item to \033[1m\033[93mPUSH\033[0m: " << RESET;
                        getline(cin, input);
                        if (input.empty()) {
                            cout << BOLD << WHITE << "  Input should " << RED << "NOT " << WHITE << "be empty." << endl << RESET;
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
                    cout << endl << BOLD << CYAN << "  - " << YELLOW << "- " << CYAN << "- " << YELLOW << "- " << WHITE << "  Dynamic Stack Menu  " << BOLD <<  YELLOW << " -" << CYAN << " -" << YELLOW << " -" << CYAN << " -" << endl << RESET;
                    cout << CYAN << "  ["<< BOLD << YELLOW "1" << RESET << CYAN"]" << WHITE << " Push" << endl;
                    cout << CYAN << "  ["<< BOLD << YELLOW "2" << RESET << CYAN"]" << WHITE << " Pop" << endl;
                    cout << CYAN << "  ["<< BOLD << YELLOW "3" << RESET << CYAN"]" << WHITE << " Display" << endl;
                    cout << CYAN << "  ["<< BOLD << YELLOW "4" << RESET << CYAN"]" << WHITE << " Back" << endl;
                    cout << BOLD << CYAN "  ----" << YELLOW << "----" << CYAN << "----" << YELLOW << "----" << CYAN << "-----" << YELLOW << "----" << CYAN << "----" << YELLOW << "----" << CYAN << "----" << RESET << endl;
                    subChoice = getValidatedInput(1, 4, "\033[0m  Select an option from\033[36m \033[1m[\033[33m1-4\033[36m]\033[37m: \033[0m");
                    if (subChoice == 1) {
                        cout << RESET << "  Enter an item to \033[1m\033[93mPUSH\033[0m: " << RESET;
                        getline(cin, input);
                        if (input.empty()) {
                            cout << RED << "  INPUT" << WHITE <<  " cannot be empty." << endl << RESET;
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
                    cout << endl << BOLD << GREEN << "  - " << BGREEN << "- " << GREEN << "- " << BGREEN << "- " << WHITE << "  Static Queue Menu  " << BOLD <<  BGREEN << " -" << GREEN << " -" << BGREEN << " -" << GREEN << " -" << endl << RESET;
                    cout << GREEN << "  ["<< BOLD << BGREEN "1" << RESET << GREEN"]" << WHITE << " Enqueue" << endl;
                    cout << GREEN << "  ["<< BOLD << BGREEN "2" << RESET << GREEN"]" << WHITE << " Dequeue" << endl;
                    cout << GREEN << "  ["<< BOLD << BGREEN "3" << RESET << GREEN"]" << WHITE << " Display" << endl;
                    cout << GREEN << "  ["<< BOLD << BGREEN "4" << RESET << GREEN"]" << WHITE << " Back" << endl;
                    cout << BOLD << GREEN "  ----" << BGREEN << "----" << GREEN << "----" << BGREEN << "----" << GREEN << "-----" << BGREEN << "----" << GREEN << "----" << BGREEN << "----" << GREEN << "----" << RESET << endl;
                    subChoice = getValidatedInput(1, 4, "\033[0m  Select an option from\033[32m \033[1m[\033[92m1-4\033[32m]\033[37m: \033[0m");
                    if (subChoice == 1) {
                        cout << "  Enter caller name: " << RESET;
                        getline(cin, input);
                        if (input.empty()) {
                            cout << RED << "  Caller name cannot be empty." << endl << RESET;
                        } else {
                            staticQueue.enqueue(input);
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
                    cout << endl << BOLD << BBLUE << "  - " << BYELLOW << "- " << BBLUE << "- " << BYELLOW << "- " << WHITE << "  Dynamic Queue Menu  " << BOLD <<  BYELLOW << " -" << BBLUE << " -" << BYELLOW << " -" << BBLUE << " -" << endl << RESET;
                    cout << BBLUE << "  ["<< BOLD << BYELLOW "1" << RESET << BBLUE"]" << WHITE << " Enqueue" << endl;
                    cout << BBLUE << "  ["<< BOLD << BYELLOW "2" << RESET << BBLUE"]" << WHITE << " Dequeue" << endl;
                    cout << BBLUE << "  ["<< BOLD << BYELLOW "3" << RESET << BBLUE"]" << WHITE << " Display" << endl;
                    cout << BBLUE << "  ["<< BOLD << BYELLOW "4" << RESET << BBLUE"]" << WHITE << " Back" << endl;
                    cout << BOLD << BBLUE "  ----" << BYELLOW << "----" << BBLUE << "----" << BYELLOW << "----" << BBLUE << "-----" << BYELLOW << "----" << BBLUE << "----" << BYELLOW << "----" << BBLUE << "----" << RESET << endl;
                    subChoice = getValidatedInput(1, 4, "\033[0m  Select an option from\033[94m \033[1m[\033[93m1-4\033[94m]\033[37m: \033[0m");
                    if (subChoice == 1) {
                        cout << YELLOW << "  Enter caller name: " << RESET;
                        getline(cin, input);
                        if (input.empty()) {
                            cout << RED << "  Caller name cannot be empty.\n" << RESET;
                        } else {
                            dynamicQueue.enqueue(input);
                        }
                    } else if (subChoice == 2) {
                        dynamicQueue.dequeue();
                    } else if (subChoice == 3) {
                        dynamicQueue.display();
                    }
                } while (subChoice != 4);
                break;

            case 5:
                cout << BOLD << GREEN << endl << "  Thank you for using the program. Goodbye!" << RESET << endl;
                break;
        }
    } while (mainChoice != 5);

    return 0;
}
