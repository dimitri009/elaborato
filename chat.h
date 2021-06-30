//
// Created by dimit on 30/06/2021.
//

#ifndef ELABORATO_CHAT_H
#define ELABORATO_CHAT_H

#include <iostream>
#include <memory>
#include <vector>
#include <list>

#include "message.h"


class user;
class chat {
public:
    explicit chat(user& first_user, user& second_user);

    virtual ~chat();

    void addMessage(const message& newMsg);

    const message& lastMessage() const;

    void readMessage(int i);

    int getUnreadMessages() const;

    user *getMyName() const;

    void setMyName(user *myName);

    user *getOtherName() const;

    void setOtherName(user *otherName);

    chat(user *myName, user *otherName);

    chat(const chat& original);
    chat & operator=(const chat& right);

    const std::vector<message> &getMessages() const;

private:
    std::vector<message> messages;
    user* myName;
    user* otherName;
};

#endif //ELABORATO_CHAT_H
