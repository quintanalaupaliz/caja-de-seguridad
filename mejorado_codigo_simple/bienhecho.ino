#include <SPI.h>
#include <Ethernet.h>
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED//direccion mac
};
IPAddress ip(192, 168, 1, 177);//la direccion ip sera dependiente

ubidots client(token);
int servo_uno = 2;//es el pin para el primer servo
int servo_dos = 3;//es el pin para el segundo servo
int led_estado = 4;
int led_abierto = 5;
int led_cerrado = 6;

void setup(){
  Serial.begin(9600);//iniciar la coneccion de Ethernt
  if(Ethernet.begin(mac)==0){
  Serial.print("failed to configure Ethernet using DHCP");
  //tratar de configurar utilizando la direccion IP en lugar de DHCP
  Ethernet.begin(mac, ip);
  }
  pinMode(servo_uno,OUTPUT);
  pinMode(servo_dos,OUTPUT);
  pinMode(led_estado,OUTPUT);
  pinMode(led_abierto,OUTPUT);
  pinMode(led_cerrado,OUTPUT);
}
void loop(){

  EthernetClient client =server.available();//termina con un espacio en blanco
  if(estado_puerta == 1){
   
         {

            digitalWrite(pin_estado,HIGH);
            digitalWrite(led_abier,HIGH);
            digitalWrite(led_cerrar,LOW);
            digitalWrite(led_error,LOW);
            estado="ON";
          }          
            
      digitalWrite(servo_uno,LOW);
      digitalWrite(servo_dos,HIGH);
      digitalWrite(led_abierto,LOW);
      digitalWrite(led_cerrado,HIGH); 
          }
                    
           }

}
