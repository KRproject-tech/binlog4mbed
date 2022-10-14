/* Copyright 2011 Arthur Wolf

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
#include <mbed.h>

#define INT_T 2000
#define PI 3.142
float global_time = 0;

Serial pc(USBTX, USBRX);
Ticker flipper;
DigitalOut led1(LED1);
DigitalOut led2(LED2);
LocalFileSystem local("local");  // マウントポイントを定義（ディレクトリパスになる）
FILE *fp0;


void flip() {

	float out[3] = { 0 };
	short data[5] = { 0 };
	int idx = 0;

	global_time += INT_T*1e-6;
	global_time = ( global_time > 1000 ) ? 0 : global_time;

    led2 = !led2;

	out[0] = 2*sin( 2*PI*global_time);
	out[1] = cos( 2*PI*global_time);
	out[2] = 0.5*sin( 2*PI*2.0*global_time);

	pc.printf( "AA,%f[s],%f[-],%f[-],%f[-]\r\n", global_time, out[0], out[1], out[2]);

	data[0] = 0xAAAA;
	data[1] = (short)( 1000*global_time );
	for(idx=0;idx<3;idx++) 
		data[2+idx] = (short)( 100*out[idx] );

	if(global_time <= 20 )
		fwrite( data, sizeof( short), 5, fp0);	
	else{
		if( fp0 )
			fclose( fp0);
	}
		
}

int main() 
{
    // PC-mbed baud rate[bps]
	pc.baud( 921600);

	if( (fp0 = fopen( "/local/data.log", "wb")) == NULL ){
		pc.printf( "error\r\n");
	}
	
	led2 = 1;
    flipper.attach_us(&flip, INT_T); // the address of the function to be attached (flip) and the interval (us)

    // spin in a main loop. flipper will interrupt it to call flip
    while(1) {
        led1 = !led1;
        wait(0.1);
    }
}


