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
/*==================[definiciones y macros]==================================*/

/*==================[definiciones de datos internos]=========================*/

/*==================[definiciones de datos externos]=========================*/
//char datoUser; //Ejemplo

/*==================[declaraciones de funciones internas]====================*/
//static void funcUser(void); //Ejemplo

/*==================[definiciones de funciones internas]=====================*/
//static void funcUser(void){ //Ejemplo
//}; 

/*==================[definiciones de funciones externas]=====================*/
/**
 * @brief	Inicializa Ports, Periféricos e Interrupciones
 * @return	Nada
 */
void appInit(void) {
    /* TODO: Inicializar Ports/Periféricos/Interrupciones */
    /* Configura funciones analógicas y dirección de los Ports de I/O */
    ANSEL        = 0;
    ANSELH       = 0;  
  	TRIS_LED1    = 0;  //sALIDA LED 1, VERIFICA QUE EL PROGRAMA ANDA
    TRIS_LED4    = 0;  //sALIDA LED 1, TITILA A 38KhZ A 5ms
    TRIS_SOUNDER = 0; 
    __delay_ms(100); //Espera que se estabilice la fuente
    
     //Configura Timer1
    TMR1CS=0;
    
    T1CKPS1=0;
    T1CKPS0=0;
    
    
    TMR1ON=1;
    //TODO ...

    //Configura CCP1
    //TODO ...
//      CCP1M0=1;
//      CCP1M1=1;            
//      CCP1M2=0;
//      CCP1M3=1;     
    CCP1CON=0B00001011;
    CCPR1=1000;
    //Configura Timer0
    //TODO ...
            T0CS=0;
            
            PSA=0;
    
            PS0=1;
            PS1=0;
            PS2=0;
                    
    
    /* TODO: Habilita Interrupciones si es necesario*/
    //TMR2IE = 1;
    //PEIE = 1;
    //GIE = 1;  
}


