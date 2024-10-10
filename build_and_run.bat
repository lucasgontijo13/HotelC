@echo off
gcc main.c reservasTXT.c ReservasBin.c menu.c memoria.c funcoes.c arquivosTXT.c ArquivosBin.c -o hotel_trabalho.exe
if %ERRORLEVEL% neq 0 exit /b %ERRORLEVEL%
hotel_trabalho.exe
