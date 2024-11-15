#include <stdio.h>
#include <stdlib.h>
#include <xc.h>          /* Archivo de Encabezados General XC8 */
#include "user.h"        /* Archivo de Encabezados StdIO */
#include "system.h"      /* Archivo de Encabezados StdIO */  
#include "tick.h"       /* Funciones/Parametros Tick */
#include "mfrc522.h"



/******************************************************************************
- Función de implementación:
    darse cuenta de que el chip está encendido y especificar la primera y segunda
    canción para reproducir respectivamente.
    El programa básico es para que los usuarios lo prueben.
- Nota:
    1. El programa de prueba debe tener equipos en línea en el módulo o
    solución de chip, como disco U, tarjeta TF
******************************************************************************/
// esto deben sacarlo y poner el tipo de dato de mplab y deberian borrarlo

static uint8_t Send_buf[10];// = {0} ;
void Delay_Ms(uint32_t z)
{
    uint32_t x=0 , y=0;
    for(x=110 ; x>0 ;x--)
        for(y=z; y>0;y-- );
}

/******************************************************************************
- Descripción de la función:
    inicialización del puerto serie
- NOTA: Establecer en 9600 baudios
******************************************************************************/
void Serial_init(void)
{
/*
    TMOD = 0x20;
    SCON = 0x50;
    PCON = 0x00;
    TH1=256-(OSC_FREQ/COMM_BAUD_RATE/32/12);
    TL1=256-(OSC_FREQ/COMM_BAUD_RATE/32/12);
    TR1 = 1;
    REN = 1;
    ES = 1;
*/
}

void Uart_PutByte(uint8_t ch)
{
    printf("%2x",ch);
    /*
    SBUF = ch; while(!TI){;}
    TI = 0;
    */
}
/******************************************************************************
- Descripción de la función:
    el puerto serie envía comandos al exterior [incluidos control y consulta]
- Descripción del parámetro:
    CMD: representa el comando de control, consulte la lista de comandos, que
    también incluye comandos relacionados con la consulta
retroalimentación:
    si se requiere una respuesta [0: no se requiere respuesta, 1: se requiere respuesta]
datos:
    parámetros transferidos

******************************************************************************/

void SendCmd(uint8_t len)
{
    uint8_t i = 0 ;
    Uart_PutByte(0x7E); // comenzar
    for(i=0; i<len; i++)// datos
    {
        Uart_PutByte(Send_buf[i]) ;
    }
    Uart_PutByte(0xEF) ;// Finalizar
}
/******************************************************************************
- Descripción de la función:
    verificación de suma
- La idea de verificación de suma es la siguiente:
    El comando enviado elimina el inicio y el final.
    Acumule los 6 bytes del medio y finalmente tome el complemento.
    El extremo receptor elimina el inicio y el final del marco de datos recibido.

Acumule los datos intermedios y agregue el byte de verificación recibido.
Es exactamente 0.
Esto significa que los datos recibidos son completamente correctos.
******************************************************************************/
void DoSum( uint8_t *Str, uint8_t len)
{
    uint16_t xorsum = 0;
    uint8_t i;
    for(i=0; i<len; i++)
    {
        xorsum = xorsum + Str[i];
    }
    xorsum = 0 -xorsum;
    *(Str+i) = (uint8_t)(xorsum >>8);
    *(Str+i+1) = (uint8_t)(xorsum & 0x00ff);
}

void Uart_SendCMD(uint8_t CMD ,uint8_t feedback , uint16_t dat)
{
    Send_buf[0] = 0xff;
    Send_buf[1] = 0x06;
    Send_buf[2] = CMD;
    Send_buf[3] = feedback;
    Send_buf[4] = (uint8_t)(dat >> 8); // data H
    Send_buf[5] = (uint8_t)(dat);      // data L
    DoSum(&Send_buf[0],6);
    SendCmd(8);
}


/*
int main()
{
    //Serial_init() ;//
    printf("\n");
    Uart_SendCMD(0x03 , 0 , 0x01) ;
    printf("\n");
    Delay_Ms(1000) ;
    Uart_SendCMD(0x03 , 0 , 0x02) ;
    printf("\n");
    Delay_Ms(1000) ;
    Uart_SendCMD(0x03 , 0 , 0x04) ;
    printf("\n SETEO VOLUMNE EN 30\n");
    Uart_SendCMD(0x06 , 0 , 30) ;
    printf("\n SUBE VOLUMEN \n");
    Uart_SendCMD(0x04 , 0 , 0) ;
    printf("\n BAJA VOLUMEN \n");
    Uart_SendCMD(0x05 , 0 , 0) ;
    //while(1) ;
}
*/