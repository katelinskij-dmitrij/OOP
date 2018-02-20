set PROGRAM="%~1"

rem ѕровере€ем запуск без параметров командной строки
%PROGRAM% > output.txt
if not errorlevel 1 goto err

rem ѕровер€ем запуск с несуществующим файлом
%PROGRAM% undefined.txt matrix2.txt > output.txt
if not errorlevel 1 goto err 

rem ѕровер€ем запуск с неполной матрицой
%PROGRAM% incompletematrix.txt > output.txt
if not errorlevel 1 goto err 
                                            
rem  ѕровер€ем запуск с матрицами и сравниваем ответ
%PROGRAM% matrix1.txt matrix2.txt > output.txt
if errorlevel 1 goto err 
fc output.txt multmatrix12.txt
if errorlevel 1 goto err 

rem ѕовторна€ проверка с матрицами и сравнение ответа
%PROGRAM% matrix3.txt matrix4.txt > output.txt
if errorlevel 1 goto err 
fc output.txt multmatrix34.txt
if errorlevel 1 goto err 

echo Program testing succeeded.
exit 0

:err
echo Tests failed.
exit 1