set PROGRAM="%~1"

rem ����� �ணࠬ�� ��� ��ࠬ��஢
echo ����� �ணࠬ�� ��� ��ࠬ��஢ 
%PROGRAM%
if not errorlevel 1 goto err

rem ����� �ணࠬ�� � 2 ��ࠬ��ࠬ�
echo ����� �ணࠬ�� � 2 ��ࠬ��ࠬ� 
%PROGRAM% crypt
if not errorlevel 1 goto err

rem ����� �ணࠬ�� � 3 ��ࠬ��ࠬ�
echo ����� �ணࠬ�� � 3 ��ࠬ��ࠬ� 
%PROGRAM% crypt input.txt
if not errorlevel 1 goto err

rem ����� �ணࠬ�� � 4 ��ࠬ��ࠬ�
echo ����� �ணࠬ�� � 4 ��ࠬ��ࠬ� 
%PROGRAM% crypt input.txt output.txt
if not errorlevel 1 goto err

rem ����� �ணࠬ�� � �����묨 ��ࠬ��ࠬ�
echo ����� �ணࠬ�� � �����묨 ��ࠬ��ࠬ� 
%PROGRAM% crypt nofile.txt output.txt 10
if not errorlevel 1 goto err

rem ����� �ணࠬ�� � �����묨 ��ࠬ��ࠬ�
echo ����� �ணࠬ�� � �����묨 ��ࠬ��ࠬ� 
%PROGRAM% crypt input1.txt output1.txt 256
if not errorlevel 1 goto err

rem ����� �ணࠬ�� � ���묨 ��ࠬ��ࠬ�
echo ����� �ணࠬ�� � ���묨 ��ࠬ��ࠬ� 
%PROGRAM% crypt input1.txt output1.txt 10
if errorlevel 1 goto err
fc output1.txt trueOutput1.txt
if errorlevel 1 goto err

rem ����� �ணࠬ�� � ���묨 ��ࠬ��ࠬ�
echo ����� �ணࠬ�� � ���묨 ��ࠬ��ࠬ� 
%PROGRAM% crypt input2.txt output2.txt 200
if errorlevel 1 goto err
fc output2.txt trueOutput2.txt
if errorlevel 1 goto err

rem ����� �ணࠬ�� � ���묨 ��ࠬ��ࠬ�
echo ����� �ணࠬ�� � ���묨 ��ࠬ��ࠬ� 
%PROGRAM% decrypt input3.txt output3.txt 10
if errorlevel 1 goto err
fc output3.txt trueOutput3.txt
if errorlevel 1 goto err

rem ����� �ணࠬ�� � ���묨 ��ࠬ��ࠬ�
echo ����� �ணࠬ�� � ���묨 ��ࠬ��ࠬ� 
%PROGRAM% decrypt input4.txt output4.txt 200
if errorlevel 1 goto err
fc output4.txt trueOutput4.txt
if errorlevel 1 goto err

echo Program testing succeeded.
exit 0

:err
echo Tests failed.
exit 1