//
// Created by Abraham Doughty on 9/8/22.
//

#ifndef M1OEP_QUESTION_H
#define M1OEP_QUESTION_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

//class to create question objects
class Question {

private:
    int value;
    string round;
    string category;
    string question;
    string answer;

public:

    //this is public because main needs to be able to refer to these types and I can't remember
    //the correct way to do this
    enum Status {PICKED, UNPICKED} status;

    //default constructor
    Question();

    //regular constructor
    Question(string round, string category, int value, string question, string answer);

    //getters
    string getRound() const;

    int getValue() const;

    string getCategory() const;

    string getQuestion() const;

    string getAnswer() const;

    Status getStatus() const;

    //setters
    void setValue(int value);

    void setRound(string round);

    void setCategory(string category);

    void setQuestion(string question);

    void setAnswer(string answer);

    void setStatus(Status status);

    //overloaded operator
    friend bool operator < (const Question& a, const Question& b);

};

//this loads the questions vector. It is set to only load the first round of questions right now
//eventually it will work with another function to randomly select categories from the desired round
//from the csv
void getDataFromFile(string fileName, vector<Question>& questions);

//THIS IS NOT MY FUNCTION I FOUND IT ONLINE @tutorialspoint.com
//I put it in this .h file to keep it out of main. I'll move it eventually.
int case_insensitive_match(string s1, string s2);

#endif //M1OEP_QUESTION_H

