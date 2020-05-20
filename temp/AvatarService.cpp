//
// Created by fred on 04/03/19.
//

#include <iostream>
#include "AvatarService.h"

#include "AvatarService.h"


AvatarService::AvatarService() {
    loadFromStorage();
}

void AvatarService::loadFromStorage() {
    for (const CusJson::NPC &npc:_dataStorage.getJsonArea()._npcs) {
        avatars.emplace_back(npc.id,npc.keywords,npc.shortdesc,npc.longdesc,npc.description);
    }

//    outputLoadedAvatars();
}

void AvatarService::outputLoadedAvatars() const {
    for (auto a : avatars) {
        std::cout << a.getId();
        for (auto b: a.getKeywords()) {
            std::cout << b << std::endl;
        }
        std::cout << a.getName();
        std::cout << a.getShortdesc();
        for (auto b: a.getLongdesc()) {
            std::cout << b << std::endl;
        }
        for (auto b: a.getDescription()) {
            std::cout << b << std::endl;
        }
    }
}


const unordered_map<int, Avatar> &AvatarService::getUserToAvatar() const {
    return userToAvatar;
}

void AvatarService::setUserToAvatar(const unordered_map<int, Avatar> &userToAvatar) {
    AvatarService::userToAvatar = userToAvatar;
}

const vector<Avatar> &AvatarService::getAvatars() const {
    return avatars;
}

void AvatarService::setAvatars(const vector<Avatar> &avatars) {
    AvatarService::avatars = avatars;
}

const vector<Avatar> &AvatarService::getAvailableAvatar(const User &user) const {
    return avatars;
}
