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
  pinMode(pin_estado,OUTPUT);
  pinMode(led_abier,OUTPUT);
  pinMode(led_cerrar,OUTPUT);
  pinMode(led_error,OUTPUT);
}
void loop(){
  // escuchar a los clientes entrantes
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // una petición http termina con una línea en blanco
    boolean currentLineIsBlank = true;
    String cadena="";
     while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        header += c;
        Serial.write(c);//Visualizamos la petición HTTP por el Monitor Serial
        cadena.concat(c);//Unimos el String 'cadena' con la petición HTTP (c). De esta manera convertimos la petición HTTP a un String
          
        int posicion=cadena.indexOf("LED="); //Guardamos la posición de la instancia "LED=" a la variable 'posicion'
 
          if(cadena.substring(posicion)=="LED=ON")//Si a la posición 'posicion' hay "LED=ON"
          {
            digitalWrite(pin_estado,HIGH);
            digitalWrite(led_abier,HIGH);
            digitalWrite(led_cerrar,LOW);
            digitalWrite(led_error,LOW);
            estado="ON";
          }
          if(cadena.substring(posicion)=="LED=OFF")//Si a la posición 'posicion' hay "LED=OFF"
          {
            digitalWrite(pin_estado,LOW);
            digitalWrite(led_abier,LOW);
            digitalWrite(led_cerrar,HIGH);
            digitalWrite(led_error,LOW);
            estado="OFF";
            client.println("HTTP/1.1 200 OK");
            client.println("WWW-Authenticate: Basic realm=\"Secure\"");
            client.println("Content-Type: text/html");
            client.println("<html><meta http-equiv='refresh' content='2; url=javascript:window.close();'</html>");
          }
}
