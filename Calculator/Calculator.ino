byte  inputByte;
long  calSum;       
int   tmpNum;
void setup()
{
   Serial.begin(9600);
}
void loop()
{
calSum = 0;
tmpNum = 0;
if (Serial.available() > 0) { 
    while (Serial.available() > 0) {
      inputByte = Serial.read(); 
      if  (inputByte  == 61)  {
         Serial.print('='); 
         delay(5);
         Serial.println(calSum);
         delay(5);
     };
    if  ((inputByte >= 48) && (inputByte <= 57)) 
    {    tmpNum  = inputByte - 48;
         calSum  = tmpNum;
         Serial.print(tmpNum);
         delay(5);
     };
    if  (inputByte == 45)  
    {    inputByte = Serial.read(); 
         tmpNum  = inputByte - 48; 
         Serial.print('-');  
         delay(5);
         Serial.print(tmpNum);
         delay(5);
         calSum = calSum - tmpNum; 
     }
    if  (inputByte == 43)  {
         inputByte = Serial.read(); 
         tmpNum  = inputByte - 48;
         Serial.print('+');  
         delay(5);
         Serial.print(tmpNum); 
         delay(5);
         calSum = calSum + tmpNum;
    }
  }  //  while 반목문의 끝
 }   //  if 조건문의 끝
}

