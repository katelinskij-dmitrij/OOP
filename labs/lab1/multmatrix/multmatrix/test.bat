set PROGRAM="%~1"

rem ���������� ������ ��� ���������� ��������� ������
%PROGRAM% > output.txt
if not errorlevel 1 goto err

rem ��������� ������ � �������������� ������
%PROGRAM% undefined.txt matrix2.txt > output.txt
if not errorlevel 1 goto err 

rem ��������� ������ � �������� ��������
%PROGRAM% incompletematrix.txt > output.txt
if not errorlevel 1 goto err 
                                            
rem  ��������� ������ � ��������� � ���������� �����
%PROGRAM% matrix1.txt matrix2.txt > output.txt
if errorlevel 1 goto err 
fc output.txt multmatrix12.txt
if errorlevel 1 goto err 

rem ��������� �������� � ��������� � ��������� ������
%PROGRAM% matrix3.txt matrix4.txt > output.txt
if errorlevel 1 goto err 
fc output.txt multmatrix34.txt
if errorlevel 1 goto err 

echo Program testing succeeded.
exit 0

:err
echo Tests failed.
exit 1