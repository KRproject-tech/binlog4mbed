# binlog4mbed
Fast binary data logging code for __mbed LPC1768__.

This code is for __gcc4mbed__ compiler: https://github.com/adamgreen/gcc4mbed

Binary file saved in mbed is readed by MATLAB code in "./load binary/"

## Usage

* __Compile mbed code__

Compile source code and move to strage of  mbed LPC1768.

"DATA.LOG" is generated in local storage in mbed.

* __Read binary file__

Read the generated file by "./load binary/plot_data.m"
