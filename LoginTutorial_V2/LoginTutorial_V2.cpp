#include "main.h"

int main()
{
    std::string username;
    std::string password;
    std::string response;
    std::string welcomeOption;

welcome:
    std::cout << "Welcome to my C++ login application\n\n";
    std::cout << "Select option:\n";
    std::cout << "[1] Login\n[2] Sign Up\n\n>";

    std::cin >> welcomeOption;

    username = "";
    password = "";

    if (welcomeOption == "1") {
        goto login;
    }
    else if (welcomeOption == "2") {
        goto signup;
    }
    else {
        std::cout << "Please input \"1\" or \"2\"";
        goto welcome;
    }

login:
    system("cls");

    std::cout << "Username: ";
    std::cin >> username;

    std::cout << "\n\nPassword: ";
    std::cin >> password;

    response = LoginOrSignup(username, password, true);

    Sleep(2000);
    
    goto auth;

signup:
    system("cls");

    std::cout << "Username: ";
    std::cin >> username;

    std::cout << "\n\nPassword: ";
    std::cin >> password;

    response = LoginOrSignup(username, password, false);

    system("cls");
    if (response == "s1") {
        std::cout << "SQL Failed 1\n\n";
        Sleep(2000);
        goto welcome;
    } else if (response == "s2") {
        std::cout << "This user already exists\n\n";
        Sleep(2000);
        goto welcome;
    } else if (response == "s4") {
        std::cout << "User created\n\n";
        Sleep(2000);
        goto control_panel;
    }
    else if (response == "s3") {
        std::cout << "SQL Failed @2\n\n";
        Sleep(2000);
        goto welcome;
    }
    else {
        std::cout << "an unspecified error occurred\n\n";
        system("pause");
        goto welcome;
    }

auth:
    if (response == "TRUE") { // Username and password correct
        system("cls");
        std::cout << "Authenticated.\n";
        system("pause");
        goto control_panel;

    }
    else { // username or password not correct
        std::cout << "Incorrect password or username.\n";
        system("pause");
        goto login;
    }
control_panel:
    system("cls");
    std::cout << "User Control Panel\n";
    system("pause");
}
    // Run program: Ctrl + F5 or Debug > Start Without Debugging menu
    // Debug program: F5 or Debug > Start Debugging menu