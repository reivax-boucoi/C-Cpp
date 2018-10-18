@echo off
:BEGIN
g++ -Wall -pedantic main.cpp -o test.sh
./test.sh
pause
goto BEGIN
