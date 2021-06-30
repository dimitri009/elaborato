//
// Created by dimit on 30/06/2021.
//

#ifndef ELABORATO_USER_H
#define ELABORATO_USER_H

#include <iostream>
#include <memory>
#include <map>
#include <utility>

class chat;
class user {
public:
    explicit user(std::string  name) : name(std::move(name)) {}

    ~user();

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        user::name = name;
    }

    std::shared_ptr<chat> createChat(user& u);

    std::shared_ptr<chat> findChat(const user& u);

    void removeChat(const user& u);

    void addChat(std::shared_ptr<chat> c, const user & u);

    bool operator==(const user& right);

private:
    std::string name;
    std::map <std::string,std::shared_ptr<chat>> chats;
};

#endif //ELABORATO_USER_H
