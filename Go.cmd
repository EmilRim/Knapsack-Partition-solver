@echo off

if .%USERDOMAIN% == .SavasPC goto :savasPC
REM MIF PC configuration
path C:\PROGRA~2\Dev-Cpp\MinGW64\bin\;%path%
mingw32-make.exe
goto :toliau

:savasPC
make

:toliau
echo Vykdomi Particijos Problemos testai... > rezultatai.txt

echo Testuojama su testas1.txt failu...
main.exe testas1.txt >> rezultatai.txt

echo Testuojama su testas2.txt failu...
main.exe testas2.txt >> rezultatai.txt

echo Testuojama su testas3.txt failu...
main.exe testas3.txt >> rezultatai.txt

echo Testuojama su testas4.txt failu...
main.exe testas4.txt >> rezultatai.txt

echo Tikrinamas stdin įvedimas su testas1.txt failu...
main.exe < testas1.txt >> rezultatai.txt

echo Visi Particijos Problemos testai baigti. Rezultatai saugomi rezultatai.txt faile.
