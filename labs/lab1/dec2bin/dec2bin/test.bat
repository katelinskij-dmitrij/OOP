set PROGRAM="%~1"

REM �������� �� ������ ��������� ��� �������� ��������
%PROGRAM% 
if NOT ERRORLEVEL 1 goto err

REM �������� �� ������ ��������� � �������� ���������
%PROGRAM% string
if NOT ERRORLEVEL 1 goto err

REM �������� �� ������ ��������� � ������������� ���������
%PROGRAM% -253
if NOT ERRORLEVEL 1 goto err

REM �������� �� ������ ��������� � ������ ���������
%PROGRAM% 15 > output.txt
if ERRORLEVEL 1 goto err
FC /B output.txt 1111.txt
if ERRORLEVEL 1 goto err

echo Program testing succeeded.
exit 0

:err
echo Program testing failed.
exit 1