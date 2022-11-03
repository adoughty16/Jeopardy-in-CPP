//
// Created by Abraham Doughty on 10/9/22.
//
#include "Player.h"
#include "Question.h"
#include "Board.h"

int main() {

    bool passed = true;

    Question q1 = Question("Test Round", "Test Category", 0, "Test Question", "Test Answer");
    Question q2;

    if (q2.getValue() != -1 || q2.getRound() != "default" || q2.getCategory() != "default" || q2. getAnswer() != "default" || q2.getQuestion() != "default") {
        passed = false;
        cout << "Failed Question default constructor test" << endl;
    }

    if (q1.getValue() != 0 || q1.getRound() != "Test Round" || q1.getCategory() != "Test Category" || q1. getAnswer() != "Test Answer" || q1.getQuestion() != "Test Question") {
        passed = false;
        cout << "Failed Question constructor test" << endl;
    }

    q2.setValue(100);
    q2.setStatus(Question::PICKED);
    q2.setAnswer("ANSWER");
    q2.setCategory("CATEGORY");
    q2.setQuestion("QUESTION");
    q2.setRound("ROUND");

    if (q2.getValue() != 100 || q2.getRound() != "ROUND" || q2.getCategory() != "CATEGORY" || q2. getAnswer() != "ANSWER" || q2.getQuestion() != "QUESTION" || q2.getStatus() != Question::PICKED) {
        passed = false;
        cout << "Failed Question setter test" << endl;
    }

    if (q1 < q2) {
        passed = false;
        cout << "Failed operator test";
    }

    if (passed) {
        cout << "Passed all Question Tests" << endl;
    }

    vector<Question> qs;
    qs.push_back(q1);
    qs.push_back(q2);
    passed = true;
    Board board = Board(qs, Board::DOUBLE_JEOPARDY);

    if (board.getQuestions()[0].getQuestion() != "Test Question") {
        passed = false;
        cout << "Failed board construction test." << endl;
    }

    board.setRound(Board::JEOPARDY);
    if (board.getRound() != Board::JEOPARDY) {
        passed = false;
        cout << "Failed board round set test" << endl;
    }

    if (passed) {
        cout << "Passed all Board Tests" << endl;
    }

    passed = true;
    Player p1 = Player("Test", 100);
    Player p2;

    if (p2.getName() != "Default Player Name") {
        passed = false;
        cout << "Failed player default construction test";
    }

    if (p1.getName() != "Test" || p1.getScore() != 100) {
        passed = false;
        cout << "Failed player non-default constructor test" << endl;
    }

    if (passed) {
        cout << "Passed all Player Tests" << endl;
    }



    return 0;
}