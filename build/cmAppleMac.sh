#!/bin/bash

rm -dr Mac
mkdir Mac
cd Mac
cmake ../ -DCMAKE_CXX_STANDARD_LIBRARIES="-lwx_osx_cocoau_aui-3.2"
cd ..
