//
// Created by Abraham Doughty on 9/15/22.
//

#include "Question.h"
#include <iomanip>
#include "Board.h"
#include "unistd.h"
#include "Player.h"

using namespace::std;

int main() {

    //loop control
    bool endGame = false;
    int demoLoopControl = 1;
    //user inputs
    string category, answer, name, buzzer, chooser;
    int value, qIndex;

    Player p1, p2, p3;

    vector<Question> questions;

    //just formatting
    cout << "----------------------------------------------------------------------" << endl << endl;

    //this function is set to only grab the first 30 questions for demo purposes. It will eventually
    //populate the full csv and then randomly select categories from the correct rounds.
    getDataFromFile("../JEOPARDY_CSV.csv", questions);

    //initialize board (will also sort the vector)
    Board demo = Board(questions, Board::JEOPARDY);

    //get player names and print instructions
    //NOTE: no input validation. It's 2022. If you want to go by "-3/8", who am I to say that's invalid?
    cout << "Player 1, enter your name: ";
    getline(cin, name);
    p1.setName(name);
    cout << endl << "Player 2, enter your name: ";
    getline(cin, name);
    p2.setName(name);
    cout << endl << "Player 3, enter your name: ";
    getline(cin, name);
    p3.setName(name);

    chooser = p1.getName();

    //explain buzzing in
    cout << endl << "To answer a question, you must be the first player to buzz in by entering your buzzer key." << endl;
    cout << "Buzzer Keys" << endl << "-----------" << endl << "Player 1: a" << endl << "Player 2: b" << endl << "Player 3: l" << endl;
    cout << endl;

    sleep(4);

    //for some reason the first 30 aren't a complete round and we get a 400 point question from an
    //entirely different category in on of the 1000 point spots... I'll fix this too.
    demo.displayBoard();

    //main game loop
    while (!endGame) {

        //reset answer for loop
        answer = "";

        //prompt and validate
        cout << chooser << ", pick a category: ";
        getline(cin, category);

        while (!(case_insensitive_match(category, (questions[0].getCategory()))) &&
                !(case_insensitive_match(category, (questions[1].getCategory()))) &&
                !(case_insensitive_match(category, (questions[2].getCategory()))) &&
                !(case_insensitive_match(category, (questions[3].getCategory()))) &&
                !(case_insensitive_match(category, (questions[4].getCategory()))) &&
                !(case_insensitive_match(category, (questions[5].getCategory())))) {

            cout << "Invalid. Please select a valid category: ";
            getline(cin, category);
        }

        //prompt and validate
        cout << "Pick a value: ";
        cin >> value;

        while  (((value != (questions[0].getValue())) &&
                (value != (questions[5].getValue())) &&
                (value != (questions[11].getValue())) &&
                (value != (questions[17].getValue())) &&
                (value != (questions[23].getValue())) &&
                (value != (questions[29].getValue()))
                ) || !cin) {
            cout << "Invalid. Please select a valid value: ";

            cin.clear();
            cin.ignore();
            cin >> value;

        }

        //find the question that has been requested by the user
        for (int i = 0; i < 30; ++i) {
            if (case_insensitive_match(questions[i].getCategory(), category) && (questions[i].getValue() == value)) {
                cout << questions[i].getQuestion() << endl;
                qIndex = i;
                i=30; //exits the loop early once the question is found
            }
        }

        //this is a lie. there is no timer
        cout << endl << "10 seconds to respond... Please buzz in before answering" << endl;

        getline(cin, buzzer);

        while (buzzer != "a" && buzzer != "b" && buzzer != "l") {
            cout << "Buzz in with 'a' 'b' or 'l': " << endl;
            getline(cin, buzzer);
        }

        if (buzzer == "a")
            cout << p1.getName() << ", enter your answer: ";
        if (buzzer == "b")
            cout << p2.getName() << ", enter your answer: ";
        if (buzzer == "l")
            cout << p3.getName() << ", enter your answer: ";

        //No validation for answers because you should be able to answer a question in any way... You could be
        //wrong and there isn't any rule in jeopardy saying you can't answer with a negative number, etc...
        //You might just be very wrong.
        while (answer == "") {
            getline(cin, answer);
        }

        //response and scoring logic
        if (case_insensitive_match(answer, questions[qIndex].getAnswer())) {
            if (buzzer == "a") {
                p1.setScore(p1.getScore() + questions[qIndex].getValue());
                cout << "Correct! That brings your score to: " << p1.getScore() << endl;
                chooser = p1.getName();
            }
            if (buzzer == "b") {
                p2.setScore(p2.getScore() + questions[qIndex].getValue());
                cout << "Correct! That brings your score to: " << p2.getScore() << endl;
                chooser = p2.getName();
            }
            if (buzzer == "l") {
                p3.setScore(p3.getScore() + questions[qIndex].getValue());
                cout << "Correct! That brings your score to: " << p3.getScore() << endl;
                chooser = p3.getName();
            }
        }
        else {
            if (buzzer == "a") {
                p1.setScore(p1.getScore() - questions[qIndex].getValue());
                cout << "Unfortunately that is incorrect." << endl;
                cout << "We were looking for: " << questions[qIndex].getAnswer() << endl;
                cout << "That drops your score down to: " << p1.getScore() << endl;
            }
            if (buzzer == "b") {
                p2.setScore(p2.getScore() - questions[qIndex].getValue());
                cout << "Unfortunately that is incorrect." << endl;
                cout << "We were looking for: " << questions[qIndex].getAnswer() << endl;
                cout << "That drops your score down to: " << p2.getScore() << endl;
            }
            if (buzzer == "l") {
                p3.setScore(p3.getScore() - questions[qIndex].getValue());
                cout << "Unfortunately that is incorrect." << endl;
                cout << "We were looking for: " << questions[qIndex].getAnswer() << endl;
                cout << "That drops your score down to: " << p3.getScore() << endl;
            }
        }

        //update question status for board display
        questions[qIndex].setStatus(Question::PICKED);
        demo.setQuestions(questions);

        //just to give time to read before the board prints again
        sleep(4);

        cout << endl << "Scoreboard" << endl << "------------" << endl;
        cout << p1.getName() << ": " << p1.getScore() << endl;
        cout << p2.getName() << ": " << p2.getScore() << endl;
        cout << p3.getName() << ": " << p3.getScore() << endl;

        //update w3 with python
        string commandString = "python3 ../updateScore.py " + p1.getName() + " " + to_string(p1.getScore()) + " "
                                                         + p2.getName() + " " + to_string(p2.getScore()) + " "
                                                         + p3.getName() + " " + to_string(p3.getScore());

        const char *command = commandString.c_str();

        system(command);


        sleep(4);

        //formatting
        cout << "---------------------------------" << endl;

        //print board for next question choice
        demo.displayBoard();

        //just for demo to exit loop. Obviously game isn't finished yet. I'm hoping to develop it for
        //the rest of the semester.
        demoLoopControl++;

        if (demoLoopControl == 5) {
            endGame = true;
        }
    }

    return 0;
}
