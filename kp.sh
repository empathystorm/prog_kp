#!/bin/bash

while [ 1 ]; do
    clear
    echo "1- посмотреть код программы"
    echo "2- скомпилировать программу"
    echo "3- запустить программу"
    echo "4- wxMaxima- контрольный расчёт"
    echo "5- wxMaxima- результат вычислений программы"
    echo "6- пояснительная записка (ГОСТ)"
    echo "7- выйти из скрипта"
    echo -n "Введите команду: "

    read sel
    
    case $sel in
    1)
    nano main.c functions.c functions.h;;
    2)
    gcc -Wall -o output main.c functions.h functions.c -lm;;
    3)
    ./output;;
    4)
    /bin/wxmaxima contr_calc.wxmx;;
    5)
    /bin/wxmaxima proc_res.wxmx;;
    6)
    libreoffice --writer 'ГОСТ 19.402-78.odt';;
    7)
    clear
    exit;;
    *)
    echo "Введена неправильная команда"
    read;;
    esac
done
