@echo off  
:loop  
    RAN.exe %random% > data.in
    AC.exe < data.in > AC.out
    WA.exe < data.in > WA.out
    fc AC.out WA.out 
if not errorlevel 1 goto loop  
pause
goto loop