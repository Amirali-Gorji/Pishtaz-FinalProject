#! /bin/bash



echo "welcome to FinalProject"
echo "Preparing Please wait..."
sudo pip3 install psycopg2
OUTPUT=$(pwd)
chmod +x ${OUTPUT}/Script/downloadData.sh
chmod +x ${OUTPUT}/Script/program.sh

sudo mkdir -p /tmp/final_project
echo "executing prerequired C file:"

gcc -Wall -Wextra -I "/usr/include/postgresql" -L "/usr/lib/postgresql" ${OUTPUT}/Cprogram/preExe.c -lpq -o ${OUTPUT}/Cprogram/pre.out
sudo ${OUTPUT}/Cprogram/pre.out



echo "Executing for the first time\n"

sudo ${OUTPUT}/Script/program.sh



echo "*/30 * * * * ${OUTPUT}/Script/program.sh" | crontab -

echo "next run would be 30 minutes later"




