rem @echo off
rmdir /S /Q Win
mkdir Win
cd Win
cmake ../ -G "Visual Studio 17 2022"
copy ..\wxModularHost.sln64 .\wxModularHost.sln
cd ..
