//
// Created by Abraham Doughty on 10/9/22.
//

#include "Player.h"

Player::Player() {
    setName("Default Player Name");
    setScore(0);
}

Player::Player(string name, int score) {
    setName(name);
    setScore(score);
}

int Player::getScore() {
    return score;
}

string Player::getName() {
    return name;
}

void Player::setScore(int score) {
    this->score = score;
}

void Player::setName(string name) {
    this->name = name;
}

