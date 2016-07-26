#include <LiquidCrystal.h>
#include <Keypad.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8); 
const byte ROWS = 4; //4 filas
const byte COLS = 3; //3 columna
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}};

byte rowPins[ROWS] = {7, 6, 5, 4}; //conexion de los pines de las filas del keypad con arduino uno.
byte colPins[COLS] = {3, 2, A5}; //conexion de los pines de las columnas del keypad con arduino.

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

//char PIN[6]={'1','2','3','4','5','6'}; //  contraseña (!) 
char PIN[6]={0,0,0,0,0,0};//pin sin ingresar contraseña
char contra[6]={0,0,0,0,0,0}; // arreglo para comparar
int estadoPIN=0;
int z=0;
int z1=0;
int Buzzer=A3;//alarma contra robo
int sal1 = A0; // salida1, para led rojo,activado todo el tiempo indica que la alarma esta activa
int sal2 = A1; // salida2, para led verde para inicar que se da acceso al sistema
int sal3 = A2;//para mostrar que se inserto correctamente el password o PIN led amarillo
int intento=0;//el numero de veces que se va a ingresar la contraseña
void setup()

{
  lcd.begin(16,2);
  lcd.write("Seguridad");
  delay(500);
  lcd.clear();
  pinMode(sal1, OUTPUT);
  pinMode(sal2, OUTPUT);
  pinMode(sal3,OUTPUT);
  pinMode(Buzzer, OUTPUT);
  //digitalWrite(sal3,HIGH);
  Serial.begin(9600); //Configura la velocidad del puerto serie
  keypad.setHoldTime(500); // configura la validacion de pulsacion del keypad 1000mS 500
  keypad.setDebounceTime(50); // configura cuanto tiempo sera presionado 50mS 250
}

void loop()
{ 
  lcd.setCursor(0,0);
  lcd.write("Su contraseña");  
  readKeypad();
 }
void readKeypad() 
{
  char key = keypad.getKey(); 
  if (key != NO_KEY)
  {  Serial.print("su contraseña: ");
    lcd.setCursor(z,1);
    lcd.print(key);
    Serial.println(key);
    switch(key)
  { 
 case '*':
  z=0; lcd.setCursor(0,1);lcd.print("                ");intentos();
  break;
 case '#':
  delay(50); 
  lcd.print(" "); 
   comprobar();
  break;
 default:
  llenarContra(key);
  } 
 } 
}
void comprobar(){
if(estadoPIN==0){
 validar();
}else{
 checkPIN(); 
}
}
void llenarContra(char key){
if(estadoPIN==0){
PIN[z]=key;
z++;
}else{
  contra[z]=key;
  z++;
}
}
void checkPIN()
{ 
  int correct=0; 
  for (int q=0; q<=5; q++)
  { 
  if (contra[q]==PIN[q])
   {
    correct++;
   } 
  }
  if (correct==6)
  { 
  intento=0;
   analogWrite(Buzzer,LOW);
  lcd.setCursor(0,1);
  lcd.write("correcto");
  lcd.setCursor(9,1);
  lcd.write(contra);
  lcd.setCursor(0,1);
  delay(1000);
  lcd.write("               ");
   correctPIN();
  delay(5000); 
  incorrectPIN(); 
  } else
{
  intentos();
  lcd.setCursor(0,1);
  lcd.write("contraseña");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.write("         ");
  incorrectPIN();//mmm
 
}
for(int zz=0;zz<6;zz++)//borrar tentativa
{
  contra[zz]=0;
}
}



