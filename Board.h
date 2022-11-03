//
// Created by Abraham Doughty on 9/15/22.
//

#ifndef M1OEP_BOARD_H
#define M1OEP_BOARD_H

#include "Question.h"
#include "SelectionSort.h"
#include <iomanip>

//class creates a jeopardy board
class Board {

private:

    vector<Question> questions;

public:

    //this is public because the types need to be accessible from main
    enum Round {JEOPARDY, DOUBLE_JEOPARDY, FINAL_JEOPARDY};
    Round round;

    //constructor
    Board(vector<Question> &questions, Round round);

    //getters
    vector<Question> getQuestions() const;

    Round getRound() const;

    //setters
    void setQuestions(vector<Question> questions);

    void setRound(Round round);

    //function prints visual representation of the board to console
    void displayBoard() const;

};



#endif //M1OEP_BOARD_H
