#include <Arduino.h>
#include <Servo.h>


Servo serv;
void setup(){
	
	Serial.begin(115200);	//Baud rate
	pinMode(13,OUTPUT);		//LED output
	serv.attach(10);		// servo attached to PIN 10
}

void loop(){
	
	const int NMAX = 64;
	char buffer_ar[NMAX];	// character buffer to recieve data from serial port
	static int i = 0;
	int	len,n;
	int position;

	//check if bytes are available at port
	while(Serial.available() == 0) {
		i++;
	}
	
	len = 4;		//recieve 4 bytes of data
	
	// readbytes reads the buffer till length specified and returns the number
	// of bytes read
	n = Serial.readBytes(buffer_ar,len);
	if(n < len){
		Serial.print("\nerror, not enough data read");
	}
	
	position = atoi(buffer_ar);	//converting to int
	Serial.print(position);			//printing to screen
	serv.writeMicroseconds(position); //writing the value servo
	delay(10);

}
