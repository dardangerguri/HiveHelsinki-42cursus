ifconfig | grep "ether " | sed 's/ether*//g' | sed -E 's/[[:space:]]+/ /g' | tr -d ' '
