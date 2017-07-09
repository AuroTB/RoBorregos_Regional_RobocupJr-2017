//Acomoda al robot si esta desalineado del angulo inicial

void acomodoAngular(int d){
  
  int h = d;
  //Si el robot no se encuentra dentro del rango designado se activa el algoritmo de acomodo
  while(h < 345 && h > 15){
//    h=euler.x();
    if(h<180){
      movimientoAngular(98);
      delay(20);
    }
    else{
      movimientoAngular(99);
      delay(20);
    }
    movimientoAngular(0);
  delay(30);
    euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
    h=euler.x();
  }
//
//    while(h<180){
//      h=euler.x();
//      movimientoAngular(98);
//      euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
//    }
//
//    while(h>180){
//      h=euler.x();
//      movimientoAngular(99);
//      euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
//    }
}

