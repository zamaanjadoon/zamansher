//Project Contributors
//1. Zaman Sher
//2. Sami Ullah

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person {
public:
    string full_name;
    string contact_number;
    string email_address;

    // Default constructor
    Person() : full_name(""), contact_number(""), email_address("") {}

    // Parameterized constructor
    Person(string name, string phone, string email) : full_name(name), contact_number(phone), email_address(email) {}
};

class AddressBook {
private:
    Person directory[100];
    int total_entries;

public:
    AddressBook() {
        total_entries = 0;
    }

    void add_entry(string name, string phone, string email) {
        if (total_entries < 100) {
            directory[total_entries] = Person(name, phone, email);
            total_entries++;
            cout << "Entry added successfully!" << endl;
        } else {
            cout << "Address book is full!" << endl;
        }
    }

    void delete_entry(string name) {
        for (int i = 0; i < total_entries; i++) {
            if (directory[i].full_name == name) {
                for (int j = i; j < total_entries - 1; j++) {
                    directory[j] = directory[j + 1];
                }
                total_entries--;
                cout << "Entry deleted successfully!" << endl;
                return;
            }
        }
        cout << "Entry not found!" << endl;
    }

    void find_entry(string name) {
        for (int i = 0; i < total_entries; i++) {
            if (directory[i].full_name == name) {
                cout << "Entry found:" << endl;
                cout << "Name: " << directory[i].full_name << endl;
                cout << "Phone Number: " << directory[i].contact_number << endl;
                cout << "Email: " << directory[i].email_address << endl;
                return;
            }
        }
        cout << "Entry not found!" << endl;
    }

    void list_entries() {
        if (total_entries == 0) {
            cout << "Address book is empty!" << endl;
        } else {
            cout << "All Entries:" << endl;
            for (int i = 0; i < total_entries; i++) {
                cout << "Name: " << directory[i].full_name << endl;
                cout << "Phone Number: " << directory[i].contact_number << endl;
                cout << "Email: " << directory[i].email_address << endl;
                cout << "-------------------------" << endl;
            }
        }
    }
};

void show_project_contributors() {
    vector<string> contributors = {"Zaman Sher", "Sami Ullah"};
    cout << "Project Contributors:" << endl;
    for (const string &contributor : contributors) {
        cout << "- " << contributor << endl;
    }
    cout << "-------------------------" << endl;
}

int main() {
    AddressBook address_book;

    while (true) {
        cout << "Address Book Menu:" << endl;
        cout << "1. Add Entry" << endl;
        cout << "2. Delete Entry" << endl;
        cout << "3. Find Entry" << endl;
        cout << "4. List Entries" << endl;
        cout << "5. Show Contributors" << endl;
        cout << "6. Exit" << endl;

        int option;
        cout << "Enter your choice: ";
        cin >> option;
        cin.ignore(); // Clear the newline character from the buffer

        switch (option) {
            case 1: {
                string name, phone, email;
                cout << "Enter full name: ";
                getline(cin, name);
                cout << "Enter phone number: ";
                getline(cin, phone);
                cout << "Enter email address: ";
                getline(cin, email);
                address_book.add_entry(name, phone, email);
                break;
            }
            case 2: {
                string name;
                cout << "Enter name to delete: ";
                getline(cin, name);
                address_book.delete_entry(name);
                break;
            }
            case 3: {
                string name;
                cout << "Enter name to search: ";
                getline(cin, name);
                address_book.find_entry(name);
                break;
            }
            case 4:
                address_book.list_entries();
                break;
            case 5:
                show_project_contributors();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
