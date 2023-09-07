#!/bin/bash

###############
#   Content   #
###############

# Temporary output file
FILE="monitoring_msg"

# OS & Kernel
# -p CPU arch, -v Kernel ver, -o os, -s Kernel name, -m hardware name (arch)
KER=$(uname -vmso)

# CPUs
CPU=$(lscpu | grep "Model name" | wc -l)
VCPU=$(grep processor /proc/cpuinfo | wc -l)

# RAM
RAM_TOT=$(free --mega | awk 'NR==2' | awk '{print$2}')
RAM_USD=$(free --mega | awk 'NR==2' | awk '{print$3}')
RAM_USG=$(($RAM_USD * 100 / $RAM_TOT))

# Disk Memory
MEM_TOT=$(df --total -BG | grep total | awk '{print$2}')
MEM_USD=$(df --total -BG | grep total | awk '{print$3}' | sed 's/G//')
MEM_USG=$(df --total | grep total | awk '{print$5}')

# CPU Usage
CPU_USG=$(awk '{u=$2+$4; t=$2+$4+$5; if (NR==1){u1=u; t1=t;} else print ($2+$4-u1) * 100 / (t-t1) "%"; }' <(grep 'cpu ' /proc/stat) <(sleep 1;grep 'cpu ' /proc/stat))

# Last Boot
LST_RBT=$(last --time-format=full reboot | awk 'NR==1' | cut -c 40-63)

# LVM Use


# Established connections
TCP_EST=$(ss -t | grep -v State | wc -l)

# Users logged in
USR_LOG=$(who | wc -l)

# IPv4 & MAC
IP=$(ip a show enp0s3 | awk '/inet / {print$2}' | cut -d '/' -f 1)
MAC=$(ip link show enp0s3 | awk '/ether / {print$2}')

# Sudo cmd
SUDO_NB=$(sudo journalctl _COMM=sudo | grep COMMAND | wc -l)

#####################
#   Msg Generation  #
#####################

if test -f "$FILE"
then
    rm -f $FILE
fi

echo "      #Architecture: $KER" >> $FILE
echo "      #CPU physical : $CPU" >> $FILE
echo "      #vCPU : $VCPU" >> $FILE
echo "      #Memory Usage: ${RAM_USD}/${RAM_TOT}MB (${RAM_USG}%)" >> $FILE
echo "      #Disk Usage: ${MEM_USD}/${MEM_TOT} (${MEM_USG})" >> $FILE
echo "      #CPU load: $CPU_USG" >> $FILE
echo "      #Last boot: $LST_RBT" >> $FILE
echo "      #LVM use: " >> $FILE
echo "      #Connexions TCP : $TCP_EST ESTABLISHED" >> $FILE
echo "      #User log: $USR_LOG" >> $FILE
echo "      #Network: IP $IP ($MAC)" >> $FILE
echo "      #Sudo: $SUDO_NB cmd" >> $FILE

wall $FILE
rm -f $FILE

exit
