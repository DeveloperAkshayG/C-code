//PROPER CODE WITH TIME CALCULATION AND FLOW CALCULATION
#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
#include<stdlib.h>
#include<string.h>
#define LCD_Command_Dir DDRE
#define LCD_Command_Port PORTE
#define LCD_Data_Dir DDRC
#define LCD_Data_Port PORTC
#define RS PE4
#define EN PE2
#define RW PE3

//long int ticks=0;
float ticks;         //for time
volatile int flag0=0;
volatile int flag1=0;
unsigned long overflow=0;
//double overflow=0;
//unsigned int tcntres;
unsigned int tcntres;
double volume=0;       //for volume calulation
double flow=0;		   //for flow calculation flow=vol*60/sec
char tcntresult[20];
char overresult[20];
char ticksres[20];
char flowres[20];

ISR(INT0_vect)   //ISR FOR INT0
{
	flag0=1;
	EIMSK |= (1<<INT1);      //setting interrupt1 on
	EICRA=0XC;				//INT1 ON RISING EDGE
	TCCR0 |= (1<<CS00) | (1<<CS01) | (1<<CS02);   //timer start with 1024 precalar
//	sei();
}

ISR(INT1_vect)   //ISR FOR INT1
{
	flag1=1;
}

ISR (TIMER0_OVF_vect)  //TIMER OVERFLOW ISR
{
	overflow++;
}


void LCD_Command(unsigned char cmnd)
{
	LCD_Data_Port= cmnd;
	LCD_Command_Port &= ~(1<<RS);	/* RS=0 command reg. */
	_delay_ms(1);
	LCD_Command_Port &= ~(1<<RW);	/* RW=0 Write operation */
	_delay_ms(1);
	LCD_Command_Port |= (1<<EN);	/* Enable pulse */
	_delay_ms(1);
	LCD_Command_Port &= ~(1<<EN);
	_delay_ms(1);
}

void LCD_Char (unsigned char char_data)	/* LCD data write function */
{
	LCD_Data_Port= char_data;
	LCD_Command_Port |= (1<<RS);	/* RS=1 Data reg. */
	_delay_ms(1);
	LCD_Command_Port &= ~(1<<RW);	/* RW=0 write operation */
	_delay_ms(1);
	LCD_Command_Port |= (1<<EN);	/* Enable Pulse */
	_delay_ms(1);
	LCD_Command_Port &= ~(1<<EN);
	_delay_ms(1);
}

void LCD_Init(void)
{
	LCD_Command_Dir = 0xFF;
	LCD_Data_Dir = 0xFF;		
	_delay_ms(20);			
	
	LCD_Command (0x38);		//initialize in 8-bit mode
	_delay_ms(1);
	LCD_Command (0x0C);		//display on cursor off
	_delay_ms(1);
	LCD_Command (0x06);		//autoincrement cursor
	_delay_ms(1);
	LCD_Command (0x01);		//clear screen
	_delay_ms(1);
	LCD_Command (0x80);     //cursor at starting point
	_delay_ms(1);
}

void LCD_Clear(void)
{
	LCD_Command (0x01);		/* clear display */
	_delay_ms(1);
	LCD_Command (0x80);		/* cursor at home position */
	_delay_ms(1);
}

void LCD_String (char *str)		/* Send string to LCD function */
{
	int i;
	for(i=0;str[i]!=0;i++)		/* Send each char of string till the NULL */
	{
		LCD_Char (str[i]);
	}
}

void LCD_String_xy (char row, char pos, char *str)/* Send string to LCD with xy position */
{
	if (row == 0 && pos<16)
	LCD_Command((pos & 0x0F)|0x80);	/* Command of first row and required position<16 */
	else if (row == 1 && pos<16)
	LCD_Command((pos & 0x0F)|0xC0);	/* Command of first row and required position<16 */
	LCD_String(str);		/* Call LCD string function */
}


void timer0_init ( )        //timer0 initialization
{
	//int i;
	TCNT0=0X00; //LOAD THE VALUE OF COUNTER REGISTER
//	TCCR0 |= (1<<CS00) | (1<<CS01) | (1<<CS02); //prescalar of 1024 and normal mode
	overflow=0;
	TIMSK |=(1<<TOIE0);
//	sei();
}


int main()
{
	LCD_Init();
	float ID=1.7;             //diameter=3.4mm so radius of capillary in mm is d/2 which is 1.7mm
	int height=47;	   //height of capillary in mm
	double pie=3.14285714286; //pie value used for volume calculation
	LCD_String_xy (0,0,"WELCOME TO");
	LCD_String_xy (1,0,"NETEL FLOWMETER");
	volume=(pie*(ID)*(ID)*(height))/1000; //volume in mm3 which is converted into ml by dividing it with 1000
	DDRD=0X00; //MAKE PORT D AS INPUT
	PORTD=0XFD;  //except pd1 all pins are high
	
//	PORTD=0XFC;  //except pd1 and pd0 all are high 
	
	DDRE=0XFF; //MAKE PORTE OUTPUT PORT
	PORTE=0b01000000;   //LED GLOW FOR INDICATION
	EIMSK |= (1<<INT0); //set int0 interrupt
	EICRA=0b0000010;  //INT0 CONFIGURED FOR FALLING EDGE
	//EICRA=0b0000011;  //INT0 CONFIGURED FOR RISING EDGE
	sei();
	timer0_init();

	PORTE=0b01000000;
	LCD_Clear();
	while(1)
	{
		if(flag0==1)
		{
			//TCCR0 |= (1<<CS00) | (1<<CS01) | (1<<CS02); //START TIMER WITH 1024 PRESCALAR
			//LCD_Clear();
			EIMSK &= ~(1<<INT0); //disable int0
			tcntres=TCNT0;
			sprintf(tcntresult,"tcnt=%d ov=%lu",tcntres,overflow);
			LCD_String_xy(1,0,tcntresult);
			ticks=(((float)overflow) * 0.03264) + (((float)tcntres) * 0.000128);
			sprintf(ticksres,"t=%.2f",ticks);
			LCD_String_xy(0,0,ticksres);
			//sprintf(overresult,"",);
			if(flag1==1)
			{
				TCCR0=0X00;
			//	LCD_Clear();
				//LCD_String_xy(0,0,overresult);
				//LCD_String_xy(1,0,tcntresult);
				ticks=(overflow * 0.03264) + (tcntres * 0.000128);
				sprintf(ticksres,"time=%.2f",ticks);
				//LCD_String_xy(0,0,ticksres);
				//flow=vol*60/sec
				flow=(volume*60)/ticks;
				sprintf(flowres,"fl=%lf",flow);
				LCD_String_xy(0,8,flowres);
				EICRA &= ~(1<<INT1);
			}
		}
	}
}
	