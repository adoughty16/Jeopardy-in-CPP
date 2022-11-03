//
// Created by Abraham Doughty on 10/9/22.
//

#include "Question.h"
#include <algorithm>

using namespace::std;

Question::Question() {
    round = "default";
    value = -1;
    category = "default";
    question = "default";
    answer = "default";
    status = UNPICKED;
}

//regular constructor
Question::Question(string round, string category, int value, string question, string answer) {
this->round = round;
this->category = category;
this->value = value;
this->question = question;
this->answer = answer;
//all questions start unpicked
status = UNPICKED;
}

//getters
string Question::getRound() const {
    return round;
}

int Question::getValue() const {
    return value;
}

string Question::getCategory() const {
    return category;
}

string Question::getQuestion() const {
    return question;
}

string Question::getAnswer() const {
    return answer;
}

Question::Status Question::getStatus() const {
    return status;
}

//setters
void Question::setValue(int value) {
    this->value = value;
}

void Question::setRound(string round) {
    this->round = round;
}

void Question::setCategory(string category) {
    this->category = category;
}

void Question::setQuestion(string question) {
    this->question = question;
}

void Question::setAnswer(string answer) {
    this->answer = answer;
}

void Question::setStatus(Status status) {
    this->status = status;
}

//overloaded operator
bool operator < (const Question& a, const Question& b) {

    return (b.getCategory().compare(a.getCategory()) > 0);

}

void getDataFromFile(string fileName, vector<Question>& questions) {

    ifstream fileIn;
    fileIn.open(fileName);

    string header;
    if (fileIn) {
        getline(fileIn, header); //consumes header line
    }

    //declare variables to be read in from file
    string category, question, answer, junk, round, extra, stringValue;
    int value;
    char comma;

    int n = 0; //this is just for demo purposes to only load in one round.

    while (fileIn && fileIn.peek() != EOF && (n <30)) {

        //junk first two
        getline(fileIn, junk, ',');
        getline(fileIn, junk, ',');
        //read in round
        getline(fileIn, round, ',');
        //read in category
        getline(fileIn, category, ',');
        //read in value
        if (fileIn.peek() == '"') {
            //need to get rid of the comma in the number
            getline(fileIn, junk, '"');
            getline(fileIn, stringValue, '"');
            stringValue.erase(stringValue.begin()); //eliminates '$'
            stringValue.erase(stringValue.begin()+1); //eliminates ','
            value = stoi(stringValue);
            getline(fileIn, junk, ',');
        }
        else {
            //get rid of '$'
            getline(fileIn, junk, '$');
            fileIn >> value;
            getline(fileIn, junk, ',');
        }

        //read in question
        if (fileIn.peek() != '"') {  //if it doesn't start with quotations, read until the comma
            getline(fileIn, question, ',');
        }
        else {
            //if it starts with a quotation, load everything into question until you encounter a quotation mark
            //immediately followed by a comma
            question = "";
            do {
                getline(fileIn, extra, '"');
                question += extra;
            }
            while (fileIn.peek() != ',');
            getline(fileIn, junk, ',');
        }
        if (fileIn.peek() == ' ') {
            //make sure the comma isn't followed by a space. If it is, the question isn't over so
            //re-enter the do/while loop.
            do {
                getline(fileIn, extra, '"');
                question += extra;
            }
            while (fileIn.peek() != ',');
            getline(fileIn, junk, ',');
        }
        //read in answer
        getline(fileIn, answer, '\r');

        //put info into vector passed in from the method call
        questions.push_back(Question(round, category, value, question, answer));

        ++n;
    }

    fileIn.close();

}

//THIS IS NOT MY FUNCTION I FOUND IT ONLINE @tutorialspoint.com
//I put it in this .h file to keep it out of main. I'll move it eventually.
int case_insensitive_match(string s1, string s2) {
    //convert s1 and s2 into lower case strings
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    if (s1.compare(s2) == 0)
        return 1; //The strings are same
    return 0; //not matched
}