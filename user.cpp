//
// Created by dimit on 30/06/2021.
//

#include "user.h"
#include "chat.h"

user::~user() = default;

std::shared_ptr<chat> user::createChat (user& u){
    chat *c = new chat ((*this), u);
    std::shared_ptr<chat> ptr = std::make_shared<chat>(*c);
    chats.insert(std::make_pair(u.getName(),ptr));
    u.addChat(ptr, *this);
    return ptr;
}

void user::removeChat(const user& u){
    auto it=chats.find(u.getName());
    chats.erase(it);
}

void user::addChat(std::shared_ptr<chat> c, const user &u) {
    chats.insert(std::make_pair(u.getName(),c));
}
std::shared_ptr<chat> user::findChat(const user& u){
    auto it=chats.find(u.getName());
    return (it->second);
}

bool user::operator==(const user &right) {
    return name == right.getName();
}