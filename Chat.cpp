#include <iostream>
#include "Chat.h"
#include "Exception.h"
using namespace std;



void Chat::registration(string login, string password, string name)
{
    if (_users.find(login) != _users.end()) throw LoginException();
    User user = User(login, password, name);
    cout << "Registration is completed!" << endl;
}

bool Chat::login()
{
    string login, password;
    cout << "login: "; cin >> login;
    cout << "password: "; cin >> password;

    auto it = _users.find(login);
    if (it != _users.end() && it->second.getUserPassword() == password) {
        _currentUser = make_shared<User>(it->second);
        cout << "Hello, " << it->second.getUserName() << "!" << endl;
        return true;
    }
    cout << "Error: Incorrect name or password!" << endl;
    return false;
}

void Chat::addMessage()
{
    std::string to, text;
    std::cout << "To: (Login of user or 'all' to send a message to all chat users)" << std::endl;
    std::cin >> to;
    std::string toLogin = "";
    if (to == "all")
    {
        toLogin = "all";
    }
    else
    {
        for (auto& user : _users)
        {
            if (to == user.first)
            {
                toLogin = to;
            }
        }
    }
    if (toLogin == "")
    {
        std::cout << "Error: the user's login was not found!" << std::endl;
        return;
    }

    std::cout << "Text: ";

    std::cin.ignore(sizeof(text) / sizeof(text[0]), '\n'); //so that all the words in the message can be displayed
    std::getline(std::cin, text);
    std::cin.ignore(0);

    Message message = Message(_currentUser->getUserLogin(), toLogin, text);
    _messages.emplace_back(message);
    std::cout << "Your message has been sent" << std::endl;
}

void Chat::showMessage()
{
    for (auto& message : _messages)
    {
        if ((message.getTo() == _currentUser->getUserLogin()) || (message.getTo() == "all"))
        {
            std::cout << "---------------------" << std::endl;
            std::cout << "From: " << message.getFrom() << "; To: " << message.getTo() << std::endl;
            std::cout << message.getText() << std::endl;
            std::cout << std::endl;
        }
    }
}