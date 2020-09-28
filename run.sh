#! /bin/bash



echo "welcome to FinalProject\n"

chmod +x ./Script/downloadData.sh

echo "executing prerequired C file:"

cd ./Cprogram

gcc -Wall -Wextra -I "/usr/include/postgresql" -L "/usr/lib/postgresql" preExe.c -lpq -o ./pre.out

sudo ./pre.out


echo "Executing for the first time\n"

./Script/program.sh

OUTPUT=$(pwd)

echo "*/30 * * * * ${OUTPUT}/Script/program.sh" | crontab -

echo "next run would be 30 minutes later"




