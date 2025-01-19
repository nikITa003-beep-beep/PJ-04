#include <iostream>
#include "Exception.h"
#include "Chat.h"

using namespace std;

int main() {
    Chat chat;

    chat.registration("l123", "123", "Kate");
    chat.registration("l234", "234", "Andy");
    chat.registration("l345", "345", "Kit");

    bool chatWork = true;
    while (chatWork) {
        cout << "Welcome to the chat! Choose the action: 1 - registration; 2 - login; 0 - exit" << endl;
        int choice_1, choise_2;
        cin >> choice_1;
        switch (choice_1) {
        case 1: {
            string login, password, name;
            cout << "Enter login: ";
            cin >> login;
            cout << "Enter password: ";
            cin >> password;
            cout << "Enter name: ";
            cin >> name;

            try {
                chat.registration(login, password, name);
            }
            catch (const LoginException& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 2:
            if (chat.login())
            {
                std::cout << "Menu: 1. View messages, 2. Send message, 0. Exit" << std::endl;
                cin >> choise_2;
                switch (choise_2)
                {
                case 1:
                    chat.showMessage();
                    break;
                case 2:
                    chat.addMessage();
                    break;
                case 0:
                    chatWork = false;
                    break;
                }
            }
            break;
        case 0:
            chatWork = false;
            break;
        default:
            cout << "Error! Choose 1 or 2, or 0 for exit." << endl;
            break;
        }
    }
    return 0;
}