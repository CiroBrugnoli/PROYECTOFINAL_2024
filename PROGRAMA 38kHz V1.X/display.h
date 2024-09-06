/*============================================================================
 * Licencia:
 * Autor:
 * Fecha:
 *===========================================================================*/
/** @file
 * @brief	Contiene macros y definiciones de la Disply
 * 
 * Aquí se definen macros, tipos de datos y se declaran las funciones y datos 
 * externos de Disply
 */
#ifndef DISPLAY_H
#define DISPLAY_H
/*==================[inclusiones]============================================*/
#include <stdint.h>     /* para las definiciones de uint8_t por ej.*/

/*==================[macros]=================================================*/
//Puerto del display 7 segmentos
#define	DISPLAY_PORT    PORTD
#define	DISPLAY_TRIS    TRISD

/*==================[tipos de datos declarados por el usuario]===============*/

/*==================[declaraciones de datos externos]========================*/

/*==================[declaraciones de funciones externas]====================*/
void displaytInit( void ); /* Inicializa el Display conectado a un puerto */
void displayWrite( uint8_t value );  /* Muestra un dígito en el Display */

/*==================[fin del archivo]========================================*/
#endif// DISPLAY_H
