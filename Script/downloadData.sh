#! /bin/bash 

sudo mkdir -p /tmp/final_project

echo "starting to download"

sudo wget -O /tmp/final_project/report.gz.tar https://loh.istgahesalavati.ir/report.gz.tar

cd /tmp/final_project

sudo tar -xzf /tmp/final_project/report.gz.tar
#echo "doooooooooooooooooooooooooooone!"
sudo rm -rf /tmp/final_project/report.gz.tar




