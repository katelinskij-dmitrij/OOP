set PROGRAM="%~1"

REM Проверка на запуск программы без указания значения
%PROGRAM% 
if NOT ERRORLEVEL 1 goto err

REM Проверка на запуск программы с неверным значением
%PROGRAM% string
if NOT ERRORLEVEL 1 goto err

REM Проверка на запуск программы с отрицательным значением
%PROGRAM% -253
if NOT ERRORLEVEL 1 goto err

REM Проверка на запуск программы с верным значением
%PROGRAM% 15 > output.txt
if ERRORLEVEL 1 goto err
FC /B output.txt 1111.txt
if ERRORLEVEL 1 goto err

echo Program testing succeeded.
exit 0

:err
echo Program testing failed.
exit 1