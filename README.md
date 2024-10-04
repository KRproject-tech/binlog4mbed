**Communication**

<a style="text-decoration: none" href="https://twitter.com/hogelungfish" target="_blank">
    <img src="https://img.shields.io/badge/twitter-%40hogelungfish-1da1f2.svg" alt="Twitter">
</a>
<p>

**Language**
<p>
<img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/cplusplus/cplusplus-original.svg" width="60"/>
<img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/matlab/matlab-original.svg" width="60"/>
<p>

# BinLog4mbed
Sample code of the __Fast__ binary data logging for __mbed LPC1768__.

This code is for __gcc4mbed__ compiler: https://github.com/adamgreen/gcc4mbed

Binary file saved on a micro SD card is read by MATLAB code in "./load binary/" or Python code in "./load binary_Py/".


## Format

Data is written as short int (2 Bytes) in "DATA.LOG".

![image](https://user-images.githubusercontent.com/114337358/206899316-ff17f5a5-9f0d-494a-b434-a7b967445486.png)



## Usage

* __Compile mbed code__

Compile source code, and generated "fwrite_test.bin" move to the local storage of  mbed LPC1768.

"DATA.LOG" is generated in local storage in mbed.

* __Read binary file__

Read the generated file by "./load binary/plot_data.m"
    
![図2](https://github.com/KRproject-tech/binlog4mbed/assets/114337358/6125f9b6-675b-451e-999a-dcf7fc5243d8)

