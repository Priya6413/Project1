#defineBLYNK_TEMPLATE_ID &quot;TMPL3h2VYoFnK&quot; #define BLYNK_TEMPLATE_NAME
&quot;food spoilage&quot; #define BLYNK_AUTH_TOKEN  
&quot;IuVXra-
y2IOq4ljDEULUD9YxYsl3VDka&quot;
#include &lt;WiFi.h&gt; 
#include &lt;WiFiClient.h&gt; 
#include &lt;BlynkSimpleEsp32.h&gt; 
#include &quot;DHT.h&quot; 
#define DHTPIN 4 
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE); 
int gas = 36; 
int motor1 = 22;  
int motor2 = 21; 
char auth[] = BLYNK_AUTH_TOKEN; 
char ssid[] = &quot;IOT123&quot;; 
char pass[] = &quot;22334455&quot;; 
void setup() 
{ 
Serial.begin(9600); 
Blynk.begin(auth, ssid, pass); 
dht.begin();  
 pinMode(gas, INPUT); 
 pinMode(motor1, OUTPUT); 
 pinMode(motor2, OUTPUT);  
} 
void loop() 
{ 
 Blynk.run(); 
 int G=analogRead(gas); 

 float h = dht.readHumidity(); 
 float t = dht.readTemperature(); 
 //G=G*0.025; 
 //Serial.print(&quot;GAS VALUE :&quot;); 
 Serial.print(G); 
 Serial.print(&quot;,&quot;); 
//Serial.print(F(&quot;Temperature: &quot;));  
Serial.print(t); // temperature 
Serial.print(&quot;,&quot;); 
//Serial.print(F(&quot;Humidity: &quot;));
//humidity Serial.println(h); 
Blynk.virtualWrite(V0,G); 
Blynk.virtualWrite(V1,t); 
Blynk.virtualWrite(V2,h); 
delay(500); 
if(h&gt;70) 
{ 
 Blynk.logEvent(&quot;alert&quot;, &quot;HIGH
HUMIDITY:&quot;);  //Serial.println(&quot;HIGH
HUMIDITY:&quot;); 
 digitalWrite(motor1,1); 
 digitalWrite(motor2,0); 
 delay(5000); 
 digitalWrite(motor1,0); 
 digitalWrite(motor2,0); 
 delay(100); 
 } 
 if(t&gt;40) 
 { 
 Blynk.logEvent(&quot;alert&quot;, &quot;TEMPERATURE is
High:&quot;);  //Serial.println(&quot;TEMPERATURE is
High:&quot;);  digitalWrite(motor1,1); 
 digitalWrite(motor2,0); 
 delay(5000); 

 digitalWrite(motor1,0); 
 digitalWrite(motor2,0); 
 delay(100);
 } 
 if((G&gt;10)&amp;&amp;(G&gt;90)) 
 { 
 //Serial.println(&quot;VERY BAD SMELL:&quot;); 
 Blynk.logEvent(&quot;alert&quot;, &quot;VERY BAD SMELL IS
DETECT  ON FOOD:&quot;); 
 digitalWrite(motor1,1); 
 digitalWrite(motor2,0); 
 delay(5000); 
 digitalWrite(motor1,0); 
 digitalWrite(motor2,0); 
 delay(100); 
 }