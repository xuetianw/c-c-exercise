//
// Created by fred on 04/03/19.
//

#ifndef WEBSOCKETNETWORKING_AVATARCONTROLLER_H
#define WEBSOCKETNETWORKING_AVATARCONTROLLER_H

#include "Message.h"
#include "AvatarService.h"


class AvatarController {
public:
    AvatarController();

    Message displayAvatar(User &user);

private:
    AvatarService avatarService;


};
#endif //WEBSOCKETNETWORKING_AVATARCONTROLLER_H
