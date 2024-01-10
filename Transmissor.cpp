// @author Gabriel Alves Ramos
//Projeto Carro robô controlado via RF 433 Mhz
//Código do Transmissor - controle
 
#include <VirtualWire.h>

int cont;
int estadoB1;
int estadoB2;
int estadoB3;
int estadoB4;
int estadoB5;

void setup()
{
   Serial.begin(9600);    // Debugging only
   Serial.println("setup");
   pinMode(13,OUTPUT);
   // Initialise the IO and ISR
   vw_set_tx_pin(7); 
   vw_setup(2000);  // Bits por segundo
   pinMode(6,INPUT_PULLUP);
   pinMode(3,INPUT_PULLUP);
   pinMode(4,INPUT_PULLUP);
   pinMode(5,INPUT_PULLUP);
   pinMode(8,INPUT_PULLUP);
}

void loop()
{

   estadoB1=digitalRead(6); //esquerda
   estadoB2=digitalRead(3); //frente
   estadoB3=digitalRead(4); //direita
   estadoB4=digitalRead(5); //tras
   estadoB5=digitalRead(8); //arma

   // Gerencia o Tras 
   if(estadoB1 == HIGH && estadoB2 == HIGH && estadoB3 == HIGH && estadoB4 == LOW){
      const char *msg = "B";

      digitalWrite(13, HIGH); // Pisque uma luz para mostrar a transmissão
      vw_send((uint8_t *)msg, strlen(msg));
      vw_wait_tx(); // Espere até que toda a mensagem desapareça
      digitalWrite(13, LOW);
      
   } 
   // Genrencia o Tras e esquerda
   else if (estadoB1 == LOW && estadoB2 == HIGH && estadoB3 == HIGH && estadoB4 == LOW){
      const char *msg = "T";

      digitalWrite(13, HIGH); // Pisque uma luz para mostrar a transmissão
      vw_send((uint8_t *)msg, strlen(msg));
      vw_wait_tx(); // Espere até que toda a mensagem desapareça
      digitalWrite(13, LOW);

   }
   // Gerencia o Tras e direita 
   else if (estadoB1 == HIGH && estadoB2 == HIGH && estadoB3 == LOW && estadoB4 == LOW){
      const char *msg = "G";

      digitalWrite(13, HIGH); // Pisque uma luz para mostrar a transmissão
      vw_send((uint8_t *)msg, strlen(msg));
      vw_wait_tx(); // Espere até que toda a mensagem desapareça
      digitalWrite(13, LOW);

   }
   // Gerencia o Frente
   else if (estadoB1 == HIGH && estadoB2 == LOW && estadoB3 == HIGH && estadoB4 == HIGH){
      const char *msg = "F";

      digitalWrite(13, HIGH); // Pisque uma luz para mostrar a transmissão
      vw_send((uint8_t *)msg, strlen(msg));
      vw_wait_tx(); // Espere até que toda a mensagem desapareça
      digitalWrite(13, LOW);

   }
   // Gerencia o frente e esquerda 
   else if (estadoB1 == LOW && estadoB2 == LOW && estadoB3 == HIGH && estadoB4 == HIGH){
      const char *msg = "L";

      digitalWrite(13, HIGH); // Pisque uma luz para mostrar a transmissão
      vw_send((uint8_t *)msg, strlen(msg));
      vw_wait_tx(); // Espere até que toda a mensagem desapareça
      digitalWrite(13, LOW);

   }
   // Gerencia o frente e direita 
   else if (estadoB1 == HIGH && estadoB2 == LOW && estadoB3 == LOW && estadoB4 == HIGH){
      const char *msg = "A";

      digitalWrite(13, HIGH); // Pisque uma luz para mostrar a transmissão
      vw_send((uint8_t *)msg, strlen(msg));
      vw_wait_tx(); // Espere até que toda a mensagem desapareça
      digitalWrite(13, LOW);

   }
   // Motor arma
   if (estadoB5 == LOW){
      const char *msg = "V";

      digitalWrite(13, HIGH); // Pisque uma luz para mostrar a transmissão
      vw_send((uint8_t *)msg, strlen(msg));
      vw_wait_tx(); // Espere até que toda a mensagem desapareça
      digitalWrite(13, LOW);
      
   } 

}
