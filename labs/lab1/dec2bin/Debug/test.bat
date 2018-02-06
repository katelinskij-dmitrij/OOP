set PROGRAM="%~1"

rem Проверка на запуск программы без указания значения
dec2bin.exe 
if NOT ERRORLEVEL 1 goto err

rem Проверка на запуск программы с неверным значением
dec2bin.exe string
if NOT ERRORLEVEL 1 goto err

rem Проверка на запуск программы с отрицательным значением
dec2bin.exe -253
if NOT ERRORLEVEL 1 goto err

rem Проверка на запуск программы с верным значением
dec2bin.exe 15
if ERRORLEVEL 1 goto err

echo Program testing succeeded.
exit 0

:err
echo Program testing failed.
exit 1