/*********************************************
* MSYS, LAB7, Part 2                         *
* Testprogram for Switch port driver         *
* Henning Hargaard 23/9 2015                 *
**********************************************/
#define F_CPU 16000000
#include <util/delay.h>
#include <avr/io.h>
#include "switch.h"
#include "led.h"

int main()
{
  unsigned char i;

  // Klarg�ring af SWITCH-porten
  initSwitchPort();
  // Klarg�ring af LED-porten
  initLEDport();
	
  // Test af switchStatus():
  // Resultatet skrives til hele lysdiodeporten
  // Testen afsluttes, n�r man samtidigt
  // trykker p� SW7 og SW0
  i = 0;
  while (i != 0b10000001)
  {
    i = switchStatus();
    writeAllLEDs(i);
  }

  // T�nd alle lysdioder i 2 sekunder
  // og sluk s� alle lysdioder
  // S� kan vi se, at n�ste test starter
  writeAllLEDs(0xFF);
  _delay_ms(2000);
  writeAllLEDs(0);
  _delay_ms(2000);

  // Test af switchOn():
  // L�s efter tur hver enkelt switch
  // og t�nd tilsvarende lysdiode, hvis der trykkes p� tasten
  // - ellers slukkes lysdiden
  while (1)
  {
    for (i=0; i<=7; i++)
    {
      if (switchOn(i))
        turnOnLED(i);
      else
        turnOffLED(i);
    }
  }
}