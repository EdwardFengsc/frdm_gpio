#include "mbed.h"
#include "Joystick.h"
#include "RGBmatrixPanel.h" 
#include "pwm_tone.h"
#include<stdlib.h>
//               Xaxis,Yaxis,Button 
Joystick joystick(A4, A5, D3);

DigitalOut r_led(LED_RED);
Serial pc(USBTX, USBRX);
PinName ub1=D13;
PinName ug1=D14;
PinName ur1=D15;
PinName lb2=D10;
PinName lg2=D11;
PinName lr2=D12;
PwmOut Buzzer(D5);


RGBmatrixPanel matrix(ur1,ug1,ub1,lr2,lg2,lb2,A0,A1,A2,D9,A3,D8,false);
                          //r1, g1,b1,r2,g2,b2,a, b, c, sclk, latch,  oe, dbuf
void delay(int x){
 
     for(int i=0;i<x;i++){
 
          wait_us(10);
 
          matrix.updateDisplay();
 
     }
 
}
float C_3 = 1000000/Do3,
       Cs_3 = 1000000/Do3s,
       D_3 = 1000000/Re3,
       Ds_3 = 1000000/Re3s,
       E_3 = 1000000/Mi3,
       F_3 = 1000000/Fa3,
       Fs_3 = 1000000/Fa3s,
       G_3 = 1000000/So3,
       Gs_3 = 1000000/So3s,
       A_3 = 1000000/La3,
       As_3 = 1000000/La3s,
       B_3 = 1000000/Ti3,
       C_4 = 1000000/Do4,
       Cs_4 = 1000000/Do4s,
       D_4 = 1000000/Re4,
       Ds_4 = 1000000/Re4s,
       E_4 = 1000000/Mi4,
       F_4 = 1000000/Fa4,
       Fs_4 = 1000000/Fa4s,
       G_4 = 1000000/So4,
       Gs_4 = 1000000/So4s,
       A_4 = 1000000/La4,
       As_4 = 1000000/La4s,
       B_4 = 1000000/Ti4,
       C_5 = 1000000/Do5,
       Cs_5 = 1000000/Do5s,
       D_5 = 1000000/Re5,
       Ds_5 = 1000000/Re5s,
       E_5 = 1000000/Mi5,
       F_5 = 1000000/Fa5,
       Fs_5 = 1000000/Fa5s,
       G_5 = 1000000/So5,
       Gs_5 = 1000000/So5s,
       A_5 = 1000000/La5,
       As_5 = 1000000/La5s,
       B_5 = 1000000/Ti5;
int tones[] = {E_4, D_4, C_4, D_4, E_4, E_4, E_4, 0, D_4, D_4, D_4, 0, E_4, G_4, G_4, 0, 
                             E_4, D_4, C_4, D_4, E_4, E_4, E_4, 0, D_4, D_4, E_4, D_4, C_4, 0, 0, 0};
/* void demo_joystick()
{
    //First initalise joystick
    joystick.init();
 
    while (true) {
        //Stores x and y output values
        float x, y;
 
        //Calls the "GetXValue" and "GetYValue" and stores it in x and y
        x = joystick.GetXValue();
        y = joystick.GetYValue();
 
        //Prints the values to the terminal
        pc.printf("X: %f, Y: %f\r\n", x, y);
        wait(5.0f);
        //If the button flag is pressed switch the led
        if (joystick.get_button_flag()) {
            r_led = !r_led;
        }
    }
}
*/
/*void demo_LEDmatrix()
 
{
 
    matrix.begin();
		while(1){
			r_led = !r_led;
			matrix.fillScreen(matrix.Color333(0, 0, 0));
			delay(100000);
		}
    while(1) {
			  r_led = !r_led;
 
        // fill the screen with 'black'
 
        matrix.fillScreen(matrix.Color333(0, 0, 0));
 
        // draw a pixel in solid white
 
        matrix.drawPixel(0, 0, matrix.Color333(7, 7, 7));
 
        delay(100);
        r_led = !r_led;
 
 
        // fix the screen with green
 
        matrix.fillRect(0, 0, 32, 16, matrix.Color333(0, 7, 0));
 
        wait_ms(500);
				r_led = !r_led;
 
 
        // draw a box in yellow
 
        matrix.drawRect(0, 0, 32, 16, matrix.Color333(7, 7, 0));
 
        wait_ms(500);
 
				r_led = !r_led;
 
        // draw an 'X' in red
 
        matrix.drawLine(0, 0, 31, 15, matrix.Color333(7, 0, 0));
 
        matrix.drawLine(31, 0, 0, 15, matrix.Color333(7, 0, 0));
 
        wait_ms(500);
				r_led = !r_led;
 
 
        // draw a blue circle
 
        matrix.drawCircle(7, 7, 7, matrix.Color333(0, 0, 7));
 
        wait_ms(500);
				r_led = !r_led;
 
 
 
        // fill a violet circle
 
        matrix.fillCircle(23, 7, 7, matrix.Color333(7, 0, 7));
 
        wait_ms(500);
				r_led = !r_led;
 
 
 
        // fill the screen with 'black'
 
        matrix.fillScreen(matrix.Color333(0, 0, 0));
 
 
 
        // draw some text!
 
        matrix.setCursor(1, 0);   // start at top left, with one pixel of spacing
 
        matrix.setTextSize(1);    // size 1 == 8 pixels high
 
 
 
        // printff each letter with a rainbow color
 
        matrix.setTextColor(matrix.Color333(7,0,0));
 
        matrix.putc('1');
 
        matrix.setTextColor(matrix.Color333(7,4,0));
 
        matrix.putc('6');
 
        matrix.setTextColor(matrix.Color333(7,7,0));
 
        matrix.putc('x');
 
        matrix.setTextColor(matrix.Color333(4,7,0));
 
        matrix.putc('3');
 
        matrix.setTextColor(matrix.Color333(0,7,0));
 
        matrix.putc('2');
 
 
 
        matrix.setCursor(1, 9);   // next line
 
        matrix.setTextColor(matrix.Color333(0,7,7));
 
        matrix.putc('*');
 
        matrix.setTextColor(matrix.Color333(0,4,7));
 
        matrix.putc('R');
 
        matrix.setTextColor(matrix.Color333(0,0,7));
 
        matrix.putc('G');
 
        matrix.setTextColor(matrix.Color333(4,0,7));
 
        matrix.putc('B');
 
        matrix.setTextColor(matrix.Color333(7,0,4));
 
        matrix.putc('*');
 
        wait_ms(500);
				r_led = !r_led;
 
    }
 
}*/
/*void demo_buzzer()
{
    Tune(Buzzer, C_4, 4);  //4 Octave C beat 4/16
    wait_ms(250);
    Tune(Buzzer, D_4, 4);  //4 Octave D beat 4/16
    wait_ms(250);
    Tune(Buzzer, E_4, 4);  //4 Octave E beat 4/16
    wait_ms(250);
    
    int i;
    
    for(i=0; i<tones_num; i++)
    {
        Auto_tunes(Buzzer, tones[i], 4); // Auto performance
        Stop_tunes(Buzzer);
    }
}*/
int main(){
	 joystick.init();
   float x, y;//joystick read in data
	 int gx,gy,px,py;//location of RGB LED matrix
	 gx = 0;
	 gy = 0;
	 px = 0;
	 py = 0;
	 matrix.drawPixel(gx, gy, matrix.Color333(7, 7, 7));//draw start point
	 delay(100);
    while (true) {
        //Stores x and y output values
			
				px = gx;
			  py = gy;
 
 
        //Calls the "GetXValue" and "GetYValue" and stores it in x and y
        x = joystick.GetXValue();
        y = joystick.GetYValue();
			//using x,y to judge the draw location of LED mtrix
				if (x < 0.2){
					if (gx == 0){
						gx = 31;
						// alarm that pixel is move out the LED mtrix
						Auto_tunes(Buzzer, tones[0], 4); // Auto performance
						Stop_tunes(Buzzer);
						
					}
					else{
						gx -= 1;
					}	
				}
				else if(x >0.7){
					if (gx == 31){
						gx = 0;
						// alarm that pixel is move out the LED mtrix
						Auto_tunes(Buzzer, tones[0], 4); // Auto performance
						Stop_tunes(Buzzer);
					}
					else{
						gx += 1;
					}
				}
				else{
					gx = gx;
				}
				if (y < 0.2){
					if (gy == 0){
						gy = 15;
						// alarm that pixel is move out the LED mtrix
						Auto_tunes(Buzzer, tones[0], 4); // Auto performance
						Stop_tunes(Buzzer);
					}
					else{
						gy -= 1;
					}
				}
				else if(y > 0.7){
					if (gy == 15){
						gy = 0;
						// alarm that pixel is move out the LED mtrix
						Auto_tunes(Buzzer, tones[0], 4); // Auto performance
						Stop_tunes(Buzzer);
					}
					else{
						gy += 1;
					}
				}
				if (px!=gx || py != gy){
				matrix.fillRect(0,0,32,16, matrix.Color333(0, 0, 0)); 
				matrix.drawPixel(gx, gy, matrix.Color333(1+(int)(7.0*rand()/(RAND_MAX+1.0)), 1+(int)(7.0*rand()/(RAND_MAX+1.0)), 1+(int)(7.0*rand()/(RAND_MAX+1.0))));
			  delay(5000);
				}
				else{
					delay(5000);
				}
				
				
        //Prints the values to the terminal
        pc.printf("GX: %d, GY: %d\r\n", gx, gy);
				pc.printf("X: %f, Y: %f\r\n", x, y);
				
        //If the button flag is pressed switch the led
        if (joystick.get_button_flag()) {
            r_led = !r_led;
        }
    }
}
