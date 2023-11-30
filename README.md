# Security System

## Project Description
This project is a simple security system managing user registrations, logins, password changes, and viewing user details.

## How to Build and Run the Project
1. *Compilation:* Compile the code using a C++ compiler.
    bash
    g++ main.cpp -o security_system
    

2. *Execution:* Run the compiled file.
    bash
    ./security_system
    

## Additional Instructions or Dependencies
- *Dependencies:* This project uses C++ standard libraries and does not have external dependencies.
- *File Handling:* Ensure the program has permissions to read and write to the file file.txt where user details are stored.

## Code Structure
The code includes several functionalities:
- registerUser(): Allows users to register with a username, password, and age (stored in file.txt).
- loginUser(): Enables users to log in with their registered credentials.
- changePassword(): Allows users to change their passwords after successful login.
- viewUserDetails(): Displays user details for the logged-in user.
- run(): The main program execution loop presenting a menu for user interaction.
- main(): Entry point of the program, initiating the security system.

## Usage
Upon running the program, a menu is displayed prompting users to:
1. Register
2. Login
3. Change Password
4. View Details
5. Exit

Select the desired option by entering the corresponding number. Follow the on-screen instructions for each operation.

## Important Notes
- The minimum age for registration is 18.
- Password change requires logging in first.

## File Structure
- main.cpp: Contains the C++ code for the security system.
- file.txt: Stores user details (username, password, age).

## Author
- **Md. Tanimur Rahman**
- **Student ID: 222-115-238**


## License
This project is licensed under the [MIT License](LICENSE).