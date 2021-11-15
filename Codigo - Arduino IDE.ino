//PRJETO - Felipe Takao Lago
//TIA: 32010443

//LEDs
int ledVerme = 2;
int ledAmare = 3;
int ledVerde = 4;

//Sensor de Nivel de Agua
int valor = 0;
int nivel = 0;

//Valvula
int valvula = 10;
boolean estadoAbertoVal = false;

void setup()
{
  Serial.begin(9600);
  
  //Sensor 
  pinMode(A0, INPUT);

  //LEDs
  pinMode(ledVerme, OUTPUT);
  pinMode(ledAmare, OUTPUT);
  pinMode(ledVerde, OUTPUT);

  //Valvula
  pinMode(valvula, OUTPUT);

}

void loop()
{
  
  nivel = analogRead(A0);
 //nivel = map(nivel, 0, 250, 0, 100);

 //Serial.print("Nivel da Agua: ");
 //Serial.println(nivel);
 //Serial.println("%");
 
 if (nivel <= 5){
  Serial.println("Nao ha agua!");

  digitalWrite(ledVerme, LOW);
  digitalWrite(ledAmare, LOW);
  digitalWrite(ledVerde, LOW);
  }
  else if (nivel <= 200){
    Serial.println("Pouca agua no bebedouro");

    digitalWrite(ledVerme, HIGH);
    digitalWrite(ledAmare, LOW);
    digitalWrite(ledVerde, LOW);
    }
 else if(nivel > 200 && nivel <= 240){
  Serial.println("Media agua no bebedouro");

  digitalWrite(ledVerme, LOW);
  digitalWrite(ledAmare, HIGH);
  digitalWrite(ledVerde, LOW);
  }
 else{
  Serial.println("O bebedouro esta CHEIO");

  digitalWrite(ledVerme, LOW);
  digitalWrite(ledAmare, LOW);
  digitalWrite(ledVerde, HIGH);
 }
 if (nivel <= 241  && nivel >= 25){
  digitalWrite(valvula, HIGH);
  }
  else{
    digitalWrite(valvula, LOW);
  }

  Serial.print("nivel: ");
  Serial.println(nivel);
  
 if(tempo > 100000){
 Firmata.sendString(
   (String("{ \"nivel\": ")
   +String(nivel)
   +String("}")).c_str()
   );
   tempo = 0;
 }else{
   tempo++;
 }
}
