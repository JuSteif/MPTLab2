/******************************************************************************/
/*                                                                            */
/*              Ostfalia Hochschule für angewandte Wissenschaften             */
/*                        Fakultät für Fahrzeugtechnik                        */
/*           Institut für Fahrzeuginformatik und Fahrzeugelektronik           */
/*                             Fahrzeuginformatik                             */
/*                                                                            */
/* Paket:        MPT_LAB                                                      */
/*                                                                            */
/* Modul:        MPT_LAB_2                                                    */
/*                                                                            */
/* Beschreibung: Aufgaben 2.MPT-Labor                                         */
/*                                                                            */
/* Funktionen:   Aufgabe A_2_3: Ausgabe auf Serieller Schnittstelle mit       */
/*                              Dienstfunktionen realisieren                  */
/*                                                                            */
/* Version:      1.0 / 120716 / V. v. Holt                                    */
/*                                                                            */
/******************************************************************************/

//------------------------------------------------------------------------------
//  Headerdateien
//------------------------------------------------------------------------------
// Allgemeine Headerdateien
#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>

// Eigene Headerdateien
#include "MPT_LAB_MAIN.h"
#include "MPT_LAB_UTIL.h"
#include "MPT_LAB_2_3.h"


#ifdef ENABLE_A_2
#ifdef ENABLE_A_2_3
//------------------------------------------------------------------------------
//  Makro-/Konstantendefinitionen
//------------------------------------------------------------------------------
#define LED_DDR     DDRC
#define LED_PORT    PORTC
#define LED_DELAY   50
#define TASTER_DDR  DDRB
#define TASTER_PIN  PINB


//------------------------------------------------------------------------------
//  Private Variablen
//------------------------------------------------------------------------------
	
	
//------------------------------------------------------------------------------
//  Interrupt Service Routinen
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
//  Private Funktionen
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
//  Public Funktionen
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Aufgabe A_2_3: Ausgabe auf Serieller Schnittstelle mit Dienstfunktionen realisieren
// A_2_3_1: Kommunikation uC=>PC mit UsartInit und UsartPutc
// A_2_3_2: Kommunikation uC=>PC mit UsartPuts
//------------------------------------------------------------------------------

//##############################################################################

// A_2_3_1: Kommunikation uC=>PC mit UsartInit und UsartPutc
void A_2_3_1(void)
{
	// Initialisierung
	// IHR_CODE_HIER ...
	LED_DDR = 0xff;
	LED_PORT = 0xff;
	
	UsartInit(8, 0, 1, 9600);
	
	CLR_BIT(LED_PORT, 0);

	while (1)
	{
		// Jetzt geben wir etwas sinnvolles aus!
		// IHR_CODE_HIER ...
		
		UsartPutc('M');
		UsartPutc('P');
		UsartPutc('T');
		UsartPutc(' ');
		UsartPutc('i');
		UsartPutc('s');
		UsartPutc('t');
		UsartPutc(' ');
		UsartPutc('t');
		UsartPutc('o');
		UsartPutc('l');
		UsartPutc('l');
		UsartPutc('!');
	}		
}	

//##############################################################################

// A_2_3_2: Kommunikation uC=>PC mit UsartPuts
void A_2_3_2(void)
{
	// Initialisierung
	// IHR_CODE_HIER ...
	LED_DDR = 0xff;
	LED_PORT = 0xff;
	
	UsartInit(8, 0, 1, 9600);
	
	CLR_BIT(LED_PORT, 0);

	while (1)
	{
		// Jetzt geben wir etwas sinnvolles aus!
		// IHR_CODE_HIER ...
		
		UsartPuts("MPT macht Spass!\n\r");
	}		
}	

//##############################################################################

#endif /* ENABLE_A_2_3 */
#endif /* ENABLE_A_2 */

/*
 * EoF
 */
