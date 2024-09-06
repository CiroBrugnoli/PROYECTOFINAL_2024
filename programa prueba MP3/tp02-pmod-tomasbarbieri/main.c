/*============================================================================
 * Licencia:
 * Autor:
 * Fecha:
 *===========================================================================*/
/** @file
 * @brief	Contiene la función principal
 * 
 * Aquí se encuentra la implementación de la función principal
 */
/*==================[inlcusiones]============================================*/
#include <xc.h>         /* Archivo de Encabezados General XC8 */
#include <stdint.h>     /* Para las definiciones de uint8_t por ej.*/
#include "system.h"     /* Funciones/Parametros System, como osc/peripheral config */
#include "user.h"       /* Funciones/Parametros User, como InitApp */
#include <stdio.h>      /* Archivo de Encabezados StdIO */
#include "uart.h"       /* Funciones/Parametros User, como InitApp */
#include "disply.h"  
/*==================[definiciones y macros]==================================*/

/*==================[definiciones de datos internos]=========================*/

/*==================[definiciones de datos externos]=========================*/

/*==================[declaraciones de funciones internas]====================*/

/*==================[funcion principal]======================================*/
void main(void) {
 
    /* TODO: Agregar el Cod1iogo de la Aplicación aquí */
    uint8_t comando;
    
    appInit();
    displayInit();          /* Inicializa I/O y Periféricos de la aplicación */
    uartInit ();

    while(1){
    uartWriteByte (00001);
    __delay_ms(2000);
    uartWriteByte (0002);
    __delay_ms(2000);
    uartWriteByte (003);
    __delay_ms(2000);
    }
 } 


/*==================[definiciones de funciones internas]=====================*/

/*==================[definiciones de funciones externas]=====================*/

/*==================[fin del archivo]========================================*/
