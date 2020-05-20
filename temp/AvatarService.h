//
// Created by fred on 04/03/19.
//

#include "Area.h"
#include "Avatar.h"
#include "DataStorage.h"
#include "User.h"

#ifndef WEBSOCKETNETWORKING_AVATARSERVICE_H
#define WEBSOCKETNETWORKING_AVATARSERVICE_H


class AvatarService {
public:
    AvatarService();

    const unordered_map<int, Avatar> &getUserToAvatar() const;

    void setUserToAvatar(const unordered_map<int, Avatar> &userToAvatar);


    const vector<Avatar> &getAvatars() const;
    void setAvatars(const vector<Avatar> &avatars);

    const vector<Avatar> &getAvailableAvatar(const User &user) const;

private:

    std::vector<Avatar> avatars;

    std::unordered_map<int, Avatar> userToAvatar;

    DataStorage _dataStorage = DataStorage();

    void loadFromStorage();

    void outputLoadedAvatars() const;

};

#endif //WEBSOCKETNETWORKING_AVATARSERVICE_H


