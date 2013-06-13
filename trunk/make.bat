@echo off

call "%VS100COMNTOOLS%vsvars32.bat"
set projectname=blackJack

%QTDIR%/bin/qmake.exe -t vcapp -o %projectname%.vcxproj %projectname%.pro

echo ^|
echo ^|  Building finished
echo ^|

