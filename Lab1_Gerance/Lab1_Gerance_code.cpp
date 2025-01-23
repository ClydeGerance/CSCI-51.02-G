#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// Function to change the letter to the next letter in the alphabet
void nextLetterFunc(char *ch) {
    if (*ch >= 'a' && *ch <= 'z') {
        // Move to the next letter in lowercase
        if (*ch == 'z') {
            *ch = 'a';
        } else {
            (*ch)++;
        }
    } else if (*ch >= 'A' && *ch <= 'Z') {
        // Move to the next letter in uppercase
        if (*ch == 'Z') {
            *ch = 'A';
        } else {
            (*ch)++;
        }
    }
}

int main() {
    string name;
    
    // Ask for the user's name
    cout << "Enter your name: ";
    cin >> name;
    
    // Print the user's name
    cout << name << endl;

    // Print the user's name with only the first letter revealed and all other letters replaced with '#'
    cout << name[0];  // Print the first letter
    for (int i = 1; i < name.length(); i++) {
        cout << "#";  // Replace all other letters with '#'
    }
    cout << endl;

    // Print the user's name with all letters replaced with the next letter
    for (int i = 0; i < name.length(); i++) {
        nextLetterFunc(&name[i]);  // Apply the function to change each letter
    }
    cout << name << endl;  // Print the transformed name
    cout << name << endl;  // Print the transformed name
    
    return 0;
}
