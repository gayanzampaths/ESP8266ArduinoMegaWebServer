// AT                             Command to display the OK message
// AT+GMR                         Command to display esp8266 version info
// AT+UART_CUR=9600,8,1,0,0       Command to change the ESP8266 serial baud rate  to 9600   
// AT Command to change the ESP8266 serial baud rate  to 115200   AT+UART_CUR=115200,8,1,0,0

// Hardware serial test - Arduino MEGA
void setup() {
 Serial.begin(9600);
 Serial1.begin(115200);    // or 115200
}

void loop() {
 
  while (Serial.available()) { 
      char ch = Serial.read();
      Serial1.print(ch);
    }
  
  while (Serial1.available()) { 
      char ch = Serial1.read();
      Serial.print(ch);
    }
    

}
