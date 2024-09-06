/*============================================================================
 * Licencia:
 * Autor:
 * Fecha:
 *===========================================================================*/
/** @file
 * @brief	Contiene las definiciones de display
 * 
 * Aquí se encuentra la implementación de display, los defines, macros, 
 * datos internos y externos, declaraciones y definiciones de funciones
 * internas y definiciones de funciones externas.
 */

/*==================[inlcusiones]============================================*/
#include <xc.h>         /* Archivo de Encabezados General XC8 */
#include <stdint.h>     /* para las definiciones de uint8_t por ej.*/
#include "system.h"
#include "display.h"    /* Funciones/Parametros Display */

/*==================[definiciones y macros]==================================*/

/*==================[definiciones de datos internos]=========================*/

/*==================[definiciones de datos externos]=========================*/

/*==================[declaraciones de funciones internas]====================*/

/*==================[definiciones de funciones internas]=====================*/

/*==================[definiciones de funciones externas]=====================*/
/**
 * @brief	Inicializa el Display de 7 segmentos conectado a un puerto
 * @return	Nada
 * @note    Las opciones se modifican en el código, por ejemplo con las 
 * constantes DISPLAY_TRIS y DISPLAY_PORT
 * @sa      DISPLAY_TRIS    
 * @sa      DISPLAY_PORT    
 */
void displaytInit(void) {
    DISPLAY_TRIS = 0;   //Configura todas salidas
    DISPLAY_PORT = 0;   //Apaga el display
}

/**
 * @brief	Muestra un dígito en el Display de 7 segmentos
 * @param[in]   value Código de dígito a mostrar
 * @return  nada
 * @note    Si esta fuera de rango, apaga el display.
 */
 void displayWrite( uint8_t value ){
    const uint8_t tabla7seg[] = {
        0b00111111, //0
        0b00000110, //1
        0b01011011, //2
        0b01001111, //3
        0b01100110, //4
        0b01101101, //5
        0b01111101, //6
        0b00000111, //7
        0b01111111, //8
        0b01100111  //9
    };
    if(value < sizeof (tabla7seg)){ //Si está dentro del rango
        PORTD = tabla7seg[value] ;  // Muestra el numero
    }
    else{                           //Si esta fuera de rango
        PORTD = 0 ;                 // Apaga el display
    }
}

/*==================[fin del archivo]========================================*/
