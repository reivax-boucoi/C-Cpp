@echo off
:BEGIN
main.c
g++ -Wall -pedantic main.c -o test.exe
test.exe
echo program ended !
PAUSE
goto BEGIN