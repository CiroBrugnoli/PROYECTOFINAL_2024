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
#define	TRIS_LED2       TRISEbits.TRISE1
#define	PIN_LED2        PORTEbits.RE1
#define	TRIS_LED3       TRISEbits.TRISE0
#define	PIN_LED3        PORTEbits.RE0
#define	TRIS_LED4       TRISBbits.TRISB1
#define	PIN_LED4        PORTBbits.RB1
#define	TRIS_LED5       TRISBbits.TRISB2
#define	PIN_LED5        PORTBbits.RB2
#define	TRIS_LED6       TRISBbits.TRISB3
#define	PIN_LED6        PORTBbits.RB3

#define TRIS_TEC1       TRISAbits.TRISA1 //Boton de generada
#define PIN_TEC1        PORTAbits.RA1
#define TRIS_TEC2       TRISAbits.TRISA2 //Sensor laser
#define PIN_TEC2        PORTAbits.RA2
//Alias de los Leds
#define	TRIS_VIDA1          TRIS_LED1 
#define	PIN_VIDA1           PIN_LED1
#define	TRIS_LEDPRUEBA      TRIS_LED4
#define	PIN_LEDPRUEBA       PIN_LED4 
#define CANTIDAD_MAX    30

//alias botones/entradas

#define PIN_GATILLO     PIN_TEC1  //entrada
#define TRIS_GATILLO    TRIS_TEC1
#define PIN_VIDA        PIN_TEC2    //entrada
#define TRIS_VIDA       TRIS_TEC2


//Buzzer
#define	TRIS_SOUNDER    TRISCbits.TRISC0
#define	PIN_SOUNDER     PORTCbits.RC0

#define TRIS_TMR0IF     INTCONbits
#define PIN_TMR0IF     INTCONbits
/*==================[tipos de datos declarados por el usuario]===============*/

/*==================[declaraciones de datos externos]========================*/
//extern char datoUser; //Ejemplo

/*==================[declaraciones de funciones externas]====================*/
/* TODO: Los prototipos de User level (ej. InitApp) van aquí */
void appInit(void);     /* Inicializa las I/O y los periféricos */
void main_RFID_Reader(void);
/*==================[fin del archivo]========================================*/
#endif// USER_H
 