#! /bin/bash
echo "first step:"
chmod +x ./Script/downloadData.sh

#./Script/downloadData.sh
echo "executing C file:"
cd ./Cprogram


gcc -Wall -Wextra -I "/usr/include/postgresql" -L "/usr/lib/postgresql" preExe.c -lpq -o ./pre.out
sudo ./pre.out

gcc -Wall -Wextra -I "/usr/include/postgresql" -L "/usr/lib/postgresql" workWithData.c -lpq -o ./work.out
sudo ./work.out


rm *.text



