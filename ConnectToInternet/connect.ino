// AT                             Command to display the OK message
// AT+GMR                         Command to display esp8266 version info
// AT+UART_CUR=9600,8,1,0,0       Command to change the ESP8266 serial baud rate  to 9600   
// AT Command to change the ESP8266 serial baud rate  to 115200   AT+UART_CUR=115200,8,1,0,0

String ssid = "TIM";
String pwd = "12345679";


// Hardware serial test - Arduino MEGA
void setup() {
 Serial.begin(9600);
 Serial1.begin(115200);    // or 115200

 GetConnection(ssid,pwd);
 SetIP("192.168.1.140");
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

void GetConnection(String ssid, String pwd){
  Serial1.println("AT+GMR");
  delay(1000);

  Serial1.println("AT+CWMODE=1");
  delay(1000);

  Serial1.print("AT+CWJAP=\"");
  Serial1.print(ssid);
  Serial1.print("\",\"");
  Serial1.print(pwd);
  Serial1.println("\"");
  delay(10000);

  Serial1.println("AT+CIFSR");
  delay(1000);

  Serial1.println("AT+CIPMUX=1");
  delay(1000);

  Serial1.print("AT+CIPSERVER=1,");
  delay(1000);
}

void SetIP(String ip){
  Serial1.println("AT+CIPSTA=\""+ip+"\"");
  delay(3000);
}
