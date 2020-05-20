//
// Created by fred on 04/03/19.
//



#include "Message.h"


#include "AvatarController.h"

AvatarController::AvatarController() = default;

Message AvatarController::displayAvatar(User& user) {
    std::vector<Avatar> avatars = avatarService.getAvailableAvatar(user);

    int i = 0;
    if (!avatars.empty()) {
        std::string descriptions;
        for (const auto &avatar : avatars) {
            i++;
            descriptions += "NPC" + std::to_string(i);
            descriptions += "---------------------------------------------------------------";
            descriptions += "\n";
            descriptions += "id: " + std::to_string(avatar.getId());
            descriptions += "\n";
            descriptions += "keywords: \n";
            for (const auto &keywords: avatar.getKeywords()) {
                descriptions += keywords;
            }
            descriptions += "\n";
            descriptions +=  "shortdesc: ";
            descriptions +=  avatar.getShortdesc();
            descriptions += "\n";
            descriptions += "longdesc: ";
            descriptions += "\n";
            for (const auto &longdesc: avatar.getLongdesc()) {
                descriptions += longdesc;
            }
            descriptions += "\n";
            descriptions += "description: ";
            for (const auto &description: avatar.getDescription()) {
                descriptions += description;
            }
            descriptions += "\n";
            descriptions += "---------------------------------------------------------------";
        }
        descriptions += "\n";
        descriptions += "please use avatar command to select avatar";
        return Message{user, descriptions};
    } else {
        return Message{user, "There is no available avatar"};
    }
}