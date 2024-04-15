### What is a Virtual Machine and how does it work?

A virtual machine is a software program that emulates the hardware of a physical computer. It enables you to run multiple operating systems on a single physical computer, each operating system running in its own virtual environment. The physical computer on which the virtual machine is installed is called the host machine. The host machine's hardware is used by the virtual machine, allowing the virtual machine to access the same CPU, memory, and storage as the host machine. The host machine runs a hypervisor which is a program that allows multiple operating systems to utilize the same hardware. The hypervisor acts as a mediator between the hardware and the operating systems, distributing the hardware resources to the various operating systems as needed. So, the operating system runs in a virtual environment with hypervisor help, and gives the impression to the operating system that it is running on a physical machine. Virtual machine allows to easily switch between operating systems and applications on the same computer without having to restart the host machine.


### What is your choice of Operating System?

The chosen operating system is Debian, because it is recommended by the subject if you are new to the world of system administration. This is because Debian is known for being a stable and reliable operating system, with a strong track record of performance and security. It is also widely used in both personal and enterprise environments, meaning that there is a large community of users and a wealth of online resources available to help you get started with using and managing a Debian system.


### What are the basic differences between Rocky and Debian?

Rocky Linux is a new Linux distribution that is designed to be compatible with Red Hat Enterprise Linux (RHEL). It was created to provide a free and open source alternative to RHEL, which is a popular enterprise Linux distribution but is not available for free.	On the other hand, Debian is a well-established and widely-used Linux distribution that is known for its stability and versatility. It is a volunteer-driven project that is developed and maintained by a community of users and developers. The key difference between Rocky Linux and Debian is that Rocky Linux is focused on providing a stable and reliable platform for enterprise use, while Debian is more geared towards general use and is suitable for a wide range of applications. Rocky Linux is based on RHEL, while Debian is an independent distribution that is not based on any other distribution. This means that Rocky Linux shares many of the same features and characteristics as RHEL, while Debian has its own unique set of features and characteristics. In terms of support and maintenance, Rocky Linux is supported by a team of developers and users who are committed to maintaining the distribution and assisting the users, and Debian is maintained by a large and active community of volunteers who contribute their time and expertise.


### What is the purpose of virtual machines?

They allow you to run multiple operating systems on a single physical computer, and can be used for a variety of purposes, such as:

- Testing software: Virtual machines can be used to test software in a variety of different environments, without the need to have multiple physical computers.
- Isolation: Virtual machines can be used to isolate certain processes or applications from the rest of the system, which can be useful for security or stability reasons.
- Compatibility: Virtual machines can be used to run older software that may not be compatible with newer operating systems.
- Development environments: Virtual machines can be used to create development environments that mimic production environments, allowing developers to test their code in a more realistic setting.


### What are differences between `aptitude` and `apt`?

Aptitude and apt (Advanced Package Tool) are both package management tools for Debian-based Linux distributions like Ubuntu. Package management tools are software programs that manage the installation, updating, and removal of software packages on a computer. They are designed to make it easy to install, update, and remove software packages, as well as to manage dependencies between packages. Aptitude is a terminal-based frontend for the apt package management system. It offers a number of features that are not available in apt, such as the ability to roll back changes, the ability to view a summary of available package updates, and more advanced dependency resolution. Apt is a more lightweight tool that is focused on simple package management tasks. It does not have as many features as aptitude, but it is generally faster and easier to use.


### What is APPArmor?

AppArmor is a security feature for Linux that allows administrators to define rules that control what resources applications and processes can access on the system. These rules can be used to limit the capabilities of potentially harmful or poorly-written software, helping to protect the system from security vulnerabilities and other types of attacks.

To check the APPArmor status:

``` bash
sudo aa-status
```

### Check that UFW is started!

``` bash
sudo ufw status
```

### Check that SSH is started!

``` bash
sudo service ssh
```

### Check that the operating system is Debian!

``` bash
sudo cat /etc/os-release
```


## USER

### Check if 'user(login)' exists!

``` bash
sudo cat /etc/passwd
```
or

``` bash
sudo getent passwd 'user(login)'
```

### Check if it is part of the groups 'sudo' and 'user42'!

```bash
groups 'user(login)'
```

### Check the password policies!

``` bash
sudo vim /etc/pam.d/common-password
```

### Create a new user, and test the password policies!

``` bash
sudo adduser 'username'
```

#### Assign the password!

Test if it follows the password policy!


### Create 'evaluating' group and add the created user to the group!

``` bash
sudo addgroup evaluating
sudo adduser 'username' evaluating
```

#### Check if the user has been added to the 'evaluating' group!

``` bash
sudo getent group evaluating
```
or

``` bash
sudo groups 'username'
```

### Explain advantages and disadvantages of a strong policy implementation!

The main benefit of strong password policy implementation is that they can help create unique and hard-to-crack passwords by requiring the use of a combination of letters, numbers, and characters. However, these policies are not always effective as there can be diminishing returns in terms of increasing password complexity. While a longer password with more characters may be more difficult to crack, it may also be harder for the user to remember and may not provide much additional security if hackers are aware that longer passwords are frequently used. It is important to find a balance between password complexity and usability to ensure that passwords are both secure and easy for users to remember.


## HOSTNAME AND PARTITIONS

### Check that the hostname is 'login42'!

``` bash
hostname
```
or

``` bash
uname -n
```

### Modify the hostname and reboot the machine to confirm the hostname has changed!

``` bash
su -
vim /etc/hostname #change it!
reboot
```

### Restore

``` bash
su -
vim /etc/hostname #change it back to login42!
reboot
```

### Check the partitions of the machine!

``` bash
lsblk
```

#### Comapre the output with the subject's example!

```bash
NAME                        MAJ:MIN RM  SIZE RO TYPE  MOUNTPOINT
sda                           8:0    0    8G  0 disk
|-sda1                        8:1    0  487M  0 part  /boot
|-sda2                        8:2    0    1K  0 part
`-sda5                        8:5    0  7.5G  0 part
  `-sda5_crypt              254:0    0  7.5G  0 crypt
    |-dgerguri42--vg-root   254:1    0  2.8G  0 lvm   /
    |-dgerguri42--vg-swap_1 254:2    0  976M  0 lvm   [SWAP]
    `-dgerguri42--vg-home   254:3    0  3.8G  0 lvm   /home
sr0                    11:0    1 1024M  0 rom
```

### What is LVM and how does it work?

Logical Volume Manager (LVM) is a system for managing disk storage on Linux systems. It allows users to create logical volumes, which are abstractions of physical storage devices, and to manage them as a single entity. With LVM, users can create and resize logical volumes, as well as move and copy data between them, without having to worry about the underlying physical storage devices. This makes it easier to manage disk storage and to expand or reduce the size of logical volumes as needed. LVM also allows users to create volume groups, which are collections of physical storage devices that can be treated as a single logical volume. This can be useful for creating large logical volumes or for creating storage pools that can be used by multiple systems. Overall, LVM is a useful tool for managing disk storage on Linux systems, as it provides a high degree of flexibility and makes it easier to manage and expand storage.

Logical Volume Manager (LVM) works by abstracting physical storage devices and creating logical volumes that can be managed as a single entity. It does this by creating a logical volume layer between the physical devices and the filesystems that use them. When LVM is used, physical storage devices are grouped into volume groups, which are treated as a single logical volume. Within a volume group, users can create logical volumes, which are essentially virtual disks that can be formatted with a filesystem and used to store data. Logical volumes are created by allocating extents, which are blocks of physical storage, from the volume group. These extents can be dynamically added or removed from a logical volume as needed, allowing users to resize logical volumes without having to worry about the underlying physical storage devices.

## SUDO

### Check if 'sudo' program is installed!

``` bash
sudo apt list --installed | grep "sudo"
```
### Assign the new user to the sudo group!

``` bash
sudo adduser 'username' sudo
```

### What is the value and importance of sudo?

Sudo (short for "superuser do") is a command used to allow users with proper permissions to execute commands as the superuser (root) or another user. It provides access to administrative tasks that are normally only available to the root user.

There are several reasons why sudo is important:

- Security: By requiring users to enter their own password before executing commands with sudo, the system can ensure that only authorized users are able to perform administrative tasks. This can help prevent accidental or malicious damage to the system.
- Separation of duties: sudo allows multiple users to share a single system without giving them all access to the root account. This can be useful in environments where different users are responsible for different tasks, as it allows them to perform their tasks without granting unnecessary privileges.
- Auditing: sudo logs all commands executed with it, which can be useful for tracking changes to the system and identifying problems.
- Convenience: sudo allows users to perform administrative tasks without logging in as the root user. This can be more convenient for users who don't need to perform administrative tasks regularly, as they don't have to remember the root password.

Overall, sudo is an important tool for managing access to administrative tasks and is essential for maintaining security, separation of duties, and auditability on these systems.

### Verify that the '/var/log/sudo/' folder has one file!

``` bash
sudo ls /var/log/sudo
sudo cat sudo.log # might be a different name
```

### Test if that takes the sudo command!

``` bash
sudo cd /var/log/sudo
sudo cat sudo.log # check the time of the last sudo and compare it!
```

## UFW

### Check if 'UFW' program is installed!

``` bash
sudo apt list --installed | grep "ufw"
```

### Check if UFW is working properly!

``` bash
sudo ufw status
```
and open iTerm and try to connect!
iTerm:

``` bash
ssh 'username'@localhost -p 4242
```
### What is UFW and what is the value of using it?

Uncomplicated Firewall (UFW) is a frontend for the iptables firewall. It is designed to be easy to use and configure, making it a popular choice for managing firewall rules on Linux systems.

UFW allows users to create rules that control incoming and outgoing network traffic based on various criteria, such as source and destination IP addresses, protocols, and port numbers. It also includes a set of predefined rules that allow common services, such as SSH and HTTP, to pass through the firewall. UFW can be used to secure a system by blocking unwanted traffic and allowing only authorized traffic to pass through the firewall. It is often used in conjunction with other security measures, such as SSH key authentication and fail2ban, to provide an additional layer of security to a system. Overall, UFW is a useful tool for managing firewall rules on Linux systems and can be an important part of a system's security strategy.

### Check if port 4242 is included in the list of active rules!

``` bash
sudo ufw status
```

### Add a new rule to open port 8080!

``` bash
sudo ufw allow 8080
sudo ufw status
```

### Delete the new rule!

``` bash
sudo ufw delete allow 8080
```

## SSH

### Check if 'SSH' program is installed!

``` bash
sudo apt list --installed | grep "openssh-server"
```

### Check if SSH is working properly!

``` bash
sudo service ssh status
```
### What is SSH and what is the value of using it?

Secure Shell (SSH) is a network protocol used to securely connect to a remote computer. It is typically used to log into a remote machine and execute commands, but it can also be used to securely transfer files between computers. SSH uses encryption to secure the connection between the client and the server, protecting against attackers who might try to intercept the data being transmitted. It also provides authentication, allowing the server to verify the identity of the client before granting access. SSH is commonly used to remotely access and manage servers, as it allows users to execute commands and transfer files securely over a network. It is also used to tunnel other applications, such as web servers, through insecure networks. Overall, SSH is an important tool for securely accessing and managing remote systems, and is widely used in many different types of environments.

### Test if SSH works!

open iTerm:

``` bash
ssh 'username'@localhost -p 4242 # it will only work with port 4242, since it is the only active rule!
```

### Test if SSH works with root! # It should not work!

open iTerm:
``` bash
ssh root@localhost -p 4242 # it asks for password, in the end it doesn't connect!
```

## SCRIPT MONITORING

### Explain the monitoring script by showing the code!

#### Architecture

``` bash
uname -a
```
The 'uname' command provides information about the current system. When run with the '-a' flag, it displays a more detailed version of this information, including the kernel version, the machine name, and the operating system name.

#### Physical Processor

``` bash
cat /proc/cpuinfo | grep "physical id" | sort | uniq | wc -l
```
This command is used to count the number of physical processors (CPUs or cores). Here is what each command does:
1. cat /proc/cpuinfo: This command displays the contents of the /proc/cpuinfo file, which contains information about the system's CPUs.
2. grep "physical id": This command filters the output of the cat command to only include lines containing the string "physical id". The "physical id" field in the output indicates the physical processor that each logical processor (or "thread") is associated with.
3. sort: This command sorts the output of the grep command alphabetically, so that all the lines with the same "physical id" value are grouped together.
4. uniq: This command removes duplicates from the sorted output. When used with the -c flag, it also displays a count of the number of occurrences of each unique line.
wc -l: This command counts the number of lines in the output.

#### Virtual Processor

``` bash
cat /proc/cpuinfo | grep "processor" | wc -l
```
This command is used to count the number of virtual processors (CPUs or cores). Here is what each command does:
1. cat /proc/cpuinfo: This command displays the contents of the /proc/cpuinfo file, which contains information about the system's CPUs.
2. grep "processor": This command filters the output of the cat command to only include lines containing the string "processor". The "processor" field in the output indicates the logical processor number.
3. wc -l: This command counts the number of lines in the output.



#### Memory Usage

``` bash
mem_used=$(free --mega | grep "Mem:" | awk '{print $3}')
total_mem=$(free --mega | grep "Mem:" | awk '{print $2}')
mem_utilization=$(free --mega | grep "Mem:" | awk '{printf "%.2f%%", $3/$2*100}')
```
These commands are used to find information about the memory usage and utilization. Here is what each command does:

1. The mem_used command is used to display the total amount of used memory.
	1.1 free --mega: This command displays information about the system's memory usage. The "--mega" flag tells free to display the sizes in megabytes.
	1.2 grep "Mem:": This command filters the output of the "free" command to include only the line that begins with "Mem:", which contains information about the system's memory usage.
	1.3 awk '{print $3}': This command uses the "awk" utility to print the third field ($3) of the "Mem:" line, which represents the amount of used memory.

2. The total_mem command is used to display the total amount of memory. It is similar to the mem_used command, but the awk takes the second column.

3. The mem_utilization command is used to display the percentage of memory utilization. The information for the used memory and total amount memory is taken as above in megabytes. Then with 'awk' command is used to calculate the percentage of used memory.


#### Disk Usage

``` bash
disk_used=$(df -Bm | grep "^/dev/" | grep -v "boot" | awk '{used_total += $3}END{printf("%d", used_total)}')
total_disk=$(df -BG | grep '^/dev/' | grep -v '/boot' | awk '{total += $2} END {printf("%d", total)}')
disk_utilization=$(df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{used_total += $3} {total+= $2} END {printf("%.0f%%"), used_total/total*100}')
```
These commands are used to find information about the disk usage and utilization. Here is what each command does:

1. The disk_used command is used to display the total amount of used disk space.
	1.1 df -Bm: This command displays information about the disk space usage on the system. The -Bm flag tells df to display the sizes of files and directories in megabytes.
	1.2 grep "^/dev/": This command filters the output of the df command to include only lines that begin with the string "/dev/".
	1.3 grep -v "boot": This command filters the output of the previous grep command to exclude lines containing the string "boot".
	1.4 awk '{used_total += $3}END{printf("%d", used_total)}': This command uses the awk utility to calculate the total amount of used disk space. The $3 field refers to the third column in the df output, which contains the used space. The used_total += $3 command adds the used space for each device to a running total. The END keyword tells awk to execute the code after all lines have been processed. The printf("%d", used_total) command prints the total used space to the terminal.

2. The total_disk command is used to display the total size of all block devices. It is similar to the disk_used command, but it displays the sizes of files in gigabytes and the awk takes the second column.

3. The disk_utilization command is used to display the percentage of used disk space. The information for the used disk and total disk size is taken as above in megabytes. Then with 'awk' command is used to calculate the percentage of used disk space.

#### CPU Load

``` bash
top -bn1 | grep "Cpu" | awk '{print $2}' | tr -d '%'
```
This command is used to display current utilization rate of the processors as a percentage. Here is what each command does:

1. top -bn1: This command displays information about the running processes on the system, including their CPU and memory usage. The -b flag tells top to run in batch mode, which allows the output to be processed by other commands. The -n1 flag tells top to display only one iteration of the output.
2. grep "Cpu": This command filters the output of the top command to include only lines containing the string "Cpu". This will include the line that displays the CPU usage statistics.
3. awk '{print $2}': This command uses the awk utility to print the second field in the top output, which contains the percentage of used CPU resources.
4. tr -d '%': This command uses the tr utility to delete the % sign from the output.

#### Last Reboot

``` bash
who -b | awk '{print $3" "$4}'
```
This command is used to display the system boot time. Here is what each command does:
1. who -b: This command displays the system boot time. The -b flag tells who to display the boot time only.
2. awk '{print $3" "$4}': This command selects the third and fourth fields (columns) in the output of the who -b command and prints them to the terminal, separated by a space.

#### LVM use

``` bash
if [$(lsblk | grep "lvm" | wc -l) = 0]; then echo no; else echo yes; fi
```
This command is a shell script that checks if Logical Volume Management (LVM) is active. Here is what each command does:
1. lsblk: This command lists the block devices on the system, including disks and partitions.
2. grep "lvm": This command filters the output of the lsblk command to only include lines containing the string "lvm". This will match any block devices that are managed by LVM.
3. wc -l: This command counts the number of lines in the output.
4. if [$(...) = 0]: This is an if statement that tests the exit status of the command inside the brackets. If the command returns a zero exit status (indicating success), the if statement will be true. If the command returns a non-zero exit status (indicating failure), the if statement will be false.
	4.1 then echo no: If the if statement is true, this command will be executed. It will print the string "no" to the terminal.
	4.2 else echo yes: If the if statement is false, this command will be executed. It will print the string "yes" to the terminal.
	4.3 fi: This ends the if statement.


#### Connections TCP

``` bash
ss -s | grep -v "TCP:" | grep TCP | awk '{print $3}'
```
This command is used to display the number of established TCP connections Here is what each command does:
1. ss -s: This command displays summary statistics for sockets on the system. The -s flag tells ss to display summary statistics only.
2. grep -v "TCP:": This command filters the output of the ss command to exclude lines containing the string "TCP:". The -v flag tells grep to invert the match, so that only lines that do not contain the string "TCP:" are included in the output.
3. grep TCP: This command filters the output of the previous grep command to include only lines containing the string "TCP".
4. awk '{print $3}': This command selects the third field (column) in the output of the previous grep command and prints it to the terminal.

#### User Log

``` bash
who | wc -l
```
This command is used to count the number of users currently logged in. Here is what each command does:
1. who: This command displays information about users who are currently logged in to the system.
2. wc -l: This command counts the number of lines in the output of the who command.

#### Network

``` bash
IP=$(hostname -I)
MAC=$(ip link | grep link/ether | awk '{print $2}')
```
The 'IP' command is used to display the IP address(es) of the system. The -I flag tells hostname to display the primary IP address of the system. And the 'MAC' command is used to display the MAC addresses of the network interfaces. Here is what each command does:
1. ip link: This command displays information about the network interfaces on the system.
2. grep link/ether: This command filters the output of the ip link command to include only lines containing the string "link/ether". This will match any lines that contain information about the MAC address of a network interface.
3. awk '{print $2}': This command selects the second field (column) in the output of the previous grep command and prints it to the terminal.

#### Sudo

``` bash
journalctl _COMM=sudo | grep COMMAND | wc -l
```

This command is used to count the number of times the sudo command has been executed on a system using the systemd journal. Here is what each command does:
1. journalctl _COMM=sudo: This command displays the journal entries for the sudo command. The _COMM field specifies the command name to filter the journal by.
2. grep COMMAND: This command filters the output of the journalctl command to include only lines containing the string "COMMAND". This will match any journal entries that contain information about a sudo command that was executed.
3. wc -l: This command counts the number of lines in the output.


### What is 'cron'?

Cron is a time-based job scheduling utility that allows users to schedule tasks to be executed automatically at a specified time or interval. It is often used to schedule system maintenance or administration tasks, such as scripts to back up data or update the system. Overall, Cron is a useful tool for automating tasks on Unix-like systems and can save time and effort by allowing users to schedule tasks to be executed automatically.

### How was the script set up to run every 10 min?

``` bash
sudo crontab -e
```
The following line is added:
```
*/10 * * * * sh /home/'username'/monitoring.sh
```

### Check if it is working!

The script should pop up every 10 min!

### Change the script to run every 1 min!

``` bash
sudo crontab -e
```
The following line is added:
```
*/1 * * * * sh /home/'username'/monitoring.sh
```

### Make the script stop running without modifying the script!
``` bash
sudo crontab -e
```
Remove the scheduling line!

### Reboot!

The script should be there, but not run again!

### Create the signature!

Create the signature.txt of the virtual disk image!

``` bash
shasum /path/where/you/have/*.vdi > /path/where/you/want/to/save/signature.txt //Name must be different if you want to save them in the same folder with the signature.txt from repository!
```

