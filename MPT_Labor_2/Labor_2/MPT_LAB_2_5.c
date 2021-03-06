/******************************************************************************/
/*                                                                            */
/*              Ostfalia Hochschule f?r angewandte Wissenschaften             */
/*                        Fakult?t f?r Fahrzeugtechnik                        */
/*           Institut f?r Fahrzeuginformatik und Fahrzeugelektronik           */
/*                             Fahrzeuginformatik                             */
/*                                                                            */
/* Paket:        MPT_LAB                                                      */
/*                                                                            */
/* Modul:        MPT_LAB_2                                                    */
/*                                                                            */
/* Beschreibung: Aufgaben 2.MPT-Labor                                         */
/*                                                                            */
/* Funktionen:   Aufgabe A_2_5: Serielle Kommunikation uC=>uC                 */
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
#include "MPT_LAB_2_5.h"


#ifdef ENABLE_A_2
#ifdef ENABLE_A_2_5
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
// Aufgabe A_2_5: Serielle Kommunikation uC=>uC
// A_2_5_1_Client: Abfrage der Taster => Senden uC
// A_2_5_1_Server: Empfangen von uC => Toggeln der LED zu Taster
// A_2_5_2_Client: HAUSAUFGABE: Abfrage der Taster => Senden uC mit R?cksetzen
// A_2_5_2_Server: HAUSAUFGABE: Empfangen von uC => Toggeln der LED zu Taster mit R?cksetzen
//------------------------------------------------------------------------------

//##############################################################################

// A_2_5_1_Client: Abfrage der Taster => Senden uC
void A_2_5_1_Client(void)
{
	// Richtungsregister f?r die LEDs auf Ausgang
	LED_DDR = 0b11111111;

	// Richtungsregister f?r Taster auf Eingang
	TASTER_DDR = 0b00000000;

	// Alle LEDs aus
	LED_PORT = 0b11111111;
	
	// Initialisierung der USART-Schnittstelle
	// 8 Zeichenbits, 1 Stopbit, 0 Parit?tsbit, 9600 Baud
	UsartInit(8,1,0,9600);


	while (1)
	{
		while (BIT_IS_CLR(TASTER_PIN,6) && BIT_IS_CLR(TASTER_PIN,7))
		{
		}
		Wait_x_ms(50);

		if (BIT_IS_SET(TASTER_PIN,6))
		{
			UsartPutc('+');
			while (BIT_IS_SET(TASTER_PIN,6))
			{
			}
		}
		if (BIT_IS_SET(TASTER_PIN,7))
		{
			UsartPutc('-');
			while (BIT_IS_SET(TASTER_PIN,7))
			{
			}
		}
		Wait_x_ms(50);
	}
}

//##############################################################################

// A_2_5_1_Server: Empfangen von uC => Toggeln der LED zu Taster
void A_2_5_1_Server(void)
{
	uint8_t Cnt = 0;
	
	// Richtungsregister f?r die LEDs auf Ausgang
	LED_DDR = 0b11111111;

	// Alle LEDs aus
	LED_PORT = 0b11111111;
	
	// Initialisierung der USART-Schnittstelle
	// 8 Zeichenbits, 1 Stopbit, 0 Parit?tsbit, 9600 Baud
	UsartInit(8,1,0,9600);

	while (1)
	{
		uint8_t Data;

		// Zeichen von USART (Terminal/Tastatur) einlesen
		Data = UsartGetc();
		if (Data == '+')
		{
			++Cnt;
			
			LED_PORT = ~Cnt;
		}
		else
		if (Data == '-')
		{
			--Cnt;
			
			LED_PORT = ~Cnt;
		}
	}
}

//##############################################################################

void A_2_5_2_Client(void)
{
	// Richtungsregister f?r die LEDs auf Ausgang
	LED_DDR = 0b11111111;

	// Richtungsregister f?r Taster auf Eingang
	TASTER_DDR = 0b00000000;

	// Alle LEDs aus
	LED_PORT = 0b11111111;
	
	// Initialisierung der USART-Schnittstelle
	// 8 Zeichenbits, 1 Stopbit, 0 Parit?tsbit, 9600 Baud
	UsartInit(8,1,0,9600);


	while (1)
	{
		// Staendige Abfrage des 5(RESET), 6(+) und 7(-) Tasters
		while (BIT_IS_CLR(TASTER_PIN,6) && BIT_IS_CLR(TASTER_PIN,7) && BIT_IS_CLR(TASTER_PIN,5))
		{
		}
		//Prellen vermeiden
		Wait_x_ms(50);

		// Routine f?r Taste 6
		if (BIT_IS_SET(TASTER_PIN,6))
		{
			//Befehl zum Inkrementieren an Server schicken, codiert durch '+'(0x2B)
			UsartPutc('+');
			//Warten bis Taste 6 losgelassen wurde, bevor n?chste Befehle entgegengenommen werden
			while (BIT_IS_SET(TASTER_PIN,6))
			{
			}
		}
		// Routine f?r Taste 7
		if (BIT_IS_SET(TASTER_PIN,7))
		{
			//Befehl zum Dekrementieren an Server schicken, codiert durch '-'(0x2D)
			UsartPutc('-');
			//Warten bis Taste 7 losgelassen wurde, bevor n?chste Befehle entgegengenommen werden
			while (BIT_IS_SET(TASTER_PIN,7))
			{
			}
		}
		// Routine f?r Taste 5
		if (BIT_IS_SET(TASTER_PIN,5))
		{
			//Befehl zum RESET an Server schicken, codiert durch 'R'(0x52)
			UsartPutc('R');
			//Warten bis Taste 5 losgelassen wurde, bevor n?chste Befehle entgegengenommen werden
			while (BIT_IS_SET(TASTER_PIN,5))
			{
			}
		}
		// Prellen beim loslassen einer Taste vermeiden
		Wait_x_ms(50);
	}
}

//##############################################################################

void A_2_5_2_Server(void)
{
	// Countervariable anlegen
	uint8_t Cnt = 0;
	
	// Richtungsregister f?r die LEDs auf Ausgang
	LED_DDR = 0b11111111;

	// Alle LEDs aus
	LED_PORT = 0b11111111;
	
	// Initialisierung der USART-Schnittstelle
	// 8 Zeichenbits, 1 Stopbit, 0 Parit?tsbit, 9600 Baud
	UsartInit(8,1,0,9600);

	while (1)
	{
		// Puffervariable f?r empfangene Daten der USART-Schnittstelle 
		uint8_t Data;

		// Zeichen von USART einlesen
		Data = UsartGetc();
		
		// Routine f?r Inkrementieren
		if (Data == '+')
		{
			// Overflow verhindern(256 nicht mehr zul?ssig)
			if(Cnt < 255){
				// Inkrementieren des Z?hlers
				++Cnt;
			}
			
			// Aktualisierten Counter an LED?s weitergeben
			LED_PORT = ~Cnt;
		}
		// Routine f?r Dekrementieren
		if (Data == '-')
		{
			// Overflow verhindern(-1 nicht mehr zul?ssig)
			if(Cnt > 0){
				// Dekrementieren des Z?hlers
				--Cnt;
			}
			
			// Aktualisierten Counter an LED?s weitergeben
			LED_PORT = ~Cnt;
		}
		// Routine f?r RESET
		if (Data == 'R')
		{
			// Z?hler auf 0 setzen
			Cnt = 0;
			
			// Aktualisierten Counter an LED?s weitergeben
			LED_PORT = ~Cnt;
		}
	}
}

//##############################################################################

#endif /* ENABLE_A_2_5 */
#endif /* ENABLE_A_2 */

/*
 *  EoF
 */


