
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Variables decelerations; these are outside of main() because all functions perform 

int hours = 0;
int minutes = 0;
int seconds = 0;

void AddHours(int i); //Ensures hours value does not exceed 24

void AddMinutes(int i); //Ensures minutes value does not 60

void AddSeconds(int i); //Ensures seconds value does not 60

void ClearScreen(); //Prints 4 blank lines
string WriteLines(char character, int times); //Returns string: a line
void PrintTop_ButtomLine(); //Prints the 1st and 4th line in the function

void PrintSecondLine(); //Prints the 2nd line in the function

void PrintThirdLine(); //Prints the 3rd and 4th line in the function

void DisplayTime(); //Prints the time in the correct format

void DisplayMenu(); //Prints the formatted menu to the user

int GetInput(string question); //Returns an integer response to a question as an argument

int main() {
    bool pressButton;
    while (true) {
        ClearScreen();
        DisplayTime();
        pressButton = (GetInput("Press button? (1-Yes 2-No) ") == 2);
        if (pressButton) {
            AddSeconds(1);
            continue; //While loop restarts
        }
        else {
            DisplayMenu();
            int userInput = GetInput("Enter Menu Selection: ");
            if (userInput == 4) {
                break; //While loop ends. Program exits.
            }
            else if (userInput == 1) {
                //AddHours(GetInput("Enter count: ")); 
                
                    AddHours(1); //Adds 1 hour
            }
            else if (userInput == 2) {
                AddMinutes(1); 
            }
            else if (userInput == 3) {
                
                AddSeconds(1); 
            }
        }
    }
    return 0;
}
void ClearScreen() {
    for (int i = 0; i < 4; i++) {
        cout << endl;
    }
}
void DisplayTime() {
    PrintTop_ButtomLine();
    PrintSecondLine();
    PrintThirdLine();
    PrintTop_ButtomLine();
}
void PrintTop_ButtomLine() {
    string text;
    text = WriteLines('*', 57); 
    text.replace(27, 5, " "); 
        cout << text << endl;
}
void PrintSecondLine() {
    string text;
    text = WriteLines(' ', 57);
    text.at(0) = '*'; 
    text.at(26) = '*';
    text.at(32) = '*';
    text.at(56) = '*';
    text.replace(7, 13, "12 Hour Clock");
    text.replace(39, 13, "24 Hour Clock");
    cout << text << endl;
}
void PrintThirdLine() {
    string text;
    string iosTime; //Stores time in 12-hour format 
    string stdTime; //Stores time in 24-hour format 
    text = WriteLines(' ', 57);
    text.at(0) = '*';
    text.at(26) = '*';
    text.at(32) = '*';
    text.at(56) = '*';
    string meridiem; //Stores meridiem
    int hour;
    if (hours < 12) { //This IF formats the 12-hour time system
        meridiem = " AM"; 
        hour = hours;
    }
    else { 
        meridiem = " PM"; 
        if (hours == 12) {
            hour = 12;
        }
        else { //If hour is 13 or less than 24 
            hour = hours - 12; 
        }
    }
    iosTime = to_string(hour) + ':' + to_string(minutes) + ':' + to_string(seconds) +
        meridiem;
    stdTime = to_string(hours) + ':' + to_string(minutes) + ':' + to_string(seconds);

    text.replace(9, iosTime.length(), iosTime);
    text.replace(43, stdTime.length(), stdTime);

    cout << text << endl;
}
string WriteLines(char character, int times) {
    string text = "";
    for (int i = 0; i < times; i++) {
        text += character;
    }
    return text;
}
void AddHours(int i) {
    hours += i;
    if (hours > 23) {
        hours = 0;
    }
}
void AddMinutes(int i) {
    minutes += i;
    if (minutes > 59) {
        AddHours(minutes / 60);
        minutes %= 60;
    }
}
void AddSeconds(int i) {
    seconds += i;
    if (seconds > 59) {
        AddMinutes(seconds / 60);
        seconds %= 60;
    }
}
int GetInput(string question) {
    int input;
    cout << question << flush;
    cin >> input;
    return input;
}
void DisplayMenu() {
    cout << WriteLines('*', 27) << endl;
    cout << "* 1-Add One Hour *" << endl;
    cout << "* 2-Add One Minute *" << endl;
    cout << "* 3-Add One Second *" << endl;
    cout << "* 4-Exit Program *" << endl;
    cout << WriteLines('*', 27) << endl;
}






