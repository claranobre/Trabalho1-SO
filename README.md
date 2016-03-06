### Trabalho 1 de Sistemas Operacionais

- Esse projeto consiste em fazer uma análise temporal da execução dos algoritmos de ordenação Bubble Sort, Quick Sort e Selection Sort na placa BeagleBone Black.
- Estamos utilizando os métodos time e clock para calcular o tempo de execução.

# Como executar esse projeto

# Computador
- **O usuário precisa ter uma máquina Linux instalada para a execução desse projeto**
- **No Terminal Linux executar as seguintes tarefas:**
- **SDK Texas Instruments**
○ Download do SDK
○ SDK Texas Instruments (~2.2Gb) - http://goo.gl/q8zaor
○ chmod +x nomedoarquivobaixado
○ ./nomedoarquivobaixado
○ Instalação: next, next, next ...
- **Instalar Qt Designer**
○ Download
○ http://www.qt.io/download-open-source/
○ Dica: fazer o download da versão offline
■ Linux 32bits: http://download.qt.io/official_releases/qt/5.5/5.5.1/qt-opensource-linux-x86-5.5.1.run
■ Linux 64bits: http://download.qt.io/official_releases/qt/5.5/5.5.1/qt-opensource-linux-x64-5.5.1.run
○ Instalar
○ chmod +x arquivobaixado
○ ./arquivobaixado
- **Atualização do Sistema [Debian Jessie]**
○ Download
wget https://rcn-ee.com/rootfs/2016-02-11/elinux/debian-8.3-console-armhf-2016-02-11.tar.xz
○ Unpack
tar xf debian-8.3-console-armhf-2016-02-11.tar.xz
cd debian-8.3-console-armhf-2016-02-11
○ Identificando o microSD
sudo ./setup_sdcard.sh --probe-mmc
○ Gravando a imagem do sistema no microSD
sudo ./setup_sdcard.sh --mmc /dev/mmcblk0 --dtb beaglebone
//Esse procedimento pode demorar 5~10 minutos//
- **Acessando o sistema**
Senha: temppwd
ssh debian@192.168.7.2
- **Encaminhando requisições de rede [BBB → Host]**
sudo su
○ eth0 é a interface de rede do Host, enquanto que eth1 é a interface de rede da BBB
iptables --table nat --append POSTROUTING --out-interface eth0 -j MASQUERADE
iptables --append FORWARD --in-interface eth1 -j ACCEPT
echo 1 > /proc/sys/net/ipv4/ip_forward
# BeagleBone Black (BBB)
○ realizar os comandos como root
sudo su
route add default gw 192.168.7.1
echo "nameserver 8.8.8.8" >> /etc/resolv.conf
/etc/init.d/networking restart
○ Atualizar os pacotes
apt-get update