// COMSC-210 | Lab 11 | Kyawt Thinzar Min
// IDE used: Visual Studio Code

#include <iostream>
using namespace std;

// Struct to represent one student in the cafeteria
struct Student {
    string name;     // student's name
    int id;          // student ID
    string *request; // pointer to a dynamically allocated array of food requests
    int numRequests; // number of food requests

    // release memory 
    ~Student() {
        if (request)
            delete [] request;
        request = nullptr;
    }
};

// Functions
void inputStudent(Student *);
void displayStudent(Student *);

int main() {
    Student *roster = new Student[NR_STUDENTS];
    
    for (int i = 0; i < NR_STUDENTS; i++)
        inputStudent(&roster[i]);
    
    for (int i = 0; i < NR_STUDENTS; i++)
        displayStudent(&roster[i]);
    
    return 0;
}

void inputStudent(Student *sptr) {
    cout << "Name: ";
    cin >> sptr->name;
    cout << "ID: ";
    cin >> sptr->id;
    cout << "How many food items would you like to request? ";
    cin >> sptr->numRequests;
    // clear newline so that there will be no problem to get input 
    cin.ignore(); 

    // Dynamically allocate an array of strings of that size
    sptr->request = new string[sptr->numRequests];

    // Input each requested food item
    for (int i = 0; i < sptr->numRequests; i++) {
        cout << "Food item #" << i + 1 << ": ";
        getline(cin, sptr->request[i]);
    }
    cout << endl;
}

// Display a student's info
void displayStudent(Student *sptr) {
    cout << "\nSummary\n";
    cout << "Name: " << sptr->name << endl;
    cout << "ID: " << sptr->id << endl;

    cout << "Requested food items:\n";
    if (sptr->numRequests == 0) {
        cout << "  None\n";
    } 
    else {
        for (int i = 0; i < sptr->numRequests; i++) {
            cout << sptr->request[i] << endl;
        }
    }
    cout<<endl;
}
