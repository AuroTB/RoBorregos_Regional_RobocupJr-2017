///Arduino Mega: Control del movimiento del robot (3 llantas)

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

#include <IRremote.h>

int pasada=-1, actual = 0;
IRrecv irrecv(11);
decode_results results;

Adafruit_BNO055 bno = Adafruit_BNO055();

//Son las velocidades que todos los motores ejerceran cuando vayan a moverse
int v1=190, v2=190, v3=190;

int xy;

//Los numeros de pines de los motores, la 'a' significa avanzar y la 'r' retroceder
int pm1_a=22, pm1_r=23, 
    pm2_a=26, pm2_r=27, 
    pm3_a=28, pm3_r=29;

//Los numeros de pines para ecribir las velocidades de los mototres.
int pm1v=8, pm2v=9, pm3v=10;

//Los pines para os tres bits de comunicacion al arduino nano
int b0 = 2, b1=3 , b2 = 4;

int variablePasada=0; //La lectura pasada de los tres bits para revisar si hubo un cambio de movimiento

imu::Vector<3> euler; //Declaracion del objeto para los angulos euler
int anguloPasado = 0, vc1=v1, vc2=v2, vc3=v3;
bool regresando = false;
int direccion = 0;

//Para el RGB
int pinR=2, pinG=4, pinB=3;

int i,x,y=0, mayor[3],mp,mayorx=-1;
int red[8];
int tsop[8];
int duration;

int echo1=3;   //izquierda
int echo2=4;   //derecha


int trig1=7;                   //supersónico izquierda
int trig2=6;                   //supersónico derecha
double d;
int cm;

//Distancias
int izquierda, derecha;
bool cerca=true;

void setup() {
  Serial.begin(9600);

  irrecv.enableIRIn();

   if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }

  pinMode(trig1,OUTPUT);                   //supersónico izquierda
  pinMode(trig2,OUTPUT);

  pinMode(pinR,OUTPUT);
  pinMode(pinG,OUTPUT);
  pinMode(pinB,OUTPUT);

  pinMode(b0, INPUT);
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  
  pinMode(pm1v, OUTPUT);
  pinMode(pm2v, OUTPUT);
  pinMode(pm3v, OUTPUT);

  pinMode(pm1_a, OUTPUT);
  pinMode(pm1_r, OUTPUT);
  pinMode(pm2_a, OUTPUT);
  pinMode(pm2_r, OUTPUT);
  pinMode(pm3_a, OUTPUT);
  pinMode(pm3_r, OUTPUT); 

  movimientoAngular(1);

  //Para recibir interrupciones
//  pinMode(18, INPUT_PULLUP); //El pin 18 es el pin de interrupcion para la linea
//  attachInterrupt(digitalPinToInterrupt(18), linea, RISING);
    
    analogWrite(pm1v, v1);
    analogWrite(pm2v, v2);
    analogWrite(pm3v, v3);
  movimientoAngular(0);//Para asegurarnos de que no se mueva

//  //Para utilizar la brujula
  bno.setExtCrystalUse(true);  

  red[0]=50;
  red[1]=51;
  red[2]=49;
  red[3]=48; 
  red[4]=11; 
  red[5]=12; 
  red[6]=46; 
  red[7]=47;  
  for(i=0;i<8;i++){
    pinMode(red[i],INPUT);
  }
  pinMode(2,OUTPUT);
  digitalWrite(2,HIGH);
}

void loop() {
//   if (irrecv.decode(&results)) {
//    botones();
//    Serial.println(results.value);
//    irrecv.resume(); // Receive the next value
//  }

//  euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
//  ajusteAngular(euler.x());
//  acomodoAngular(euler.x());
//  anguloPasado = euler.x();
//    findIt();
//    pared();
      showTsopCerca();
}
