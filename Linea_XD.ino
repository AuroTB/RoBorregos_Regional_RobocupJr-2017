void linea(){
  //Mas uno porque manda valores del 0 al 7
  //Se mueve al lado contrario de donde detecto linea
  //La senal ya esta espejeada
  movimientoAngular(binario_decimal()+1);
  for(int i=0; i<100 ; i++)
    delayMicroseconds(10000);
}

int binario_decimal(){
  int valx=0;
  if(digitalRead(b0)==HIGH)
  valx+=1;
  if(digitalRead(b1)==HIGH)
  valx+=2;
  if(digitalRead(b2)==HIGH)
  valx+=4;
  return valx;
}

