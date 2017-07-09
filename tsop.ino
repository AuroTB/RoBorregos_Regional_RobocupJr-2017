int ih;

void obtainTsop(){
    tsop[0]=tsopReadFar(red[0]);
    tsop[1]=tsopReadFar(red[1]);
    tsop[2]=tsopReadFar(red[2]);
    tsop[3]=tsopReadFar(red[3]);
  }
}

void showTsopCerca(){
  for(i=0;i<8;i++){
    Serial.print(tsopRead(red[i]));Serial.print(" ");
  }
  Serial.println();
}

int getTsop(){
  if(cerca){
    mayor[0]=-1;
    for(i=0;i<8;i++){
      if(tsopRead(red[i])!=0){
        mayor[0]=i;
        i=8;
      }
    }
    return mayor[0];
      
  }else{
      for(x=0;x<3;x++){
      mayor[x]=0;
      }
  
    for(x=0;x<3;x++){
    obtainTsop();
        for(i=0;i<8;i++){
          if(tsop[i]>tsop[mayor[x]]){
            mayor[x]=i;  
          }
        }
    }
    //digitalWrite(2,LOW);
  
  //  Serial.print(tsop[0]);Serial.print(" ");
  //  Serial.print(tsop[1]);Serial.print(" ");
  //  Serial.print(tsop[2]);Serial.print(" ");
  //  Serial.print(tsop[3]);Serial.println(" ");
    
    if(tsop[mayor[0]]==0&&tsop[mayor[1]]==0&&tsop[mayor[2]]==0){
      return -1;
    }else if(mayor[0]==mayor[1]){
      return mayor[0];
    }else if(mayor[0]==mayor[2]){
      return mayor[0];
    }else if(mayor[1]==mayor[2]){
      return mayor[1];
    }
  
  }
}

int tsopRead(int t){
  duration = pulseIn(t,LOW,25000);
  return duration;
}

int tsopReadFar(int t){
  digitalWrite(2,HIGH);
  duration = pulseIn(t,LOW,25000);
  duration = pulseIn(t,LOW,25000);
  for(ih=0;ih<3;ih++){
    duration+=pulseIn(t,LOW,25000);
  }
  duration/=ih-1;

  return duration;
}

void findIt(){
  cerca=true;
  mayorx=getTsop();
  if(mayorx==-1){
    cerca=false;
    digitalWrite(2,LOW);
    mayorx=getTsop();
  }
  
  //Serial.println(mayorx);
  switch(mayorx){
    case 0:
      movimientoAngular(1);
      delay(50);
    break;
    case 1:
      if(cerca){
      movimientoAngular(5);
      delay(200);
      movimientoAngular(4);
      delay(50);
      }else{
        movimientoAngular(4);
        delay(50);
      }
    break;
    case 2:
      if(getDistance(1)>getDistance(2)){
      movimientoAngular(2);
      delay(150);
      }else{
      movimientoAngular(8);
      delay(150);
      }
      movimientoAngular(5);
      delay(50);
    break;
    case 3:
      if(cerca){
      movimientoAngular(5);
      delay(200);
      movimientoAngular(6);
       delay(50);
      }else{
        movimientoAngular(6);
       delay(50);
      }
    break;
//    default:
//      movimientoAngular(0);
//      delayX(100);
//      movimientoAngular(5);
//      delayX(200);
  }
  mp=mayorx;
}
