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
/* Funktionen:   Aufgabe A_2_2: Inbetriebnahme der Seriellen Schnittstelle    */
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
#include "MPT_LAB_2_2.h"


#ifdef ENABLE_A_2
#ifdef ENABLE_A_2_2
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
// Aufgabe A_2_2: Inbetriebnahme der Seriellen Schnittstelle
// A_2_2_1: Kommunikation zu PC-Terminal "zu Fuß" realisieren
//------------------------------------------------------------------------------

//##############################################################################

// A_2_2_1: Kommunikation zu PC-Terminal "zu Fuß" realisieren
void A_2_2_1(void)
{
	// Richtungsregister für die LEDs auf Ausgang
	LED_DDR = 0b11111111;

	// Alle LEDs aus
	LED_PORT = 0xff;
	
	// Jetzt initialisieren wir die Usart-Schnittstelle:
	// Kein Paritäts-Bit
	UCSRC |= (0 << UPM1) | (0 << UPM0);
	// 1 Stop-Bit
	UCSRC |= (0 << USBS);
	// 8 Zeichen-Bits
	UCSRC |= (1 << UCSZ1) | (1 << UCSZ0);

	// Einstellen der Bitrate:
	// Tabelle (Datenblatt): 9600 Baud => 103 (0.2% Fehler)
	UBRRL = 103 % 256; // '%' liefert den Divisionsrest von 103 / 256 => 103
	UBRRH = 103 / 256; // '/' liefert den Quotienten    von 103 / 256 => 0
	
	// Freigabe der Sende-/Empfangs-Kanäle
	UCSRB |= (1 << RXEN) | (1 << TXEN);

	// Led 0 an zur Kontrolle, dass wir bis hier im Programm gekommen sind.
	CLR_BIT(LED_PORT,0);

	while (1)
	{
		// Warten, dass Senderegister frei ist
		while (BIT_IS_CLR(UCSRA,UDRE));
		// Jetzt ist das Senderegister frei, also
		// senden wir ein Zeichen einfach durch Schreiben
		// in das Senderegister UDR
		UDR = 'x';
	}
}

//##############################################################################

#endif /* ENABLE_A_2_2 */
#endif /* ENABLE_A_2 */

/*
 *  EoF
 */

