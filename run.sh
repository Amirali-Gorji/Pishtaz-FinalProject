#! /bin/bash
echo "first step:"
chmod +x ./Script/downloadData.sh
./Script/downloadData.sh
echo "executing C file:"
gcc -Wall -Wextra -I "/usr/include/postgresql" -L "/usr/lib/postgresql" ./Cprogram/workWithData.c -lpq -o ./Cprogram/work
sudo ./Cprogram/work

rm *.text
