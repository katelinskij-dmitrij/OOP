set PROGRAM="%~1"

rem �஢��塞 ����� ��� ��ࠬ��஢ ��������� ��ப�
echo �஢��塞 ����� ��� ��ࠬ��஢ ��������� ��ப� 
%PROGRAM% > output.txt
if not errorlevel 1 goto err

rem �஢��塞 ����� � ���������騬 䠩���
echo �஢��塞 ����� � ���������騬 䠩���
%PROGRAM% undefined.txt matrix2.txt > output.txt
if not errorlevel 1 goto err 

rem �஢��塞 ����� � �������� ����殩
echo �஢��塞 ����� � �������� ����殩
%PROGRAM% incompletematrix.txt > output.txt
if not errorlevel 1 goto err 
                                            
rem  �஢��塞 ����� � ����栬� � �ࠢ������ �⢥�
echo �஢��塞 ����� � ����栬� � �ࠢ������ �⢥�
%PROGRAM% matrix1.txt matrix2.txt > output.txt
if errorlevel 1 goto err 
fc output.txt multmatrix12.txt
if errorlevel 1 goto err 

rem ����ୠ� �஢�ઠ � ����栬� � �ࠢ����� �⢥�
echo ����ୠ� �஢�ઠ � ����栬� � �ࠢ����� �⢥�
%PROGRAM% matrix3.txt matrix4.txt > output.txt
if errorlevel 1 goto err 
fc output.txt multmatrix34.txt
if errorlevel 1 goto err 

echo Program testing succeeded.
exit 0

:err
echo Tests failed.
exit 1