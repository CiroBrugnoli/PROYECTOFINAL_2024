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
#include "mfrc522.h"
/*==================[definiciones y macros]==================================*/

typedef enum {
    E_SUELTO, E_BAJANDO, E_PRESIONADO, E_SUBIENDO, E_MANTENIDO ,
    VIVO , MUERTO ,REVIVIENDO, VIDA_INF 
} estadoMEF_t;

/*==================[definiciones de datos internos]=========================*/
uint8_t Tiempo0 = 0;
uint8_t Tiempo1 = 0;
uint8_t RFID;
uint8_t tInicioRonda;        
uint8_t Mostrar_Tiempo = 0;
uint8_t Resta_Tiempo;
uint8_t DISPAROS = CANTIDAD_MAX;
uint8_t INMORTAL;
uint8_t BALAS_INF;
uint8_t cont_balas = 30;
uint8_t VIDAS;
 

estadoMEF_t estadoActualGAT, estadoActualRONDA; // Variable de estado (global)
tick_t tInicioGAT, tInicioBALAS, tRFID;
char gatilloAP(void);
char rx_LSR(void);
char sumar_vida(void);
void RFID_Init();
/*==================[definiciones de datos externos]=========================*/
  


/*==================[declaraciones de funciones internas]====================*/
void func_interup_boton();
uint8_t VALOR_TIMER;
void Control_Led_Rojo(); //Función para que se ingrese cuando cambian los estados de los                         //pines del sensor o boton de generación
void InicializarMEF(void);
void ActualizarRONDA(void);
void ActualizarGAT(void);

/*==================[funcion principal]======================================*/

/* TODO: Agregar el Cod1iogo de la Aplicación aquí */
uint8_t comando;

void InicializarMEF(void) {}

void main(void) {
    uint8_t i;
    appInit();
//    appInit(); /* Inicializa I/O y Periféricos de la aplicación 
    InicializarMEF();
    PIN_VIDA1 = 1;
    PIN_LEDPRUEBA = 0;

    while (1) {
        tRFID = tickRead();
        main_RFID_Reader();
    
}}
 /*       ActualizarRONDA();
        // prenmdo led rojko para saber en que estado estoy
        if( estadoActualGAT == E_PRESIONADO )
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
//        func_interup_boton();
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
         gatilloAP();
         rx_LSR();
         if(VIDAS==0)
             sumar_vida();
    }
}

/*
void func_interup_boton() {
    Acá ingresa el programa cuando cambia el estado un pin de entrada del microcontrolador
    if (PIN_TEC1 == 0) {
        //El botón fue apretado
        Tiempo0 = VALOR_TIMER;
    } else {
        //significa que se dejó de apretar el botón
        Tiempo1 = VALOR_TIMER - Tiempo0;
        Mostrar_Tiempo = 1;
    }
}
*/
char gatilloAP(void){
    __delay_ms(300);
    if(PIN_GATILLO==1)
        PIN_VIDA=0;
    else            
        PIN_VIDA=1;     

}

char rx_LSR(void){
        __delay_ms(300);
    if( !TRIS_TEC2)
        VIDAS--;
           
}
    
void ActualizarRONDA(void) {
    switch (estadoActualRONDA) {
        case VIVO:
            if (PIN_VIDA1 == 0) {// Chequear condiciones de transición de estado
                if (INMORTAL ==0)estadoActualRONDA=MUERTO;
                //prendeled verde
            }
           
            if (BALAS_INF == 1){
                tInicioBALAS=tickRead();
                PIN_LED4=!PIN_LED4;
                PIN_LED5=!PIN_LED5;
                PIN_LED6=!PIN_LED6;
                estadoActualRONDA = BALAS_INF; 
            }
            break;
        /*case BALAS_INF://seva
            if (tInicioBALAS)
            if (tickRead() - tInicioBALAS) {
                estadoActualRONDA = E_SUELTO;
            } else if (tickRead() - tInicioGAT > 800 && PIN_TEC1 == 0) {// Chequear condiciones de transición de estado
                estadoActualRONDA = E_PRESIONADO; // Cambiar a otro estado
                //incrementaDisplay();
                tInicioGAT = tickRead();
            }
            break;*/
        case MUERTO:
            if (RFID == 1) {// Chequear condiciones de transición de estado
                estadoActualRONDA = REVIVIENDO; // Cambiar a otro estado
                tInicioRonda = tickRead(); // También inicia temporizacion
                //Sonido
            }
            break;
        case REVIVIENDO:
            if(tickRead()-tInicioRonda>5000)
             estadoActualRONDA = VIVO;
            break;
        default:
            //Si algo modificó la variable estadoActual 
            // a un estado no válido llevo la MEF a un 
            // lugar seguro, por ejemplo, la reinicio:
            InicializarMEF();
        }    
}

void ActualizarGAT(void)
//void ActualizarMEF1(void) 
{
    switch (estadoActualGAT) {
        case E_SUELTO:
            if (PIN_TEC1 == 0) {// Chequear condiciones de transición de estado
                estadoActualGAT = E_BAJANDO; // Cambiar a otro estado
                tInicioGAT = tickRead(); // También inicia temporizacion
            }
            break;
        case E_BAJANDO:
            if (PIN_TEC1 == 1) {
                estadoActualGAT = E_SUELTO;
            } else if (tickRead() - tInicioGAT > 20   && PIN_TEC1 == 0) {// Chequear condiciones de transición de estado
                estadoActualGAT = E_PRESIONADO; // Cambiar a otro estado
                //incrementaDisplay();
                tInicioGAT = tickRead();
            }
            break;
        case E_PRESIONADO:
            if (PIN_TEC1 == 1) {// Chequear condiciones de transición de estado
                estadoActualGAT = E_SUBIENDO; // Cambiar a otro estado
                tInicioGAT = tickRead(); // También inicia temporizacion
            }
            if (PIN_TEC1 == 0 && tickRead() - tInicioGAT > 40) {// Chequear condiciones de transición de estado
                estadoActualGAT = E_MANTENIDO; // Cambiar a otro estado
                if( BALAS_INF == 0)
                  cont_balas--;
                tInicioGAT = tickRead(); // También inicia temporizacion
            }
            if( BALAS_INF == 0){
                cont_balas--;
                tInicioGAT = tickRead(); // También inicia temporizacion
            }
            break;
        case E_MANTENIDO:
            if (PIN_TEC1 == 1) {
                
                estadoActualGAT = E_SUBIENDO;
                tInicioGAT = tickRead();
            }
            if(PIN_TEC1==0){
                estadoActualGAT = E_PRESIONADO;
                tInicioGAT = tickRead();
            }
            break;
        case E_SUBIENDO:
            if (PIN_TEC1 == 0) {
                estadoActualGAT = E_PRESIONADO;
            }
            else if (tickRead() - tInicioGAT > 40) {// Chequear condiciones de transición de estado
                estadoActualGAT = E_SUELTO; // Cambiar a otro estado
            }
            break;
        default:
            //Si algo modificó la variable estadoActual 
            // a un estado no válido llevo la MEF a un 
            // lugar seguro, por ejemplo, la reinicio:
            InicializarMEF();
    }
}
char sumar_vida(void){
    return 1;
}