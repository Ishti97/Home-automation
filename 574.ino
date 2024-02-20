#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>

/*Modified by
 * Technical Team,REES52
 */



#include <ESP8266WiFi.h>
#define FIREBASE_HOST "https://project1-4d69e-default-rtdb.firebaseio.com/"
#define L1 5
#define L2 4
#define L3 14
#define L4 12// LED at GPIO4 D2
 
const char* ssid = "JSRN";   //enter your wi-fi name
const char* password = "@richkid";    //enter the wifi password
unsigned char status_led=0;

WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);   
  pinMode(L1, OUTPUT);
  digitalWrite(L1, HIGH);
  pinMode(L2, OUTPUT);
  digitalWrite(L2, HIGH);
  pinMode(L3, OUTPUT);
  digitalWrite(L3, HIGH);
  pinMode(L4, OUTPUT);
  digitalWrite(L4, HIGH);
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Firebase.begin(FIREBASE_HOST);
 
  // Start the server
  server.begin();
  Serial.println("Server started at...");
  Serial.println(WiFi.localIP());
 
}
 
void loop() {

  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while (! client.available())
  {
    delay (1);
  }
  
 
  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();
 
  // Match the request
  
  if (req.indexOf("/ledoff1") != -1)  {
    status_led=1;
    digitalWrite(L1, LOW);
    Serial.println("LED OFF");
  }
  else if(req.indexOf("/ledon1") != -1)
  {
    status_led=0;
    digitalWrite(L1,HIGH);
    Serial.println("LED ON");
  }
    else if (req.indexOf("/ledoff2") != -1)  {
    status_led=1;
    digitalWrite(L2, LOW);
    Serial.println("LED OFF");
  }
  else if(req.indexOf("/ledon2") != -1)
  {
    status_led=0;

    digitalWrite(L2,HIGH);

    Serial.println("LED ON");
  }
    else if (req.indexOf("/ledoff3") != -1)  {
    status_led=1;

    digitalWrite(L3, LOW);

    Serial.println("LED OFF");
  }
  else if(req.indexOf("/ledon3") != -1)
  {
    status_led=0;

    digitalWrite(L3,HIGH);

    Serial.println("LED ON");
  }
    else if (req.indexOf("/ledoff4") != -1)  {
    status_led=1;

    digitalWrite(L4, LOW);
    Serial.println("LED OFF");
  }
  else if(req.indexOf("/ledon4") != -1)
  {
    status_led=0;

    digitalWrite(L4,HIGH);
    Serial.println("LED ON");
  }
 
 
 
 
// Return the response
client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println("Connection: close");
client.println(""); 

client.println("<!DOCTYPE HTML>");
client.println("<HTML>");
client.println("<H1> LED CONTROL </H1>");
client.println("<br />");

    client.println("<a href=\"/ledoff1\"\"> <button style='FONT-SIZE: 50px; HEIGHT: 200px; WIDTH: 300px; 126px; Z-INDEX: 0; TOP: 200px;'> LED ON </button> </a>");
 client.println("<a href=\"/ledon1\"\"> <button style='FONT-SIZE: 50px; HEIGHT: 200px;WIDTH: 300px; 126px; Z-INDEX: 0; TOP: 200px;'> LED OFF </button> </a>");

client.println("<a href=\"/ledoff2\"\"> <button style='FONT-SIZE: 50px; HEIGHT: 200px; WIDTH: 300px; 126px; Z-INDEX: 0; TOP: 200px;'> LED ON </button> </a>");
  client.println("<a href=\"/ledon2\"\"> <button style='FONT-SIZE: 50px; HEIGHT: 200px;WIDTH: 300px; 126px; Z-INDEX: 0; TOP: 200px;'> LED OFF </button> </a>");


 client.println("<a href=\"/ledoff3\"\"> <button style='FONT-SIZE: 50px; HEIGHT: 200px; WIDTH: 300px; 126px; Z-INDEX: 0; TOP: 200px;'> LED ON </button> </a>");
  client.println("<a href=\"/ledon3\"\"> <button style='FONT-SIZE: 50px; HEIGHT: 200px;WIDTH: 300px; 126px; Z-INDEX: 0; TOP: 200px;'> LED OFF </button> </a>");

 client.println("<a href=\"/ledoff4\"\"> <button style='FONT-SIZE: 50px; HEIGHT: 200px; WIDTH: 300px; 126px; Z-INDEX: 0; TOP: 200px;'> LED ON </button> </a>");
  client.println("<a href=\"/ledon4\"\"> <button style='FONT-SIZE: 50px; HEIGHT: 200px;WIDTH: 300px; 126px; Z-INDEX: 0; TOP: 200px;'> LED OFF </button> </a>");
 
 client.println("</html>");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
 
