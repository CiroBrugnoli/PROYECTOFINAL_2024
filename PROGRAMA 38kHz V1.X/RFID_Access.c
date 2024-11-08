#pragma config PLLDIV = 2, CPUDIV = OSC1_PLL2, USBDIV = 2
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
#pragma config EBTRB = OFF

#define _XTAL_FREQ 48000000
#include <xc.h>
#include <stdio.h>

#include "lcd.h"                                        // Libreria de la pantalla lcd
#include "mfrc522.h"                                    // Libreria del modulo RFID MFRC522

char UID[8];                                            // Almacena el codigo del UID
char buf[4];                                            // Almacena el UID en formato de cadena
unsigned char TagType;

const char usuario_1[4] = {0xF6,0x1E,0x86,0xBB};        // Llavero
const char usuario_2[4] = {0x24,0x1D,0x4C,0xFF};        // TAG 1

void main()
{
    ADCON1bits.PCFG = 0x0F;                             // Coloca todos los pines como digitales
    TRISBbits.RB2 = 0;                                  // Pin RB2 como salida
    TRISBbits.RB3 = 0;                                  // Pin RB3 como salida
    LATBbits.LB2 = 0;
    LATBbits.LB3 = 0;
    Lcd_Init();                                         // Inicializa la pantalla lcd
    MFRC522_Init();                                     // Inicializa el modulo MFRC522
        
    while(1)
    {
        Lcd_Set_Cursor(1,1);                            // Solicita ingresar tarjeta
        Lcd_Write_String("Ingresa Tarjeta");
        
        while(!MFRC522_IsCard(&TagType));               // Verifica si hay TAG presente
        while(!MFRC522_ReadCardSerial(&UID));           // Lee el codigo del TAG
        
        Lcd_Clear();
        Lcd_Set_Cursor(1,1);
        Lcd_Write_String("ID: ");
        for(char i=0; i<4; i++)                         // Imprime el codigo del UID
        {
            sprintf(buf, "%X", UID[i]);
            Lcd_Write_String(buf);
        }
        
        if(MFRC522_Compare_UID(UID, usuario_1))         // Compara la UID del usuario 1 (llavero)
        {
            LATBbits.LB2 = 1;                           // Enciende el led verde
            LATBbits.LB3 = 0;
            Lcd_Set_Cursor(2,1);
            Lcd_Write_String("Acceso Correcto");
            __delay_ms(3000);
        }
        else if(MFRC522_Compare_UID(UID, usuario_2))    // Compara la UID del usuario 2 (TAG 1)
        {
            LATBbits.LB2 = 1;                           // Enciende el led verde
            LATBbits.LB3 = 0;
            Lcd_Set_Cursor(2,1);
            Lcd_Write_String("Acceso Correcto");
            __delay_ms(3000);
        }
        else                                            // Error de acceso
        {
            LATBbits.LB2 = 0;
            LATBbits.LB3 = 1;                           // Enciende el led rojo
            Lcd_Set_Cursor(2,1);
            Lcd_Write_String("Acceso Denegado");
            __delay_ms(2000);
        }
        LATBbits.LB2 = 0;                               // Apaga los leds
        LATBbits.LB3 = 0;
        Lcd_Clear();
        MFRC522_Halt();                                 // Apaga la antena
    }
}