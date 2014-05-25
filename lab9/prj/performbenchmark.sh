#!/bin/bash

IMPLEMENTATIONS="astar dfs bfs"
PROBLEMSIZES="5 10 20 40 60 80"
REPETITIONSCOUNT=1000

OUTPUTDIR="data"
mkdir -p $OUTPUTDIR
for I in $IMPLEMENTATIONS 
do
  echo Processing $I:
  > $OUTPUTDIR/$I.csv
  for PS in $PROBLEMSIZES 
  do
    ./graph $I $PS $REPETITIONSCOUNT | tee -a $OUTPUTDIR/$I.csv
  done
done
