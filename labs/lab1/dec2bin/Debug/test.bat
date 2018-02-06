set PROGRAM="%~1"

rem �������� �� ������ ��������� ��� �������� ��������
dec2bin.exe 
if NOT ERRORLEVEL 1 goto err

rem �������� �� ������ ��������� � �������� ���������
dec2bin.exe string
if NOT ERRORLEVEL 1 goto err

rem �������� �� ������ ��������� � ������������� ���������
dec2bin.exe -253
if NOT ERRORLEVEL 1 goto err

rem �������� �� ������ ��������� � ������ ���������
dec2bin.exe 15
if ERRORLEVEL 1 goto err

echo Program testing succeeded.
exit 0

:err
echo Program testing failed.
exit 1