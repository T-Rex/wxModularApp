#!/bin/bash

rm -dr Mac
mkdir Mac
cd Mac
cmake ../ -G "Xcode"
cd ..
