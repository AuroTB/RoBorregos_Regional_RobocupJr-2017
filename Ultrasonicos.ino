void pared(){
  izquierda=getDistance(1);
  if(izquierda<22){
    movimientoAngular(8);
    delay(50);
  }
  derecha=getDistance(2);
  if(derecha<22){
    movimientoAngular(2);
    delay(50);
  }

//  izquierda=getDistance(1);
//  derecha=getDistance(2);
//  if(cerca==true&&tsopRead(red[0])!=0&&(izquierda+derecha)>150){
//    if(derecha>110){
//          movimientoAngular(8);
          //delay(50);
//    }else if(izquierda>110){
//          movimientoAngular(2);
          //delay(50);
//    }else{
        ////Codigo de arriba
//  }else{
//    //codigo de arriba no comentado
//  }
}

void centrar(){
  int suma;
    izquierda=getDistance(1);
    derecha=getDistance(2);
  suma=izquierda+derecha;
      if(suma>150){      //rango aceptable de cancha libre
        if(izquierda<61){
          movimientoAngular(8);
        }else if(derecha<61){
          movimientoAngular(2);
        }
      }else{                          //hay un robot a los lados
        suma=suma/2;
        if(izquierda>suma){
          movimientoAngular(2);
        }else if(suma>derecha){
          movimientoAngular(8);
        }
      }
}

int getDistance(int face){
  d=0.0;
  cm=0;
  switch(face){                        
    case 1:                            //Si recibe un 1: obtiene mediciones del ultrasónico de la frontal      
      digitalWrite(trig1, LOW); 
      delayMicroseconds(2);
      digitalWrite(trig1, HIGH); 
      delayMicroseconds(10); 
      digitalWrite(trig1, LOW);
      d = pulseIn(echo1, HIGH);
      cm = d/58;
      digitalWrite(trig1, LOW);
      break;
    
    case 2:                             //Si recibe un 2: obtiene mediciones del ultrasónico izquierda
      digitalWrite(trig2, LOW); 
      delayMicroseconds(2);
      digitalWrite(trig2, HIGH); 
      delayMicroseconds(10); 
      digitalWrite(trig2, LOW);
      d = pulseIn(echo2, HIGH); 
      cm = d/58;
      digitalWrite(trig2, LOW);
      break;
  }
  delay(50);
  if(cm>140||cm<0){
    return 0;
  }else{
  return cm;
  }
}
