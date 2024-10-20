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
#include "tick.h"       /* Funciones/Parametros Tick */
/*==================[definiciones y macros]==================================*/

typedef enum {
    E_SUELTO, E_BAJANDO, E_PRESIONADO, E_SUBIENDO, E_MANTENIDO
} estadoMEF_t;

/*==================[definiciones de datos internos]=========================*/
int Tiempo0 = 0;
int Tiempo1 = 0;
int Mostrar_Tiempo = 0;
int Resta_Tiempo;
estadoMEF_t estadoActual1, estadoActual2; // Variable de estado (global)
tick_t tInicio1, tInicio2;

/*==================[definiciones de datos externos]=========================*/



/*==================[declaraciones de funciones internas]====================*/
void func_interup_boton();
int VALOR_TIMER;
void Control_Led_Rojo(); //Función para que se ingrese cuando cambian los estados de los
                         //pines del sensor o boton de generación
void InicializarMEF(void);
void ActualizarMEF1(void);
void ActualizarMEF2(void);

/*==================[funcion principal]======================================*/

/* TODO: Agregar el Cod1iogo de la Aplicación aquí */
uint8_t comando;

void InicializarMEF(void) {
    estadoActual1 = E_SUELTO; // Establece estado inicial 
    estadoActual2 = E_SUELTO; // Establece estado inicial 
}



void main(void) {
    uint8_t i;
    appInit();
//    appInit(); /* Inicializa I/O y Periféricos de la aplicación */
    InicializarMEF();
    PIN_VIDA1 = 1;
    PIN_LEDPRUEBA = 0;

    while (1) {
        ActualizarMEF1();
        if(estadoActual1 == E_PRESIONADO)
        {
            PIN_VIDA1 = 1;
            
        }
        else
        {
           PIN_VIDA1 = 0;

        }
        
        for (i = 0; i < 190; i++) {
            PIN_LEDPRUEBA = 1;
            __delay_us(10);
            PIN_LEDPRUEBA = 0;
            __delay_us(10);
        }
        __delay_ms(100);
        func_interup_boton();
        while (Mostrar_Tiempo) {
            Mostrar_Tiempo = 0;
            if (Tiempo1>=10) 
            {
               //PIN_VIDA1=1;
            }                
            else 
                //PIN_VIDA1=0;
            Tiempo1=0;    
        }
    }
}

void func_interup_boton() {
    //Acá ingresa el programa cuando cambia el estado un pin de entrada del microcontrolador
    if (PIN_TEC1 == 0) {
        //El botón fue apretado
        Tiempo0 = VALOR_TIMER;
    } else {
        //significa que se dejó de apretar el botón
        Tiempo1 = VALOR_TIMER - Tiempo0;
        Mostrar_Tiempo = 1;
    }
}

void ActualizarMEF1(void) {
    switch (estadoActual1) {
        case E_SUELTO:
            if (PIN_TEC1 == 0) {// Chequear condiciones de transición de estado
                estadoActual1 = E_BAJANDO; // Cambiar a otro estado
                tInicio1 = tickRead(); // También inicia temporizacion
            }
            break;
        case E_BAJANDO:
            if (PIN_TEC1 == 1) {
                estadoActual1 = E_SUELTO;
            } else if (tickRead() - tInicio1 > 800&&PIN_TEC1 == 0) {// Chequear condiciones de transición de estado
                estadoActual1 = E_PRESIONADO; // Cambiar a otro estado
                //incrementaDisplay();
                tInicio1 = tickRead();
            }
            break;
        case E_PRESIONADO:
            if (PIN_TEC1 == 1) {// Chequear condiciones de transición de estado
                estadoActual1 = E_SUBIENDO; // Cambiar a otro estado
                tInicio1 = tickRead(); // También inicia temporizacion
            }
            if (PIN_TEC1 == 0&&tickRead() - tInicio1 > 400) {// Chequear condiciones de transición de estado
                estadoActual1 = E_MANTENIDO; // Cambiar a otro estado
                //incrementaDisplay();
                tInicio1 = tickRead(); // También inicia temporizacion
            }
            break;

        case E_MANTENIDO:
            if (PIN_TEC1 == 1) {
                estadoActual1 = E_SUBIENDO;
                tInicio1 = tickRead();
            }
            if(PIN_TEC1==0){
                estadoActual1 = E_PRESIONADO;
                tInicio1 = tickRead();
            }
            break;
        case E_SUBIENDO:
            if (PIN_TEC1 == 0) {
                estadoActual1 = E_PRESIONADO;
            }
            if (tickRead() - tInicio1 > 40) {// Chequear condiciones de transición de estado
                estadoActual1 = E_SUELTO; // Cambiar a otro estado
            }
            break;
        default:
            //Si algo modificó la variable estadoActual 
            // a un estado no válido llevo la MEF a un 
            // lugar seguro, por ejemplo, la reinicio:
            InicializarMEF();
    }
}

