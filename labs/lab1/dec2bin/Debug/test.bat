REM �������� �� ������ ��������� ��� �������� ��������
dec2bin.exe 
if NOT ERRORLEVEL 1 goto err

REM �������� �� ������ ��������� � �������� ���������
dec2bin.exe string
if NOT ERRORLEVEL 1 goto err

REM �������� �� ������ ��������� � ������������� ���������
dec2bin.exe -253
if NOT ERRORLEVEL 1 goto err

REM �������� �� ������ ��������� � ������ ���������
dec2bin.exe 15 > output.txt
if ERRORLEVEL 1 goto err
FC /B output.txt 1111.txt
if ERRORLEVEL 1 goto err

echo Program testing succeeded.
exit 0

:err
echo Program testing failed.
exit 1