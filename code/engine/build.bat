REM Build script for engine
@ECHO OFF
SetLocal EnableDelayedExpansion

REM Get a list of all the .c files
SET cFilenames=
FOR /r %%f in (*.c) do (
    SET cFilenames=!cFilenames! %%f
)

REM echo "Files:" %cFilenames%

SET assembly=engine
SET compilerFlags=-g -shared -Wvarargs -Wall -Werror
REM -Wall -Werror
SET includeFlags=-Isrc -I%VULKAN_SDK%/include
SET linkerFlags=-luser32 -lvulkan-1 -L%VULKAN_SDK%Lib
SET defines=-D_DEBUG -DKEXPORT -D_CRT_SECURE_NO_WARNINGS

ECHO "Building %assembly%..."
clang %cFilenames% %compilerFlags% -o ../bin/%assembly%.dll %defines %includeFlags% %linkerFlags%