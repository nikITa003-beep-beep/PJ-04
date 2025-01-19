#pragma once
#include <vector>
#include <unordered_map>
#include <map>          //For storing users by login and all messages
#include "Message.h"

class Chat
{
public:
    void registration(string login, string password, string name);
    bool login();
    void addMessage();
    void showMessage();

private:
    map<string, User> _users; // Storing users by login
    unordered_map<string, vector<Message>> _messages; // Messages by recipient
    vector<Message> _messages;
    shared_ptr<User> _currentUser = nullptr;
};