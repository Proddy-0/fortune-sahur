@echo off
:: VERSAO 2.1 - Salva o .exe na mesma pasta do .cpp

:: 1. Verifica se um nome de arquivo foi fornecido
IF "%~1"=="" (
    echo.
    echo [ERRO] Voce nao especificou um arquivo para compilar!
    echo Uso: compila.bat seu_arquivo.cpp
    echo.
    pause
    exit /b
)

echo.
echo [ Compilando o arquivo: %1 ]
echo.

:: 2. Compila o arquivo, especificando o CAMINHO COMPLETO para o arquivo de saida.
::    As aspas garantem que funcione mesmo se houver espacos no nome da pasta.
g++ -g %1 -o "%~dp1%~n1.exe" && (
    echo.
    echo [ Compilacao bem-sucedida! ]
    echo [ Arquivo .exe criado em: %~dp1 ]
    echo [ Executando o programa... ]
    echo -------------------------------------
    
    :: 3. Executa o programa usando seu caminho completo
    "%~dp1%~n1.exe"
    
    echo -------------------------------------
    echo.
    echo [ Programa finalizado. ]
)

echo.
pause