@echo off
echo Compilando o projeto HotelC...

gcc main.c menu.c funcoes.c memoria.c ArquivosBin.c arquivosTXT.c ReservasBin.c reservasTXT.c -o hotel.exe -std=c99

echo.
echo Sucesso! O arquivo hotel.exe foi criado.
echo Pressione qualquer tecla para sair...
pause > nul