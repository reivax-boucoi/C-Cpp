@echo off
:BEGIN
nbToLetters.cpp
g++ -Wall -pedantic nbToLetters.cpp -o test.exe
test.exe
echo program ended !
PAUSE
goto BEGIN