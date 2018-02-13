set PROGRAM="%~1"

REM �������� �� ������ ��������� ��� �������� ������
%PROGRAM% 
if NOT ERRORLEVEL 1 goto err

REM �������� �� ������ ��������� � �������������� ������
%PROGRAM% fileeeeeeee.txt
if NOT ERRORLEVEL 1 goto err

REM �������� �� ������ ��������� � ������������ � �������������� �������
%PROGRAM% file1.txt fileeeeeeee.txt
if NOT ERRORLEVEL 1 goto err

REM �������� �� ������ ��������� � ������������� �������
%PROGRAM% file1.txt file2.txt > output.txt
if not ERRORLEVEL 1 goto err
FC /B output.txt true.txt
if ERRORLEVEL 1 goto err

echo Program testing succeeded.
exit 0

:err
echo Program testing failed.
exit 1