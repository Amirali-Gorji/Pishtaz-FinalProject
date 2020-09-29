#! /bin/bash

OUTPUT=$(pwd)
echo "downloading DataFiles\n"
${OUTPUT}/Script/downloadData.sh

echo "Adding DataFiles to Database..."
#sleep to let user see something
#sleep 2


gcc -Wall -Wextra -I "/usr/include/postgresql" -L "/usr/lib/postgresql" ./Cprogram/workWithData.c -lpq -o ./Cprogram/work.out

sudo ./Cprogram/work.out

python3 ./PythonProgram/GainData.py > ./result.txt


sudo rm /tmp/final_project/*.text
