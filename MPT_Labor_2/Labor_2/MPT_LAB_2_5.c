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
// A_2_5_2_Client: HAUSAUFGABE: Abfrage der Taster => Senden uC mit Rücksetzen
// A_2_5_2_Server: HAUSAUFGABE: Empfangen von uC => Toggeln der LED zu Taster mit Rücksetzen
//------------------------------------------------------------------------------

//##############################################################################

// A_2_5_1_Client: Abfrage der Taster => Senden uC
void A_2_5_1_Client(void)
{
	// Richtungsregister für die LEDs auf Ausgang
	LED_DDR = 0b11111111;

	// Richtungsregister für Taster auf Eingang
	TASTER_DDR = 0b00000000;

	// Alle LEDs aus
	LED_PORT = 0b11111111;
	
	// Initialisierung der USART-Schnittstelle
	// 8 Zeichenbits, 1 Stopbit, 0 Paritätsbit, 9600 Baud
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
	
	// Richtungsregister für die LEDs auf Ausgang
	LED_DDR = 0b11111111;

	// Alle LEDs aus
	LED_PORT = 0b11111111;
	
	// Initialisierung der USART-Schnittstelle
	// 8 Zeichenbits, 1 Stopbit, 0 Paritätsbit, 9600 Baud
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
	// Richtungsregister für die LEDs auf Ausgang
	LED_DDR = 0b11111111;

	// Richtungsregister für Taster auf Eingang
	TASTER_DDR = 0b00000000;

	// Alle LEDs aus
	LED_PORT = 0b11111111;
	
	// Initialisierung der USART-Schnittstelle
	// 8 Zeichenbits, 1 Stopbit, 0 Paritätsbit, 9600 Baud
	UsartInit(8,1,0,9600);


	while (1)
	{
		while (BIT_IS_CLR(TASTER_PIN,6) && BIT_IS_CLR(TASTER_PIN,7) && BIT_IS_CLR(TASTER_PIN,5))
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
		if (BIT_IS_SET(TASTER_PIN,5))
		{
			UsartPutc('R');
			while (BIT_IS_SET(TASTER_PIN,5))
			{
			}
		}
		Wait_x_ms(50);
	}
}

//##############################################################################

void A_2_5_2_Server(void)
{
	uint8_t Cnt = 0;
	
	// Richtungsregister für die LEDs auf Ausgang
	LED_DDR = 0b11111111;

	// Alle LEDs aus
	LED_PORT = 0b11111111;
	
	// Initialisierung der USART-Schnittstelle
	// 8 Zeichenbits, 1 Stopbit, 0 Paritätsbit, 9600 Baud
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
		if (Data == 'R')
		{
			Cnt = 0;
			
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


