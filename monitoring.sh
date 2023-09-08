#!/bin/bash

# ARCHITECTURE
	arch=$(uname -a)

# PHYSICAL CPU
	pCPU=$(cat /proc/cpuinfo | grep "physical id" | sort | uniq | wc -l)

# VIRTUAL CPU
	vCPU=$(cat /proc/cpuinfo | grep "processor" | wc -l)

# MEMEMORY
	mem_used=$(free --mega | grep "Mem:" | awk '{print $3}')
	mem_total=$(free --mega | grep "Mem:" | awk '{print $2}')
	mem_utilization=$(free --mega | grep "Mem:" | awk '{printf "%.2f%%", $3/$2*100}')

# DISK
	disk_used=$(df -Bm | grep "^/dev/" | grep -v "boot" | awk '{used_total += $3}END{printf("%d", used_total)}')
	disk_total=$(df -BG | grep '^/dev/' | grep -v '/boot' | awk '{total += $2} END {printf("%d", total)}')
	disk_utilization=$(df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{used_total += $3} {total+= $2} END {printf("%.0f%%"), used_total/total*100}')

# CPU LOAD
	CPU_load=$(top -bn1 | grep "Cpu" | awk '{print $2}' | tr -d '%')

# LAST REBOOT
	last_boot=$(who -b | awk '{print $3" "$4}')

# LVM USE
	lvm=$(if [$(lsblk | grep "lvm" | wc -l) = 0]; then echo no; else echo yes; fi)

# ESTABLISHED TCP CONNECTIONS
	tcp=$(ss -s | grep -v "TCP:" | grep TCP | awk '{print $3}')

# USER LOG
	user_log=$(who | wc -l)

# NETWORK
	ip=$(hostname -I)
	mac=$(ip link | grep link/ether | awk '{print $2}')

# SUDO LOG
	sudo=$(journalctl _COMM=sudo | grep COMMAND | wc -l)
	

wall " 	#Architecture: $arch
	#CPU physical: $pCPU
	#vCPU: $vCPU
	#Memory Usage: $mem_used/${mem_total}MB ($mem_utilization)
	#Disk Usage: $disk_used/${disk_total}Gb ($disk_utilization)
	#CPU load: $CPU_load
	#Last boot: $last_boot
	#LVM use: $lvm
	#Connections TCP: $cTCP ESTABLISHED
	#User log: $user_log
	#Network: IP $ip ($mac)
	#Sudo: $sudo cmd"
