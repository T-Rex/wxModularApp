rem @echo off
rmdir /S /Q Win
mkdir Win
cd Win
cmake ../ -G "Visual Studio 11 Win64"
cd ..