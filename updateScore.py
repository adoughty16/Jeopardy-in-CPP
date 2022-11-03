# Python program takes command line arguments and uses it to create html doc that formats jeopardy scores.
 
import sys
import os

player1 = sys.argv[1]
score1 = sys.argv[2]
player2 = sys.argv[3]
score2 = sys.argv[4]
player3 = sys.argv[5]
score3 = sys.argv[6]
  
fileOut = open("scores.html", "w")

fileOut.write("<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n<title>Jeopardy Scores</title>\n</head>\n<body>")
fileOut.write("<h1>Jeopardy Scores!</h1>\n<p>")

fileOut.write(player1 + " score: " + score1 + "<br>\n")
fileOut.write(player2 + " score: " + score2 + "<br>\n")
fileOut.write(player3 + " score: " + score3)

fileOut.write("</p>\n</body>\n</html>")

fileOut.close()

#adds file to server with command line
os.system("scp scores.html asdought@w3.uvm.edu:www-root/")