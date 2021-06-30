#include <iostream>
#include <memory>

#include "chat.h"
#include "user.h"

int main() {
    user dylan("Dylan");
    user berkamp ("Berkamp");
    std::shared_ptr<chat> ptr= dylan.createChat(berkamp);
    std::shared_ptr<chat> ptr2= dylan.findChat(berkamp);
    user paul("Paul");
    message foo(&dylan, &berkamp, "Ciao Berkamp, come va?");
    message bar(&berkamp, &dylan, "Tutto bene, te?");
    message fooBar(&dylan, &berkamp, "Anch'io tutto bene");

    ptr2->addMessage(foo);
    ptr->addMessage(bar);
    ptr->addMessage(fooBar);
    try {
        ptr->readMessage(1);
        ptr2->readMessage(5);
    }
    catch (std::out_of_range &e) {
        std::cerr << "Out of range error:" << e.what() << std::endl;
    }
    dylan.removeChat(berkamp);
}