# BinLog4mbed
Sample code of the fast binary data logging for __mbed LPC1768__.

This code is for __gcc4mbed__ compiler: https://github.com/adamgreen/gcc4mbed

Binary file saved in mbed is read by MATLAB code in "./load binary/"


## Format

Data is written as short int (2 Bytes) in "DATA.LOG".

![image](https://user-images.githubusercontent.com/114337358/206899316-ff17f5a5-9f0d-494a-b434-a7b967445486.png)



## Usage

* __Compile mbed code__

Compile source code, and generated "fwrite_test.bin" move to the local storage of  mbed LPC1768.

"DATA.LOG" is generated in local storage in mbed.

* __Read binary file__

Read the generated file by "./load binary/plot_data.m"
