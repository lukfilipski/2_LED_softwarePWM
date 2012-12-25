// THIS CODE WORKS - przy F_CPU = 800000UL albo 960000UL

#include <avr/io.h>
#define GREEN PB1
#define RED PB2
#define F_CPU 1000000UL
#define output_low(port,pin) port &= ~(1<<pin)      //makra ulatwiajace czytanie kodu 
#define output_high(port,pin) port |= (1<<pin)
#define set_input(portdir,pin) portdir &= ~(1<<pin)
#define set_output(portdir,pin) portdir |= (1<<pin)

void delay_ms(uint8_t ms) {                   //ustawienia timera
  uint16_t delay_count = F_CPU / 17500;
	volatile uint16_t i;
	
	while (ms != 0) {
		for (i=0; i != delay_count; i++);
		ms--;
	}
}


int main(void) {
	
	int8_t i;
	set_output(DDRB, RED);
	set_output(DDRB, GREEN);
	output_low(PORTB, RED);     //wyjscie RED i GREEN na stan niski
	output_low(PORTB, GREEN);
	
	while (1) {
		/*
    output_high(PORTB, YELLOW);     //zbedny kod
	  delay_ms(20);
		output_low(PORTB, YELLOW);
		delay_ms(50);
		*/

		for (i=0; i <= 25; i++) {
			output_high(PORTB, RED);
			output_low(PORTB, GREEN);
			delay_ms(25-i);
			output_low(PORTB, RED);
			output_high(PORTB, GREEN);
			delay_ms(i);
		}
		
			//delay_ms(500);        //obsolete!
			
		for (i=25; i >=0; i--) {
			output_high(PORTB, RED);
			output_low(PORTB, GREEN);
			delay_ms(25-i);
			output_low(PORTB, RED);
			output_high(PORTB, GREEN);
			delay_ms(i);
		}
	}
}
