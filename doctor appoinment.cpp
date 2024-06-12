#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Function to book an appointment
int bookAppointment() {
    system("cls");

    cout << "\n ----- Book Your Appointment ---- \n";
    cout << "\n ----- Available slots ---- \n";

    // Check if a record already exists
    ifstream read("appointment.dat");
    char arr[26] = {0}; // Using an array to track availability of slots

    if (read) {
        string line;
        while (getline(read, line)) {
            char temp = line[0];
            int index = (temp - 'A');
            arr[index] = 1;
        }
        read.close();

        cout << "\n Appointment Summary by hours:";
        char key = 'A';
        for (int i = 9; i <= 21; i++) {
            int index = (key - 'A');
            if (arr[index] == 0)
                cout << "\n " << key << "->" << i << " - Available";
            else
                cout << "\n " << key << "->" << i << " - Booked";
            key++;
        }
    } else {
        cout << "\n Appointment Available for following hours :";
        char key = 'A';
        for (int i = 9; i <= 21; i++) {
            cout << "\n " << key << " -> " << i << " - Available";
            key++;
        }
    }

    char choice;
    cout << "\n\n Input your choice : ";
    cin >> choice;

    // Validate the choice
    if (!(choice >= 'A' && choice <= 'Z')) {
        cout << "\n Error : Invalid Selection";
        cout << "\n Please select a correct value from A to Z";
        cout << "\n Press any key to continue";
        getchar();
        getchar();
        system("cls");
        bookAppointment();
    }

    int index = (choice - 'A');
    int isBooked = arr[index];

    if (isBooked == 1) {
        cout << "\n Error : Appointment is already booked for this hour";
        cout << "\n Please select a different time.";
        cout << "\n Press any key to continue.";
        getchar();
        getchar();
        system("cls");
        bookAppointment();
    }

    string name;
    cout << "\n Enter your first name: ";
    cin >> name;

    ofstream out("appointment.dat", ios::app);

    if (out) {
        out << choice << ":" << name.c_str() << "\n";
        out.close();
        cout << "\n Appointment booked for hour: " << (choice - 'A') + 9 << " successfully!";
    } else {
        cout << "\n Error while saving booking";
    }

    cout << "\n Please press any key to continue..";
    getchar();
    getchar();
    return 0;
}

// Function to display existing appointments
int existingAppointment() {
    system("cls");
    cout << "\n ----- Appointments Summary ---- \n";

    ifstream read("appointment.dat");
    char arr[26] = {0};

    if (read) {
        string line;
        while (getline(read, line)) {
            char temp = line[0];
            int index = (temp - 'A');
            arr[index] = 1;
        }
        read.close();

        cout << "\n Appointment Summary by hours:";
        char key = 'A';
        for (int i = 9; i <= 21; i++) {
            int index = (key - 'A');
            if (arr[index] == 0)
                cout << "\n " << key << "->" << i << " - Available";
            else
                cout << "\n " << key << "->" << i << " - Booked";
            key++;
        }
    } else {
        cout << "\n No appointments have been booked yet.";
    }

    cout << "\n Please press any key to continue..";
    getchar();
    getchar();
    return 0;
}

int main() {
    while (1) {
        system("cls");
        cout << "\t\t\tDoctor Appointment System\n";
        cout << "----------------------------------------\n\n";

        cout << "1. Book Appointment\n";
        cout << "2. Check Existing Appointment\n";
        cout << "0. Exit\n";
        int choice;

        cout << "\n Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bookAppointment();
                break;
            case 2:
                existingAppointment();
                break;
            case 0:
                while (1) {
                    system("cls");
                    cout << "\n Are you sure you want to exit? (y/n)\n";
                    char ex;
                    cin >> ex;
                    if (ex == 'y' || ex == 'Y')
                        exit(0);
                    else if (ex == 'n' || ex == 'N') {
                        break;
                    } else {
                        cout << "\n Invalid choice!";
                        getchar();
                    }
                }
                break;
            default:
                cout << "\n Invalid choice. Enter again ";
                getchar();
        }
    }
    return 0;
}
