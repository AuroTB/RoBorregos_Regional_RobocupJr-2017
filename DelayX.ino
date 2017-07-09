//Crea un delay pero con instrucciones que se estan ejeutando
//(No lee de los tsops mientras hace esto para evtar ruidos)
void delayX(int t){
  unsigned long tx = millis();
  unsigned long ta = millis();
  while(tsopRead(red[0])==0 || ta-tx<t){
//    Serial.print(millis());Serial.print(" - ");Serial.print(tx);Serial.print(" = ");
//    Serial.println(millis()-tx);
    ta=millis();
    if(ta-tx>t)
    break;
        }
       // Serial.println("salio");
 if(millis()-tx>t){
    movimientoAngular(1);
 }
}

void delayY(int t){
  int tx = millis();
  while(tx-millis() < t){
  euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  ajusteAngular(euler.x());
  acomodoAngular(euler.x());
  anguloPasado = euler.x();
  if(tsopRead(red[0])>4){
    movimientoAngular(1);
  }
  }
}

