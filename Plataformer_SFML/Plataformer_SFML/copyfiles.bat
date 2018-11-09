::Copia de archivos 

@echo off
echo copiando archivos ...

set targetDir=%1

set solutionDir=%2

set configuration=%3

MKDIR "%targetDir%res"
XCOPY "%solutionDir%res" "%targetDir%res" /E /Y /S

if %configuration% == Release (
	XCOPY "%solutionDir%libs\SFML-2.5.1\bin\sfml-graphics-2.dll" "%targetDir%" /E /Y /S
	XCOPY "%solutionDir%libs\SFML-2.5.1\bin\sfml-system-2.dll" "%targetDir%" /E /Y /S
	XCOPY "%solutionDir%libs\SFML-2.5.1\bin\sfml-window-2.dll" "%targetDir%" /E /Y /S
)
if %configuration% == Debug (
	XCOPY "%solutionDir%libs\SFML-2.5.1\bin\sfml-graphics-d-2.dll" "%targetDir%" /E /Y /S
	XCOPY "%solutionDir%libs\SFML-2.5.1\bin\sfml-system-d-2.dll" "%targetDir%" /E /Y /S
	XCOPY "%solutionDir%libs\SFML-2.5.1\bin\sfml-window-d-2.dll" "%targetDir%" /E /Y /S
)