#include <VirtualWire.h>
#include <AFMotor.h>

byte message[VW_MAX_MESSAGE_LEN];    // Armazena as mensagens recebidas
byte msgLength = VW_MAX_MESSAGE_LEN; // Armazena o tamanho das mensagens
 
int valor_recebido_RF;
int cont;
char recebido_RF_char[40];
char recebido=0;
const int luzfreio = 13;

// motor
AF_DCMotor motor1(1); // Motor conectado à M1
AF_DCMotor motor2(2); // Motor conectado à M2
AF_DCMotor motor3(3); // Motor conectado à M3
AF_DCMotor motor4(4); // Motor conectado à M4


void setup() {

Serial.begin(9600);

    vw_set_rx_pin(11); // Define o pino 11 do Arduino como entrada de dados do receptor
    vw_setup(2000);             // Bits por segundo
    vw_rx_start();              // Inicializa o receptor


  
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(10,OUTPUT);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);


     //motor
     motor1.setSpeed(255); 
     motor2.setSpeed(255); 
     motor3.setSpeed(255); 
     motor4.setSpeed(255);
}


void loop() {
    motor1.run(RELEASE); 
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);


     uint8_t message[VW_MAX_MESSAGE_LEN];    
     uint8_t msgLength = VW_MAX_MESSAGE_LEN; 
 
 
    if (vw_get_message(message, &msgLength)) // Non-blocking
    {          
        for (int i = 0; i < msgLength; i++)
       {
          recebido = message[i];
       }
          switch (recebido){
               case 'F':{ // Gerencia o Frente
                    motor1.run(FORWARD); 
                    motor2.run(FORWARD);
                    motor3.run(FORWARD); 
                    motor4.run(FORWARD);
                    delay(1000);
                    break;
               }
               case 'B':{ // Gerencia o Tras
                    motor1.run(BACKWARD); 
                    motor2.run(BACKWARD); 
                    motor3.run(BACKWARD); 
                    motor4.run(BACKWARD);
                    delay(2000);
                    break;
               }
               case 'T':{ // Genrencia o Tras e esquerda
                    motor1.run(RELEASE); 
                    motor2.run(RELEASE); 
                    motor3.run(BACKWARD); 
                    motor4.run(BACKWARD);
                    delay(1000);
                    break;
               }
               case 'G':{ // Gerencia o Tras e direita 
                    motor1.run(BACKWARD); 
                    motor2.run(BACKWARD); 
                    motor3.run(RELEASE); 
                    motor4.run(RELEASE);
                    delay(1000);
                    break;
               }
               case 'L':{ // Gerencia o frente e esquerda 
                    motor1.run(RELEASE); 
                    motor2.run(RELEASE); 
                    motor3.run(FORWARD); 
                    motor4.run(FORWARD);
                    delay(1000);
                    break;
               }
               case 'A':{ // Gerencia o frente e direita 
                    motor1.run(FORWARD); 
                    motor2.run(FORWARD); 
                    motor3.run(RELEASE); 
                    motor4.run(RELEASE);
                    delay(1000);
                    break;
               }
               case 'V':{ // Motor arma
                    digitalWrite(A1,HIGH);
                    delay(1000);
                    break;
               }
          }  
     }
}