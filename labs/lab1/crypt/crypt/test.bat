set PROGRAM="%~1"

rem Запуск программы без параметров
echo Запуск программы без параметров 
%PROGRAM%
if not errorlevel 1 goto err

rem Запуск программы с 2 параметрами
echo Запуск программы с 2 параметрами 
%PROGRAM% crypt
if not errorlevel 1 goto err

rem Запуск программы с 3 параметрами
echo Запуск программы с 3 параметрами 
%PROGRAM% crypt input.txt
if not errorlevel 1 goto err

rem Запуск программы с 4 параметрами
echo Запуск программы с 4 параметрами 
%PROGRAM% crypt input.txt output.txt
if not errorlevel 1 goto err

rem Запуск программы с неверными параметрами
echo Запуск программы с неверными параметрами 
%PROGRAM% crypt nofile.txt output.txt 10
if not errorlevel 1 goto err

rem Запуск программы с неверными параметрами
echo Запуск программы с неверными параметрами 
%PROGRAM% crypt input1.txt output1.txt 256
if not errorlevel 1 goto err

rem Запуск программы с верными параметрами
echo Запуск программы с верными параметрами 
%PROGRAM% crypt input1.txt output1.txt 10
if errorlevel 1 goto err
fc output1.txt trueOutput1.txt
if errorlevel 1 goto err

rem Запуск программы с верными параметрами
echo Запуск программы с верными параметрами 
%PROGRAM% crypt input2.txt output2.txt 200
if errorlevel 1 goto err
fc output2.txt trueOutput2.txt
if errorlevel 1 goto err

rem Запуск программы с верными параметрами
echo Запуск программы с верными параметрами 
%PROGRAM% decrypt input3.txt output3.txt 10
if errorlevel 1 goto err
fc output3.txt trueOutput3.txt
if errorlevel 1 goto err

rem Запуск программы с верными параметрами
echo Запуск программы с верными параметрами 
%PROGRAM% decrypt input4.txt output4.txt 200
if errorlevel 1 goto err
fc output4.txt trueOutput4.txt
if errorlevel 1 goto err

echo Program testing succeeded.
exit 0

:err
echo Tests failed.
exit 1