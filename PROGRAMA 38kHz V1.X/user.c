/*============================================================================
 * Licencia:
 * Autor:
 * Fecha:
 *===========================================================================*/
/** @file
 * @brief	Contiene las definiciones de user
 * 
 * Aquí se encuentra la implementación de users, los defines, macros, 
 * datos internos y externos, declaraciones y definiciones de funciones
 * internas y definiciones de funciones externas.
 */

/*==================[inlcusiones]============================================*/
#include <xc.h>         /* Archivo de Encabezados General XC8 */
#include <stdint.h>     /* para las definiciones de uint8_t por ej.*/

#include "system.h"     /* Funciones/Parametros System, como conf de osc/perif */
#include "user.h"       /* Funciones/Parametros User, como InitApp */
#include "uart.h"       /* Funciones/Parametros Uart */
#include "display.h"    /* Funciones/Parametros Display */
/*==================[definiciones y macros]==================================*/



 void appInit(void) {
    /* TODO: Inicializar Ports/Periféricos/Interrupciones */

    /* Configura funciones analógicas y dirección de los Ports de I/O */
    ANSEL = 0;
    ANSELH = 0;
    TRIS_VIDA1 = 1;
    TRIS_TEC1 = 1;
      TRIS_SOUNDER = 0;
    uartInit();
    displaytInit();

    //Configura Timer1

    TMR1CS = 0; //CLOCK INTERNO
    T1CKPS1 = 0; //PRESSCALER
    T1CKPS0 = 0;
    TMR1ON = 1;


    //Configura CCP1
    CCP1CON = 0b00001011; // esto lo pone como comparador
    CCPR1 = 1000; //PARA INTERRUMPIR CADA 1000us da la frecuencia

    //Configura Timer0
    T0CS = 0;
    PSA = 0;
    PS0 = 1;
    PS1 = 0;
    PS2 = 0;


    __delay_ms(100); //Espera que se estabilice la fuente

    /* TODO: Habilita Interrupciones si es necesario*/
    CCP1IE = 1; //EL ENEBLE 
    PEIE = 1; //PERIFERICOS
    GIE = 1; //ACTIVA LAS INTERRUCIONES 
}

/**
 * @brief	Demora una cantidad de mSegs basado en desbordes de TMR0
 * @param[in] tmsegs Cantidad ed milisegundos de la demora
 * @return  nada
 * @note    Debe estar previamente configurado el TMR0
 */

void delayTMR0mSeg(uint16_t tmsegs) {
    for (uint16_t cont = 0; cont < tmsegs; cont++) {
        TMR0 = 6;
        T0IF = 0;
        while (T0IF == 0);
    }
}

//void speakerPlay(uint16_t semiper, uint16_t tmsegs) {
    //if (semiper == Silencio) {//es silencio
     ////} else {//es nota
     //   TMR1 = 0; //QUE EL TIMER1 EMPIECE DE 0
     //   CCPR1 = semiper; //igualo al ccp1 al semiperiodo
     //   TMR1ON = 1; //ENCIENDE EL TIMER1
    //}
   // delayTMR0mSeg(tmsegs);
//}   
 
     
    
