#!/bin/bash
 
printf "\n\rCompilando..."
source ~/Documents/UFRN/SO/Lab/Dev/ti-processor-sdk-linux-am335x-evm-02.00.01.07/linux-devkit/environment-setup
arm-linux-gnueabihf-gcc -o ordenacao ordenacao.c
 
printf "\n\rCopiando para a BBB (em /home/debian)..."
sshpass -p 'temppwd' scp ordenacao debian@192.168.7.2:~/Documents/Projeto1-SO/
 
printf "\n\rConectando-se na BBB\n\n\r"
sshpass -p 'temppwd' ssh debian@192.168.7.2