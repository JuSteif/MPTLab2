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
/* Funktionen:   Aufgabe A_2_1: LED-Lauflicht mit Einführung allgemeiner      */
/*                              Makros und Dienstfunktionen                   */
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
#include "MPT_LAB_2_1.h"

#ifdef ENABLE_A_2
#ifdef ENABLE_A_2_1


//------------------------------------------------------------------------------
//  Makro-/Konstantendefinitionen
//------------------------------------------------------------------------------

#define LED_DDR			DDRC
#define LED_PORT		PORTC
#define LED_DELAY		1

#define TASTER_DDR		DDRB
#define TASTER_PIN		PINB

#define PRELLEN_DELAY	1

//------------------------------------------------------------------------------
//  Public Funktionen
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Aufgabe A_2_1: LED-Lauflicht mit Einführung allgemeiner Makros und Dienstfunktionen
// A_2_1_1: Lauflicht L-R-L-... mit CLR_BIT, SET_BIT und Wait_x_ms
// A_2_1_2: Lauflicht L-R-L-... mit Port- und Pindefinitionen, sonst wie A_2_1_1
// A_2_1_3: Lauflicht L-R-L-... mit Tastertriggerung für Hin- und Rücklauf, sonst wie A_2_1_2
//------------------------------------------------------------------------------

//##############################################################################

// A_2_1_1: Lauflicht L-R-L-... mit CLR_BIT, SET_BIT und Wait_x_ms
void A_2_1_1(void)
{
	// Richtungsregister für LEDs auf Ausgang
	DDRC = 0b11111111;

	// Alle LEDs aus
	PORTC = 0b11111111;
	
	while (1)
	{
		int8_t i_b;
		
		// LEDs einschalten: 0 => 7
		for (i_b=0; i_b <= 7; i_b++)
		{
			CLR_BIT(PORTC,i_b);
			Wait_x_ms(1);
		}
		// LEDs ausschalten: 0 => 7
		for (i_b=0; i_b <= 7; i_b++)
		{
			SET_BIT(PORTC,i_b);
			Wait_x_ms(1);
		}
		// LEDs einschalten: 7 => 0
		for (i_b=7; i_b >= 0; i_b--)
		{
			CLR_BIT(PORTC,i_b);
			Wait_x_ms(1);
		}
		// LEDs ausschalten: 7 => 0
		for (i_b=7; i_b >= 0; i_b--)
		{
			SET_BIT(PORTC,i_b);
			Wait_x_ms(1);
		}
	}
}	

//##############################################################################

// A_2_1_2: Lauflicht L-R-L-... mit Port- und Pindefinitionen

void A_2_1_2(void)
{
	// Ihr Code hier...
	// Richtungsregister für LEDs auf Ausgang
	LED_DDR = 0b11111111;

	// Alle LEDs aus
	LED_PORT = 0b11111111;
	
	while (1)
	{
		int8_t i_b;
		
		// LEDs einschalten: 0 => 7
		for (i_b=0; i_b <= 7; i_b++)
		{
			CLR_BIT(LED_PORT,i_b);
			Wait_x_ms(LED_DELAY);
		}
		// LEDs ausschalten: 0 => 7
		for (i_b=0; i_b <= 7; i_b++)
		{
			SET_BIT(LED_PORT,i_b);
			Wait_x_ms(LED_DELAY);
		}
		// LEDs einschalten: 7 => 0
		for (i_b=7; i_b >= 0; i_b--)
		{
			CLR_BIT(LED_PORT,i_b);
			Wait_x_ms(LED_DELAY);
		}
		// LEDs ausschalten: 7 => 0
		for (i_b=7; i_b >= 0; i_b--)
		{
			SET_BIT(LED_PORT,i_b);
			Wait_x_ms(LED_DELAY);
		}
	}
}	

//##############################################################################


// A_2_1_3: Lauflicht L-R-L-... mit Tastertriggerung für Hin- und Rücklauf
void A_2_1_3(void)
{
	// Ihr Code hier...
	// Richtungsregister für LEDs auf Ausgang
	LED_DDR = 0b11111111;
	TASTER_DDR = 0x00;

	// Alle LEDs aus
	LED_PORT = 0b11111111;
	uint8_t state = 0;
	
	while (1)
	{
		int8_t i_b;
		
		if(BIT_IS_SET(TASTER_PIN, 7)){
			Wait_x_ms(PRELLEN_DELAY);
			
			// LEDs einschalten: 0 => 7
			for (i_b=0; i_b <= 7; i_b++)
			{
				CLR_BIT(LED_PORT,i_b);
				Wait_x_ms(LED_DELAY);
			}
			// LEDs ausschalten: 0 => 7
			for (i_b=0; i_b <= 7; i_b++)
			{
				SET_BIT(LED_PORT,i_b);
				Wait_x_ms(LED_DELAY);
			}
			// LEDs einschalten: 7 => 0
			for (i_b=7; i_b >= 0; i_b--)
			{
				CLR_BIT(LED_PORT,i_b);
				Wait_x_ms(LED_DELAY);
			}
			// LEDs ausschalten: 7 => 0
			for (i_b=7; i_b >= 0; i_b--)
			{
				SET_BIT(LED_PORT,i_b);
				Wait_x_ms(LED_DELAY);
			}
			
			while (!BIT_IS_CLR(TASTER_PIN, 7))
			{
				Wait_x_ms(PRELLEN_DELAY);
			}
		}
	}
}	

//##############################################################################

#endif /* ENABLE_A_2_1 */
#endif /* ENABLE_A_2 */


/*
 *  EoF
 */
