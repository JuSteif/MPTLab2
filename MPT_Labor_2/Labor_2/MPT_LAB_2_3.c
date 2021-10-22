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

	while (1)
	{
		// Jetzt geben wir etwas sinnvolles aus!
		// IHR_CODE_HIER ...
	}		
}	

//##############################################################################

// A_2_3_2: Kommunikation uC=>PC mit UsartPuts
void A_2_3_2(void)
{
	// Initialisierung
	// IHR_CODE_HIER ...

	while (1)
	{
		// Jetzt geben wir etwas sinnvolles aus!
		// IHR_CODE_HIER ...
	}		
}	

//##############################################################################

#endif /* ENABLE_A_2_3 */
#endif /* ENABLE_A_2 */

/*
 * EoF
 */
