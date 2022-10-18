#include "DHT.h"
#define dht_type DHT11 //define qual o tipo de sensor DHTxx que se está utilizando
/**
* Configurações iniciais sobre os sensores
* DHT11, LM35, LDR5 e TCRT5000
*/
int dht_pin = A2;
DHT dht_1 = DHT(dht_pin, dht_type); //pode-se configurar diversos sensores DHTxx
int lm35_pin = A0, leitura_lm35 = 0;
float temperatura;
int ldr_pin = A5, leitura_ldr = 0;
int switch_pin = 7;
void setup()
{
Serial.begin(9600);
dht_1.begin();
pinMode(switch_pin, INPUT);
}
void loop()
{
/**
* Bloco do DHT11
*/
float umidade = dht_1.readHumidity();
float temperatura = dht_1.readTemperature();
float temperaturaProjeto = 7.5 * temperatura - (232.5);
float umidadeProjeto = 3.00 * umidade - (99);
float umidade1 = umidadeProjeto * 1.10;
float temperatura1 = temperaturaProjeto * 1.10;
float umidade2 = umidadeProjeto * 0.90;
float temperatura2 = temperaturaProjeto * 0.90;
float umidade3 = umidadeProjeto * 1.40;
float temperatura3 = temperaturaProjeto * 1.40;
float umidade4 = umidadeProjeto * 0.60;
float temperatura4 = temperaturaProjeto * 0.60;
if (isnan(temperatura) or isnan(umidade))
{
Serial.println("Erro ao ler o DHT");
}
else
{
Serial.print(umidadeProjeto);
Serial.print(";");
Serial.print(temperaturaProjeto);
Serial.print(";");
  
Serial.print(umidade1);
Serial.print(";");
Serial.print(temperatura1);
Serial.print(";");

Serial.print(umidade2);
Serial.print(";");
Serial.print(temperatura2);
Serial.print(";");

Serial.print(umidade3);
Serial.print(";");
Serial.print(temperatura3);
Serial.print(";");

Serial.print(umidade4);
Serial.print(";");
Serial.print(temperatura4);
Serial.println(";");

}
/**
 * * Bloco do LM35
leitura_lm35 = analogRead(lm35_pin);
temperatura = leitura_lm35 * (5.0/1023) * 100;
Serial.print(temperatura);
Serial.print(";");
/**
* Bloco do LDR5
leitura_ldr = analogRead(ldr_pin);
Serial.print(leitura_ldr);
Serial.print(";");
/**
* Bloco do TCRT5000
if(digitalRead(switch_pin) == LOW){
Serial.println(1);
}
else {
Serial.println(0);
}*/
delay(2000);
}
