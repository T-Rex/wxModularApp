rem @echo off
rmdir /S /Q Win
mkdir Win
cd Win
cmake ../ -G "Visual Studio 17 2022" -A Win32
copy ..\wxModularHost.sln32 .\wxModularHost.sln
cd ..
