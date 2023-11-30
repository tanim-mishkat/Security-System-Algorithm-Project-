#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <limits> // Include the header for numeric_limits

using namespace std;

struct User
{
    string username;
    string password;
    int age;
};

User loggedInUser; // Global variable to store the currently logged-in user

// Function to display user details
void viewUserDetails(const User &user)
{
    cout << "\nUser Details: " << endl;
    cout << "Username: " << user.username << endl;
    cout << "Age: " << user.age << endl;
    cout << "Password: " << user.password << endl;
}

// Function to register a new user
void registerUser()
{

    cout << "\n\t________________________" << endl;
    cout << "\t|        Register      |" << endl;
    cout << "\t|______________________|" << endl;

    string name, password;
    int age;

    cout << "\nEnter your username: " << endl;
    cin >> name;
    cout << "Enter your password: " << endl;
    cin >> password;
    cout << "Enter your age: " << endl;
    cin >> age;

    if (age < 18)
    {
        cout << "\nYou must be 18 or older to register :)\n"
             << endl;
        return;
    }

    ofstream outFile("file.txt", ios::app); // Open the file in append mode
    if (outFile.is_open())
    {
        outFile << name << endl;
        outFile << password << endl;
        outFile << age << endl;
        cout << "\nRegistration successful :)" << endl;
    }
    else
    {
        throw runtime_error("\nError opening file for registration :(\n");
    }
    outFile.close();
}

// Function to handle user login
void loginUser()
{
    cout << "\t_________________________" << endl;
    cout << "\t|         Login         |" << endl;
    cout << "\t|_______________________|" << endl;

    string username, password;
    cout << "\nEnter username: " << endl;
    cin >> username;
    cout << "Enter password: " << endl;
    cin >> password;

    ifstream inFile("file.txt");
    string fileUsername, filePassword;
    int fileAge;
    bool userFound = false;

    if (!inFile)
    {
        throw runtime_error("\nError opening file for login!!!\n");
    }

    while (inFile >> fileUsername >> filePassword >> fileAge)
    {
        if (username == fileUsername && password == filePassword)
        {
            userFound = true;
            loggedInUser = {username, password, fileAge}; // Set the currently logged-in user
            break;
        }
    }

    inFile.close();

    if (userFound)
    {
        cout << "\nLogin successful! :)" << endl;
    }
    else
    {
        cout << "\nIncorrect credentials!!!" << endl;
    }
}

// Function to change user password
void changePassword()
{
    cout << "\n\t________________________" << endl;
    cout << "\t|   Change Password    |" << endl;
    cout << "\t|______________________|" << endl;

    // Check if the user is logged in
    if (loggedInUser.username.empty())
    {
        cout << "\nPlease log in first!!!" << endl;
        return;
    }

    string oldPassword, newPassword, confirmPassword;

    // Verify old password
    cout << "\nEnter old password: ";
    cin >> oldPassword;

    if (oldPassword != loggedInUser.password)
    {
        cout << "\nIncorrect old password!!!" << endl;
        return;
    }

    ofstream outFile("file.txt");
    if (!outFile)
    {
        throw runtime_error("\nError opening file for password change!!!\n");
    }

    // Display user details

    cout << "Enter new password: ";
    cin >> newPassword;
    cout << "Confirm new password: ";
    cin >> confirmPassword;

    if (newPassword == confirmPassword)
    {
        loggedInUser.password = newPassword;
        outFile << loggedInUser.username << endl;
        outFile << newPassword << endl;
        outFile << loggedInUser.age << endl;
        cout << "\nPassword changed successfully!" << endl;
    }
    else
    {
        cout << "\n!!! Passwords do not match. Reverted to the old password !!!" << endl;
        outFile << loggedInUser.username << endl;
        outFile << loggedInUser.password << endl;
        outFile << loggedInUser.age << endl;
    }

    outFile.close();
}

void run()
{
    int choice;
    do
    {
        cout << "\n\t     Security System" << endl;
        cout << "\t------------------------" << endl;
        cout << "\t|   1. Register        |" << endl;
        cout << "\t|   2. Login           |" << endl;
        cout << "\t|   3. Change Password |" << endl;
        cout << "\t|   4. View Details    |" << endl;
        cout << "\t|   5. Exit            |" << endl;
        cout << "\t------------------------" << endl
             << endl;

        cout << "Enter Your Choice: ";

        // Check if the input is an integer
        if (cin >> choice)
        {
            try
            {
                switch (choice)
                {
                case 1:
                    registerUser();
                    break;

                case 2:
                    loginUser();
                    break;

                case 3:
                    changePassword();
                    break;

                case 4:
                    viewUserDetails(loggedInUser);
                    break;

                case 5:
                    cout << "\nThank You!" << endl;
                    break;

                default:
                    cout << "\nEnter a valid choice (1 to 5)" << endl;
                    break;
                }
            }
            catch (const exception &ex)
            {
                cerr << "Exception: " << ex.what() << endl;
            }
        }
        else
        {
            // Clear the error state
            cin.clear();

            // Ignore the invalid input up to the newline character
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "\nInvalid input. Please enter a number between (1 and 5)" << endl;
        }

    } while (choice != 5);
}

int main()
{
    run();

    return 0;
}
