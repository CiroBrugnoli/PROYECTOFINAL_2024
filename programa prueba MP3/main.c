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
#include <xc.h>          /* Archivo de Encabezados General XC8 */
#include <stdint.h>      /* Para las definiciones de uint8_t por ej.*/
#include <stdio.h>       /* Archivo de Encabezados StdIO */
#include "user.h"        /* Archivo de Encabezados StdIO */
#include "system.h"      /* Archivo de Encabezados StdIO */

/*==================[definiciones y macros]==================================*/

/*==================[definiciones de datos internos]=========================*/

/*==================[definiciones de datos externos]=========================*/

/*==================[declaraciones de funciones internas]====================*/

/*==================[funcion principal]======================================*/
 
    /* TODO: Agregar el Cod1iogo de la Aplicación aquí */
    uint8_t comando;
    

void main(void) {
   uint8_t i;
   appInit();
   PIN_LED1=1;
   PIN_LED4=0;
    while (1){
        for(i = 0; i < 190; i++){
            PIN_LED4 = 1;
            __delay_us(10);
            PIN_LED4 = 0;
            __delay_us(10);
        }
        __delay_ms(100);

}
}
