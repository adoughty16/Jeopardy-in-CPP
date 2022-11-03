# Jeopardy-in-CPP

This is a program that simulates Jeopardy!
It draws from a csv containing over 200,000 questions that have been used on Jeopardy in the last 30 years.

The game is formatted for 3 players sharing a keyboard. Each player will use a different keystroke to signal their buzzer.

Currently the game is only ready to play one round. Double and Final Jeopardy rounds are in the works.

main.cpp calls a python script that generates a .html that is subsequently uploaded to a silk server using CLI. This .html doc contains updated player scores.

** The selection sort algorithm was not authored by me. It comes from my c++ class and was written by my professor, Lisa Dion. I only made very slight modifications to her code. **