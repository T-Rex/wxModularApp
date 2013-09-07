rem @echo off
IF "%1" == "" GOTO NO_PARAMS
IF "%1" == "x86" GOTO CMAKE_86
IF "%1" == "86"  GOTO CMAKE_86
IF "%1" == "x64" GOTO CMAKE_64
IF "%1" == "64"  GOTO CMAKE_64

ECHO %1
ECHO "Nothing to do"
GOTO End

:CMAKE_86
	ECHO "Configuring for x86"
	cm86.bat
	GOTO End
:CMAKE_64
	ECHO "Configuring for x64"
	cm64.bat
	GOTO End
:NO_PARAMS
	ECHO "No parameters specified"
	IF EXIST "%ProgramW6432%" GOTO CMAKE_64
	GOTO CMAKE_86
:End
