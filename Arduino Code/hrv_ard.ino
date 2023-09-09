
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
int sensorValue = 0;
unsigned long prv=0;
unsigned long previousMillis = 0;
int count=0,n,sum=0;
int hb=0;
void setup() {
  Serial.begin(9600);
  
}


void loop() {


unsigned long prvMillis = millis();
int cnt=0;
unsigned int rr[100];
while((millis()-prvMillis)<5000)
{
  //Serial.println((millis()-prvMillis));
    sensorValue = 1023-analogRead(analogInPin);
   // Serial.println(sensorValue);
    if(sensorValue>600)
    {
      cnt=cnt+1;
      
      if(cnt==1)
      {
        prv=millis();
      }
      else
      {
        rr[cnt-2]=millis()-prv;
        
        prv=millis();
      }
      delay(200);
    }
    
}
//Serial.println(cnt);
//if(cnt>14)
//{
//  Serial.print("0\n");
//}
if(cnt<2)
{
  Serial.print("200\n");
}
else
{
//Serial.println(cnt);
for(int ii=0;ii<cnt-1;ii++)
//Serial.println(rr[ii]);   

n=cnt-1;
sum=0;
for(int j=1;j<=n-1;j++)
{
  sum=sum + ((rr[j]-rr[j+1]) * (rr[j]-rr[j+1]));
}
int hrv=sqrt((sum/(n-1)));
Serial.print(String(hrv)+"\n");
}



}
