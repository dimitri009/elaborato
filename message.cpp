//
// Created by dimit on 30/06/2021.
//

#include "message.h"
#include "user.h"

message::message(const message &original) {
    currentTime = original.currentTime;
    read = original.read;
    text = original.text;
    if (original.sender != nullptr && original.receiver){
        sender = new user(*original.sender);
        receiver = new user(*original.receiver);
    }
    else{
        sender = {nullptr};
        receiver = {nullptr};
    }
}

message &message::operator=(const message &right) {
    if (this != &right) {
        if (sender != nullptr && receiver != nullptr){
            delete sender;
            delete receiver;
        }

        currentTime = right.currentTime;
        read = right.read;
        text = right.text;
        if (right.sender != nullptr && right.receiver){
            sender = new user(*right.sender);
            receiver = new user(*right.receiver);
        }
        else{
            sender = nullptr;
            receiver = nullptr;
        }
    }
    return *this;
}
