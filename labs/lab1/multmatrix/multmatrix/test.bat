set PROGRAM="%~1"

rem Проверяем запуск без параметров командной строки
echo Проверяем запуск без параметров командной строки 
%PROGRAM% > output.txt
if not errorlevel 1 goto err

rem Проверяем запуск с несуществующим файлом
echo Проверяем запуск с несуществующим файлом
%PROGRAM% undefined.txt matrix2.txt > output.txt
if not errorlevel 1 goto err 

rem Проверяем запуск с неполной матрицой
echo Проверяем запуск с неполной матрицой
%PROGRAM% incompletematrix.txt > output.txt
if not errorlevel 1 goto err 
                                            
rem  Проверяем запуск с матрицами и сравниваем ответ
echo Проверяем запуск с матрицами и сравниваем ответ
%PROGRAM% matrix1.txt matrix2.txt > output.txt
if errorlevel 1 goto err 
fc output.txt multmatrix12.txt
if errorlevel 1 goto err 

rem Повторная проверка с матрицами и сравнение ответа
echo Повторная проверка с матрицами и сравнение ответа
%PROGRAM% matrix3.txt matrix4.txt > output.txt
if errorlevel 1 goto err 
fc output.txt multmatrix34.txt
if errorlevel 1 goto err 

echo Program testing succeeded.
exit 0

:err
echo Tests failed.
exit 1