/*#pragma config PLLDIV = 2, CPUDIV = OSC1_PLL2, USBDIV = 2
#pragma config FOSC = HSPLL_HS, FCMEN = OFF, IESO = OFF
#pragma config PWRT = OFF, BOR = OFF, BORV = 3, VREGEN = OFF
#pragma config WDT = OFF
#pragma config WDTPS = 32768
#pragma config CCP2MX = ON, PBADEN = OFF, LPT1OSC = OFF, MCLRE = ON
#pragma config STVREN = ON, LVP = OFF, ICPRT = OFF, XINST = OFF
#pragma config CP0 = OFF, CP1 = OFF, CP2 = OFF, CP3 = OFF
#pragma config CPB = OFF, CPD = OFF
#pragma config WRT0 = OFF, WRT1 = OFF, WRT2 = OFF, WRT3 = OFF
#pragma config WRTC = OFF, WRTB = OFF, WRTD = OFF
#pragma config EBTR0 = OFF, EBTR1 = OFF, EBTR2 = OFF, EBTR3 = OFF
#pragma config EBTRB = OFF*/

#define _XTAL_FREQ 48000000
#include <xc.h>
#include <stdio.h>
#include "system.h" 
#include "uart.h"                                    // Libreria de la pantalla lcd
#include "mfrc522.h"                                // Libreria del modulo RFID MFRC522
#include "tick.h"


extern tick_t tRFID;
char UID[8];                                        // Almacena el codigo del UID
char buf[4];                                        // Almacena el UID en formato de cadena
unsigned char TagType;
void RFID_Init()
{
ANSEL=0;
ANSELH=0;// Coloca todos los pines como digitales
uartInit();                                     
MFRC522_Init();
}

void main_RFID_Reader(void)
{
    if (tickRead() - tRFID < 10000 ) {                        
        /*Lcd_Set_Cursor(1,1);                        // Textos iniciales
        Lcd_Write_String("Lector RFID");
        Lcd_Set_Cursor(2,1);
        Lcd_Write_String("ID: ");*/
        
        while(!MFRC522_IsCard(&TagType));           // Verifica si hay TAG presente
        while(!MFRC522_ReadCardSerial(&UID));       // Lee el codigo del TAG
        
//        Lcd_Set_Cursor(2,1);
        //Lcd_Write_String("ID: ");
        for(char i=0; i<4; i++)                     // Imprime el codigo del UID
        {
            sprintf(buf, "%X", UID[i]);
           // Lcd_Write_String(buf);
            SendBuff(buf,4);
        }
        __delay_ms(1000);
        MFRC522_Halt();                             // Apaga la antena
    
}
    }
    