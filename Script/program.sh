#! /bin/bash
echo "downloading DataFiles\n"
./Script/downloadData.sh

echo "Adding DataFiles to Database..."
#sleep to let user see something
sleep 2

cd ./Cprogram

gcc -Wall -Wextra -I "/usr/include/postgresql" -L "/usr/lib/postgresql" workWithData.c -lpq -o ./work.out

sudo ./work.out

python3 ../PythonProgram/GainData.py
 
sudo rm /tmp/final_project/*.text
