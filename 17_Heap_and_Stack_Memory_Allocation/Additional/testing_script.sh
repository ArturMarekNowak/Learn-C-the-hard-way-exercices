#!/bin/bash
set -e
echo "Hello to testing script, make yourself a favourite beverage"
./ex17_2 db.dat c
echo 
./ex17_2 db.dat l
echo
./ex17_2 db.dat s 1 Artur Artur@Nowak.com
echo
./ex17_2 db.dat l
echo
./ex17_2 db.dat s 2 Marek Marek@Nowak.com
echo
./ex17_2 db.dat l
echo
./ex17_2 db.dat s 3 Andrzej Andrzej@Nowak.com
echo
./ex17_2 db.dat l
echo
./ex17_2 db.dat g 1 
echo
./ex17_2 db.dat l
echo
./ex17_2 db.dat d 2 
echo
./ex17_2 db.dat l
