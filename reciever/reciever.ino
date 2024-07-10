void setup() {

  #include <VirtualWire.h>
#define ledPin 6

void setup()
{Serial.begin(9600);
    vw_set_rx_pin(11);
    vw_setup(2000);
    pinMode(ledPin, OUTPUT);
    vw_rx_start();
}

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN; 
 
    if (vw_get_message(buf, &buflen))
    {
      if(buf[0]=='H')
      {  
       digitalWrite(ledPin,HIGH);
       for(int i=0;i<15;i++){
       Serial.print(char(buf[i]));
       }

      }  
      else if(buf[0]=='Y')
        {
       digitalWrite(ledPin,LOW);
        for(int i=0;i<8;i++){
       Serial.print(char(buf[i]));
        }
      }
    }
}

  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
