@echo off
:BEGIN
g++ -Wall -pedantic main.cpp -o test.exe
test.exe
pause
goto BEGIN