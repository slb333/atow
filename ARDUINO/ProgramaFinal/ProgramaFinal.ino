#include <SoftwareSerial.h>   // Incluimos la librería  SoftwareSerial  
SoftwareSerial miBT(10,11);    // Definimos los pines RX y TX del Arduino conectados al Bluetooth
char DATO = 0;
int led = 3;                // AL PIN DONDE ESTA CONECTADO
 
void setup()
{
  miBT.begin(38400);       // Inicializamos el puerto serie BT (Para Modo AT 2)velocidad= 38400
  pinMode(led, OUTPUT);     // SE COMO SALIDA EL PIN
}
 
void loop()
{
  if(miBT.available())    // Si llega un dato por el puerto BT se envía al monitor serial
  {
    DATO = miBT.read();
    if(DATO == 'I'){
      digitalWrite(led, HIGH);
    }
    if(DATO == 'O'){
      digitalWrite(led, LOW);
    }
  }
}