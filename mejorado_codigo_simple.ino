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

byte rowPins[ROWS] = {7, 6, 5, 4}; //conexion de los pines de las filas del keypad con arduino.
byte colPins[COLS] = {3, 2, A5}; //conexion de los pines de las columnas del keypad con arduino.

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

//char PIN[6]={'1','2','3','4','5''6'}; //  contraseña (!) 
char PIN[6]={0,0,0,0,0,0};//pin sin ingresar contraseña
char contra[6]={0,0,0,0,0,0}; // arreglo para comparar
int estadoPIN=0;
int z=0;
int z1=0;

