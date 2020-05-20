//
// Created by Owner on 1/18/2019.
//

#include "Avatar.h"
#include "ContainerItem.h"

bool Avatar::takeItem(InventoryItem inventoryItem) {
    return _inventory.addItem(inventoryItem);
}

void Avatar::putItem(InventoryItem inventoryItem, ContainerItem containerObject) {
    // TODO: complete once adding to a containerItem is implemented
    // containerObject.addItem(inventoryItem);
}

void Avatar::dropItem(InventoryItem inventoryItem) {
    // TODO: complete after implementing an _inventory in a room
    InventoryItem removedItem = removeItem(inventoryItem);
    // currentRoom._inventory.addItem(removedItem);
}

bool Avatar::wearItem(InventoryItem inventoryItem) {
    if (inventoryItem.getItemType() == ItemType::CLOTHING) {
        InventoryItem clothingToRemove = _currentClothing;
        InventoryItem clothingToWear = removeItem(inventoryItem);
        _currentClothing = clothingToWear;
        return _inventory.addItem(clothingToRemove);
    }
    return false;
}

InventoryItem Avatar::removeItem(InventoryItem inventoryItem) {
    return _inventory.removeItem(inventoryItem.getId());
}

bool Avatar::isPlayable() {
    return _avatarType == AvatarType::PLAYABLE;
}

Avatar::Avatar(AvatarType avatarType, int userId)
        : MAX_HP(200),
          MAX_MANA(150),
          _avatarType(avatarType),
          _userID(userId),
          _inventory(Inventory(_userID)) {}

void Avatar::set_hp(unsigned int _hp) {
    Avatar::_hp = _hp;
}

void Avatar::set_mana(unsigned int _mana) {
    Avatar::_mana = _mana;
}

void Avatar::set_currentRoom(const models::Room &_currentRoom) {
    Avatar::_currentRoom = _currentRoom;
}

AvatarType Avatar::get_avatarType() const {
    return _avatarType;
}

int Avatar::get_userID() const {
    return _userID;
}

const InventoryItem &Avatar::get_currentClothing() const {
    return _currentClothing;
}

const Inventory &Avatar::get_inventory() const {
    return _inventory;
}

const string &Avatar::getName() const {
    return name;
}

int Avatar::get_hp() const {
    return _hp;
}

int Avatar::get_mana() const {
    return _mana;
}

const models::Room &Avatar::get_currentRoom() const {
    return _currentRoom;
}


string Avatar::get_tellCommandMessages() const {
    return _tellCommandMessages;
}

Avatar::Avatar(int id, const vector<string> &keywords, const string &shortdesc, const vector<string> &longdesc,
               const vector<string> &description) : id(id), keywords(keywords), shortdesc(shortdesc),
                                                    longdesc(longdesc), description(description) {}

int Avatar::getId() const {
    return id;
}

const vector<string> &Avatar::getKeywords() const {
    return keywords;
}

const string &Avatar::getShortdesc() const {
    return shortdesc;
}

const vector<string> &Avatar::getLongdesc() const {
    return longdesc;
}

const vector<string> &Avatar::getDescription() const {
    return description;
}

