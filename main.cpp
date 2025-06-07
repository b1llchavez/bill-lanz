#include "stack_queue.h" // includes the HEADER FILE stack_queue.h
#include <iostream> // includes the input & output stream library 
#include <limits> // include limits 
using namespace std; // to not use std manually

// ANSI color codes
#define RESET   "\033[0m" // reset both text and color
#define BOLD    "\033[1m" // bold text
#define RED     "\033[31m" // red-colored text
#define GREEN   "\033[32m" // green-colored text
#define YELLOW  "\033[33m" // yellow-colored text
#define BLUE    "\033[34m" // blue-colored text
#define CYAN    "\033[36m" // cyan-colored text
#define MAGENTA "\033[35m" // magenta-colored text
#define BGREEN  "\033[92m" // bright green-colored text
#define BYELLOW "\033[93m" // bright yellow-colored text
#define BBLUE   "\033[94m" // bright blue-colored text
#define WHITE   "\033[37m" // white-colored text

// helper function to get a number input within a specific range
int getValidatedInput(int min, int max, const string& prompt) {
    int choice;  // variable to store the user's input

    while (true) {  // loop until a valid input is entered
        cout << prompt << RESET;  // display the prompt message

        if (cin >> choice && choice >= min && choice <= max) {  // if input is a number and is within the range,
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // clear any extra input
            return choice;  // return the valid input
        } else {  // if input is invalid
             cout << RED << "  \033[31mINVALID \033[37minput. Please enter a number only between "
                 << min << " and " << max << "." << endl << RESET << endl;  // displays the error message

            cin.clear();  // clears the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // discard or ignore the invalid input
        }
    }
}


// void function to print the big ASCII art title
void printBigTitle() {
    cout << BOLD << BLUE; // to make the title color blue
    cout << BOLD << "   _____ ___    _    __  __    ____ _____ __  __ ___ _   _ ___ " << endl;
    cout << BOLD << "  |_   _| __|  / \\  |  \\/  |  / ___| ____|  \\/  |_ _| \\ | |_ _|" << endl;
    cout << BOLD << "    | | |  _| / _ \\ | |\\/| | | |  _|  _| | |\\/| || ||  \\| || | " << endl;
    cout << BOLD << "    | | | |__/ ___ \\| |  | | | |_| | |___| |  | || || |\\  || | " << endl;
    cout << BOLD << "    |_| |___/_/   \\_\\_|  |_|  \\____|_____|_|  |_|___|_| \\_|___|" << endl;
    cout << RESET; // to reset the bold and color blue text
    cout << " " << endl; // for spacing
    cout << BOLD << "  =============================================================" << endl;
    cout << BLUE << "             Mamon, Mamorno, Sacramento, Tolentino       " << endl; // group member surnames
    cout << BOLD << WHITE << "  =============================================================" << RESET;
}

int main() {
    StaticStack staticStack; // creates a static stack object
    DynamicStack dynamicStack; // creates a dynamic stack object
    StaticQueue staticQueue; // creates a static queue object
    DynamicQueue dynamicQueue; // creates a dynamic queue object

    int mainChoice, subChoice; // variables to the store menu choices
    string input; // variable that will store the user's input

    printBigTitle(); // print the TEAM GEMINI 


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
                    if (subChoice == 1) { // if the user selects option 1 (pop)
                        cout << RESET << "  Enter an item to \033[1m\033[93mPUSH\033[0m: " << RESET;
                        getline(cin, input);
                        if (input.empty()) {
                            cout << BOLD << WHITE << "  Input should " << RED << "NOT " << WHITE << "be empty." << endl << RESET;
                        } else {
                            staticStack.push(input);  // pushes an input to the static stack
                        }
                    } else if (subChoice == 2) { // if the user selects option 2 (pop)
                        staticStack.pop(); // pops an item from static stack
                    } else if (subChoice == 3) { // if the user selects option 3 (display)
                        staticStack.display(); // display contents of static stack
                    }
                } while (subChoice != 4);  // repeat until the user selects option 4 (back)
                break; // exit the current case block

            case 2:
                do {
                    cout << endl << BOLD << CYAN << "  - " << YELLOW << "- " << CYAN << "- " << YELLOW << "- " << WHITE << "  Dynamic Stack Menu  " << BOLD <<  YELLOW << " -" << CYAN << " -" << YELLOW << " -" << CYAN << " -" << endl << RESET;
                    cout << CYAN << "  ["<< BOLD << YELLOW "1" << RESET << CYAN"]" << WHITE << " Push" << endl;
                    cout << CYAN << "  ["<< BOLD << YELLOW "2" << RESET << CYAN"]" << WHITE << " Pop" << endl;
                    cout << CYAN << "  ["<< BOLD << YELLOW "3" << RESET << CYAN"]" << WHITE << " Display" << endl;
                    cout << CYAN << "  ["<< BOLD << YELLOW "4" << RESET << CYAN"]" << WHITE << " Back" << endl;
                    cout << BOLD << CYAN "  ----" << YELLOW << "----" << CYAN << "----" << YELLOW << "----" << CYAN << "-----" << YELLOW << "----" << CYAN << "----" << YELLOW << "----" << CYAN << "----" << RESET << endl;
                    subChoice = getValidatedInput(1, 4, "\033[0m  Select an option from\033[36m \033[1m[\033[33m1-4\033[36m]\033[37m: \033[0m");
                    if (subChoice == 1) { // if the user selects option 1 (pop)
                        cout << RESET << "  Enter an item to \033[1m\033[93mPUSH\033[0m: " << RESET;
                        getline(cin, input);
                        if (input.empty()) {
                            cout << RED << "  INPUT" << WHITE <<  " cannot be empty." << endl << RESET;
                        } else {
                            dynamicStack.push(input); // pushes an input to the dynamic stack
                        }
                    } else if (subChoice == 2) { // if the user selects option 2 (pop)
                        dynamicStack.pop(); // pops an item from the dynamic stack
                    } else if (subChoice == 3) { // if the user selects option 3 (display)
                        dynamicStack.display(); // display contents of the dynamic stack
                    }
                } while (subChoice != 4); // repeat until the user selects option 4 (back)
                break; // exit the current case block

            case 3:
                do {
                    cout << endl << BOLD << GREEN << "  - " << BGREEN << "- " << GREEN << "- " << BGREEN << "- " << WHITE << "  Static Queue Menu  " << BOLD <<  BGREEN << " -" << GREEN << " -" << BGREEN << " -" << GREEN << " -" << endl << RESET;
                    cout << GREEN << "  ["<< BOLD << BGREEN "1" << RESET << GREEN"]" << WHITE << " Enqueue" << endl;
                    cout << GREEN << "  ["<< BOLD << BGREEN "2" << RESET << GREEN"]" << WHITE << " Dequeue" << endl;
                    cout << GREEN << "  ["<< BOLD << BGREEN "3" << RESET << GREEN"]" << WHITE << " Display" << endl;
                    cout << GREEN << "  ["<< BOLD << BGREEN "4" << RESET << GREEN"]" << WHITE << " Back" << endl;
                    cout << BOLD << GREEN "  ----" << BGREEN << "----" << GREEN << "----" << BGREEN << "----" << GREEN << "-----" << BGREEN << "----" << GREEN << "----" << BGREEN << "----" << GREEN << "----" << RESET << endl;
                    subChoice = getValidatedInput(1, 4, "\033[0m  Select an option from\033[32m \033[1m[\033[92m1-4\033[32m]\033[37m: \033[0m");
                    if (subChoice == 1) { // if the user selects option 1 (enqueue)
                        cout << "  Enter caller name: " << RESET; 
                        getline(cin, input);  // read full input line
                        if (input.empty()) {  // if the input is empty
                            cout << "  Caller name cannot be" << RED << " EMPTY." << endl << RESET; // display that the caller name cannot be empty
                        } else { // if input is not empty
                            staticQueue.enqueue(input); // adds the caller to the static queue
                        }
                    } else if (subChoice == 2) { // if the user selects option 2 (dequeue)
                        staticQueue.dequeue(); // removes the caller from static queue
                    } else if (subChoice == 3) { // if the user selects option 3 (display)
                        staticQueue.display(); // display the contents of static queue
                    }
                } while (subChoice != 4); // repeat until the user selects option 4 (back)
                break; // exit the current case block

            case 4:
                do {
                    cout << endl << BOLD << BBLUE << "  - " << BYELLOW << "- " << BBLUE << "- " << BYELLOW << "- " << WHITE << "  Dynamic Queue Menu  " << BOLD <<  BYELLOW << " -" << BBLUE << " -" << BYELLOW << " -" << BBLUE << " -" << endl << RESET;
                    cout << BBLUE << "  ["<< BOLD << BYELLOW "1" << RESET << BBLUE"]" << WHITE << " Enqueue" << endl;
                    cout << BBLUE << "  ["<< BOLD << BYELLOW "2" << RESET << BBLUE"]" << WHITE << " Dequeue" << endl;
                    cout << BBLUE << "  ["<< BOLD << BYELLOW "3" << RESET << BBLUE"]" << WHITE << " Display" << endl;
                    cout << BBLUE << "  ["<< BOLD << BYELLOW "4" << RESET << BBLUE"]" << WHITE << " Back" << endl;
                    cout << BOLD << BBLUE "  ----" << BYELLOW << "----" << BBLUE << "----" << BYELLOW << "----" << BBLUE << "-----" << BYELLOW << "----" << BBLUE << "----" << BYELLOW << "----" << BBLUE << "----" << RESET << endl;
                    subChoice = getValidatedInput(1, 4, "\033[0m  Select an option from\033[94m \033[1m[\033[93m1-4\033[94m]\033[37m: \033[0m");
                    if (subChoice == 1) { // if the user selects option 1 (enqueue)
                        cout << "  Enter caller name: " << RESET;
                        getline(cin, input); // read full input line
                        if (input.empty()) { // if the input is empty
                            cout << "  Caller name cannot be" << RED << " EMPTY." << endl << RESET; // display that the caller name cannot be empty
                        } else { // if input is not empty
                            dynamicQueue.enqueue(input); // adds the caller to the static queue
                        }
                    } else if (subChoice == 2) { // if the user selects option 2 (dequeue)
                        dynamicQueue.dequeue(); // removes the caller from dynamic queue
                    } else if (subChoice == 3) { // if the user selects option 3 (display)
                        dynamicQueue.display(); // display the contents of dynamic queue
                    }
                } while (subChoice != 4); // repeat until the user selects option 4 (back)
                break; // exit the current case block

            case 5:
                cout << BOLD << GREEN << endl << "  Thank you for using the program. Goodbye!" << RESET << endl; // prompt message that the program will now shut down/exit
                break;
        }
    } while (mainChoice != 5); // repeat menu until the user chooses to exit

    return 0; // program termination
}
