#!/bin/bash

for dir in _mm*; do echo $dir; cd $dir; ../test.sh  ;cd ..; done
