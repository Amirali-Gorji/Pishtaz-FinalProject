#! /bin/bash 

echo "starting to download"
wget -O ./report.gz.tar https://loh.istgahesalavati.ir/report.gz.tar

tar -xzf report.gz.tar

rm -rf report.gz.tar




