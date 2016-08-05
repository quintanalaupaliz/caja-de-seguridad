#include <SPI.h>
#include <Ethernet.h>
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED//direccion mac
};
IPAddress ip(192, 168, 1, 177);//la direccion ip sera dependiente
EthernetServer server(80);//el puerto 80 es automatico
String header;
int pin_estado=6;//es el pin de led
int led_abier=2;//pin de led puerta abierta
int led_cerrar=3;//pin de led que esta la puerta cerrada
int led_error=4;// pin de error
String estado="OFF"; // estado de led inicialmente Off

void setup(){
  Serial.begin(9600);
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at");
  Serial.println(Ethernet.localIP());
}
void loop(){
}
