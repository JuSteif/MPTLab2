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
/* Funktionen:   Aufgabe A_2_4: Eingabe von Serieller Schnittstelle mit       */
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
#include "MPT_LAB_2_4.h"


#ifdef ENABLE_A_2
#ifdef ENABLE_A_2_4
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
// Aufgabe A_2_4: Eingabe von Serieller Schnittstelle mit Dienstfunktionen realisieren
// A_2_4_1: Echo Eingabe=>Ausgabe
// A_2_4_2: LED-Ansteuerung vom Terminal über Ziffertasten und switch
// A_2_4_3: LED-Ansteuerung vom Terminal über Ziffertasten "intelligente" Auswertung
//------------------------------------------------------------------------------

//##############################################################################

// A_2_4_1: Echo Eingabe=>Ausgabe
void A_2_4_1(void)
{
  // Richtungsregister für die LEDs auf Ausgang
  LED_DDR = 0b11111111;

  // Alle LEDs aus
  LED_PORT = 0b11111111;
	
  // Initialisierung der USART-Schnittstelle
  // 8 Zeichenbits, 1 Stopbit, 0 Paritätsbit, 9600 Baud
  UsartInit(8,1,0,9600);
	
  // Led 0 an zur Kontrolle, dass wir bis hier im Programm gekommen sind.
  CLR_BIT(LED_PORT,0);

  // Ausgabe einer Meldung zur Aufgabeeinforderung
  UsartPuts("\n\r");
  UsartPuts("MPT-Terminal\n\r");
  UsartPuts("Bitte geben Sie etwas ein:");
	
	while (1)
	{
		uint8_t Data;
		// Zeichen von USART (Terminal/Tastatur) einlesen		
		Data = UsartGetc();
		// Zeichen als Echo auf USART (Terminal/Monitor) ausgeben
		UsartPutc(Data);
	}		
}	

//##############################################################################

// A_2_4_2: LED-Ansteuerung vom Terminal über Ziffertasten und switch
void A_2_4_2(void)
{
  // IHR_CODE_HIER ...
}	


//##############################################################################

// A_2_4_3: HAUSAUFGABE: LED-Ansteuerung vom Terminal über Ziffertasten "intelligente" Auswertung
void A_2_4_3(void)
{
	// IHR_CODE_HIER ...
}

//##############################################################################

#endif /* ENABLE_A_2_4 */
#endif /* ENABLE_A_2 */

/*
 *  EoF
 */
