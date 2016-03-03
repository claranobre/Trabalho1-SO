#!/bin/bash
 
printf "\n\rCompilando..."
source ~/ti-processor-sdk-linux-am335x-evm-02.00.01.07/linux-devkit/environment-setup
arm-linux-gnueabihf-g++ -o main main.cpp
 
printf "\n\rCopiando para a BBB (em /home/debian)..."
sshpass -p 'temppwd' scp main debian@192.168.7.2:~
 
printf "\n\rConectando-se na BBB\n\n\r"
sshpass -p 'temppwd' ssh debian@192.168.7.2
