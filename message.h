//
// Created by dimit on 30/06/2021.
//

#ifndef ELABORATO_MESSAGE_H
#define ELABORATO_MESSAGE_H

#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <ctime>

class user;
class message{
public:
    message(user * se, user* re, std::string te,bool r = false): sender(se), receiver(re), text(std::move(te)), read(r){
        time(&currentTime);
    }

    const std::string & getText() const {
        return text;
    }
    bool isRead() const {
        return read;
    }
    void setRead(bool read) {
        message::read = read;
    }

    time_t getCurrentTime() const {
        return currentTime;
    }

public:
    user *getSender() const {
        return sender;
    }

    user *getReceiver() const {
        return receiver;
    }
    message(const message& original);
    message & operator=(const message& right);
private:
    time_t currentTime{};
    bool read;
    user *sender, *receiver;
    std::string text;
};

#endif //ELABORATO_MESSAGE_H
