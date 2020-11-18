// defines pins numbers
const int trigPin = 5;
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
