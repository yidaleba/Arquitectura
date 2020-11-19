// defines pins numbers#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3);
# define entrada 4
# define audio 12
#define Pecho 6
#define Ptrig 7
#define MOTOR 13
long duracion, distancia;

void setup()
{
  Serial.begin(9600);
  pinMode(Pecho, INPUT);
  pinMode(Ptrig, OUTPUT);
  pinMode(MOTOR, OUTPUT);


   Serial.begin(9600);
  BTSerial.begin(9600);

  pinMode (entrada, INPUT);
  pinMode (audio, OUTPUT);
}

void loop()
{
  digitalWrite(Ptrig, LOW);
  delayMicroseconds(2);
  digitalWrite(Ptrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Ptrig, LOW);

  duracion = pulseIn(Pecho,HIGH);
  distancia = (duracion/2)/29;

  if(distancia >= 500 || distancia <=0)
  {
    Serial.print("---");
  }
  else
  {
    Serial.print(distancia);
    Serial.println("cm");
    digitalWrite(MOTOR, 0);  
  }

  if(distancia<=80 && distancia >= 0)
  {
    digitalWrite(MOTOR, 1);
    //Serial.println("Alarma.....");
  }
  delay(400);
  
  int v_entrada = digitalRead(entrada);
  
  if (BTSerial.available()) {
    char Mensaje = BTSerial.read();
    if (Mensaje == 'A') {
       tone(audio, 300 );
      Serial.println("Encender alarma");
    }
    else if (Mensaje == 'B')
    {
       noTone(audio);
      Serial.println("Apagar alarma");
    }
  }
  
} = 5;
const int echoPin = 4;
int button = 10;
int state = 0; 
int luz = 13;
int luz2 = 9;

// defines variables
long duration;
int distance;



void setup() {
pinMode(trigPin, OUTPUT); // ponemos el pin triPin como salida
pinMode(echoPin, INPUT); // ponemos el pin echoPin como entrada
pinMode(luz, OUTPUT);
pinMode(button,INPUT);
pinMode(luz2,OUTPUT);
Serial.begin(9600); // comenzamos con la velocidad de comunicacion del puerto serial
}

void loop() {
      
            digitalWrite(trigPin, LOW);
              delayMicroseconds(2);
              // ponemos el trigpin en estado alto por 10 microsegundos para este sensor
              digitalWrite(trigPin, HIGH);
              delayMicroseconds(10);
              digitalWrite(trigPin, LOW);
              // Reads the echoPin, returns the sound wave travel time in microseconds
              duration = pulseIn(echoPin, HIGH);
              // Calculating the distance
              distance= duration*0.034/2;
              // Prints the distance on the Serial Monitor
                  if(distance > 500)
                  {
                    digitalWrite(luz,HIGH);
                    
                  }else
                  {
                    digitalWrite(luz,LOW);
                  }
                  if(button == HIGH)
                  {
                    digitalWrite(luz2,HIGH);
                  }else{
                    digitalWrite(luz2,LOW);
                  }
                      Serial.print("Distancia baston: ");
                  Serial.println(distance);
                  Serial.print(button);
      


}
