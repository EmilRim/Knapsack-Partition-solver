@echo off

if .%USERDOMAIN% == .SavasPC goto :savasPC
REM MIF PC configuration
path C:\PROGRA~2\Dev-Cpp\MinGW64\bin\;%path%
mingw32-make.exe
goto :toliau

:savasPC
make

:toliau
echo Running Partition Problem Tests... > result.txt

echo Running test with testas1.txt...
main.exe testas1.txt >> result.txt

echo Running test with testas2.txt...
main.exe testas2.txt >> result.txt

echo Running test with testas3.txt...
main.exe testas3.txt >> result.txt

echo Running test with testas4.txt...
main.exe testas4.txt >> result.txt

echo Testing stdin input with testas1.txt...
main.exe < testas1.txt >> result.txt

echo All Partition Problem tests finished. Results are in result.txt.
