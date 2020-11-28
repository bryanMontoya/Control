
int Tip = 3;
int entradaAnaloga = A0;

double lecturaSensor = 0;
double ref = 300;
double error = 0;
double k = 50;
double senalControl = 0;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(entradaAnaloga,INPUT);  
  Serial.begin(9600);
}

void loop() {  
  lecturaSensor = analogRead(entradaAnaloga);      
  //Serial.print("Sensor:");
  Serial.println(lecturaSensor);
  error = ref - lecturaSensor;
  senalControl = k*error;
  //Serial.print("Control:");
  //Serial.println(senalControl);
  
  
  if(senalControl>1024){
    senalControl = 1024;       
  }else if(senalControl<0){
    senalControl = 0;
  }
  senalControl = map(senalControl,0,1024,0,255); //((Señal), (min), (max), (valor entre los que quiero quede)).       
  analogWrite(Tip, senalControl);  
  delay(1000);
}
