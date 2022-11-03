//
// Created by Abraham Doughty on 10/9/22.
//

#include "Board.h"
#include "SelectionSort.h"
#include <iomanip>

Board::Board(vector<Question> &questions, Round round) {
    this->questions = questions;
    this->round = round;

    //sort by category
    selectionSort(questions);
    //sort by value
    selectionSortSecond(questions);
}

vector<Question> Board::getQuestions() const {
    return questions;
}

Board::Round Board::getRound() const {
    return round;
}

//setters
void Board::setQuestions(vector<Question> questions) {
    this->questions = questions;
}

void Board::setRound(Round round) {
    this->round = round;
}

//function prints visual representation of the board to console
void Board::displayBoard() const {

    //print the categories
    for (int i = 0; i < 6; i += 1) {

        cout << left << setw(35) << questions[i].getCategory();

    }

    cout << endl;

    //print the values
    for (int i = 0; i < 30; i += 6){
        for (int j = 0; j < 6; j += 1) {
            if (questions[(i + j)].getStatus() == Question::UNPICKED) {
                cout << setw(35) << to_string(questions[(i + j)].getValue());
            }
            else {
                cout << setw(35) << "----";
            }
        }
        cout << endl;
    }
}