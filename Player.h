//
// Created by Abraham Doughty on 10/9/22.
//

#ifndef M1OEP_PLAYER_H
#define M1OEP_PLAYER_H

#include <string>

using namespace::std;

class Player {
private:
    string name;
    int score;

public:

    Player();

    Player(string name, int score);

    int getScore();

    string getName();

    void setScore(int score);

    void setName(string name);
};

#endif //M1OEP_PLAYER_H
