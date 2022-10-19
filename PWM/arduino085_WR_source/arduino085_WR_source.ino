
// --- Protótipo das Funções Auxiliares ---
 
void setFrequency(char option);     //Seleciona a frequência de operação do PWM


// --- Variáveis Globais ---
int adc = 0x00;                     //Armazena grandeza analógica
#define pin 3


// --- Configurações Iniciais ---
void setup()
{
  pinMode( pin, OUTPUT);   //saída PWM pino 3
  Serial.begin(9600);

  
  TCCR2A = 0xA3;         //Configura operação em fast PWM, utilizando registradores OCR2x para comparação
                         //1010 0011
  setFrequency(7);       //Seleciona opção 7 para frequência PWM (aprox 60Hz)
  
  

} //end setup

void loop()
{
   adc = analogRead(A0);
   
   adc = map(adc,0,1023,0,255);

   OCR2B = adc;
  
   Serial.println(adc);

 
 
} //end loop


void setFrequency(char option)
{
  /*
  TABLE:
  
      option  frequency
        
        1      62.5  kHz
        2       7.81 kHz
        3       1.95 kHz
        4     976.56  Hz
        5     488.28  Hz
        6     244.14  Hz
        7      61       .03  Hz   
  */
  TCCR2B = option;
  
   

} //end setFrequency
