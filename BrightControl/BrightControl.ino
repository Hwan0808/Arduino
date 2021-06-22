int ledPin = 6;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  establishConnection();               // handshaking 설정
}
void loop()
{
    if (Serial.available() > 0)
    {
       int brightness = Serial.parseInt();         // 첫 번째 유효 정수 값 읽기
       brightness = constrain(brightness, 0, 1000);  // 0~255로 제한
       analogWrite(ledPin, brightness);             // LED 밝기 조절
        // 현재 밝기 값을 컴퓨터로 전송
       Serial.println("Current brightness is " + String(brightness, DEC));
       delay(1000);
     }
}
void establishConnection()
{
   char buffer[100] = "";
   Serial.println("Send me Back  \'OK\'");   // OK 문자열을 보내도록 알림
   while(true)                        // Handshaking이 성립될 때까지
    {  
       if (Serial.available())        // 수신 문자열이 있는 경우
       {  
          int readCount = Serial.readBytes(buffer, 99);   // 문자열 읽기
          buffer[readCount] = '\0';                        // 종료문자 추가
           // 수신 문자열을 컴퓨터로 재전송
          Serial.println("Received message :" + String(buffer));
           // OK 문자열이 수신될 때까지 대기
          if ( String("OK").equals(buffer)) 
          Serial.println("test");
          break;
        }
     }
     Serial.println("Now send me a brightness value.");   // 밝기 값 입력 대기
}
