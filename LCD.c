#include<reg51.h>

sfr LCD= 0XA0; //p2=lcd pins
sbit RS=P3^2;
sbit RW=P3^1;
sbit EN=P3^0;

void LCD_INI(void); //INITIALIZED FUNCITON
void LCD_CMD(unsigned char); //LCD COMMAND SEND FUNCTION
void LCD_DATA(unsigned char);//LCD DATA SEND FUNCTION
void delay(unsigned int);

void main(void){
	delay(50);
	LCD_INI();
	LCD_DATA('S'); // load 's' on lcd
	LCD_DATA('R');
	LCD_DATA('I');
	LCD_DATA('J');
	LCD_DATA('A');
	LCD_DATA('N');
	while(1);
}

void LCD_INI(void){
	delay(50);
	LCD_CMD(0x38); //set function 00111000
	LCD_CMD(0x0E); //set display on/off 00001110
	LCD_CMD(0x01);//clear display 00000001
}
void LCD_CMD(unsigned char x){
	LCD=x; // put x in lcd
	RS=0;
	RW=0;
	EN=1;
	delay(1);
	EN=0;
	return;
}

void LCD_DATA(unsigned char w){
	LCD=w; // put w in lcd
	RS=1;
	RW=0;
	EN=1;
	delay(1);
	EN=0;
	return;
}

void delay(unsigned int ms){
	unsigned int i,j;
	for(i=0;i<ms;i++)
	for(j=0;j<100;j++);
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	