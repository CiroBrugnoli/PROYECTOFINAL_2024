/*============================================================================
 * Licencia:
 * Autor:
 * Fecha:
 *===========================================================================*/
/** @file
 * @brief	Contiene macros y definiciones de user
 * 
 * Aquí se definen macros, tipos de datos y se declaran las funciones y datos 
 * externos de user
 */
#ifndef USER_H
#define USER_H
/*==================[inclusiones]============================================*/
#include <stdint.h>     /* para las definiciones de uint8_t por ej.*/

/*==================[macros]=================================================*/
/* User Level #define Macros                                                 */
/* TODO: Los parámetros de user.c pueden ponerse aquí */
    
//Leds
#define	TRIS_LED1       TRISEbits.TRISE2
#define	PIN_LED1        PORTEbits.RE2
#define	TRIS_LED4       TRISAbits.TRISA5
#define	PIN_LED4        PORTAbits.RA5


//Alias de los Leds
#define	TRIS_VIDA1          TRIS_LED1 
#define	PIN_VIDA1           PIN_LED1
#define	TRIS_LEDPRUEBA      TRIS_LED4
#define	PIN_LEDPRUEBA       PIN_LED4 

//Buzzer
#define	TRIS_SOUNDER    TRISCbits.TRISC0
#define	PIN_SOUNDER     PORTCbits.RC0

/*==================[tipos de datos declarados por el usuario]===============*/

/*==================[declaraciones de datos externos]========================*/
//extern char datoUser; //Ejemplo

/*==================[declaraciones de funciones externas]====================*/
/* TODO: Los prototipos de User level (ej. InitApp) van aquí */
void appInit(void);     /* Inicializa las I/O y los periféricos */
/*==================[fin del archivo]========================================*/
#endif// USER_H