/******************************************************************************/
/*                                                                            */
/*              Ostfalia Hochschule f�r angewandte Wissenschaften             */
/*                        Fakult�t f�r Fahrzeugtechnik                        */
/*           Institut f�r Fahrzeuginformatik und Fahrzeugelektronik           */
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
// A_2_4_2: LED-Ansteuerung vom Terminal �ber Ziffertasten und switch
// A_2_4_3: LED-Ansteuerung vom Terminal �ber Ziffertasten "intelligente" Auswertung
//------------------------------------------------------------------------------

//##############################################################################

// A_2_4_1: Echo Eingabe=>Ausgabe
void A_2_4_1(void)
{
  // Richtungsregister f�r die LEDs auf Ausgang
  LED_DDR = 0b11111111;

  // Alle LEDs aus
  LED_PORT = 0b11111111;
	
  // Initialisierung der USART-Schnittstelle
  // 8 Zeichenbits, 1 Stopbit, 0 Parit�tsbit, 9600 Baud
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

// A_2_4_2: LED-Ansteuerung vom Terminal �ber Ziffertasten und switch
void A_2_4_2(void)
{
	// IHR_CODE_HIER ...
	LED_DDR = 0xff;
	LED_PORT = 0xff;
  
	UsartInit(8, 0, 1, 9600);
  
	while(1){
		uint8_t data = UsartGetc();
		
		switch (data)
		{
		case '0':
			TGL_BIT(LED_PORT, 0);
			break;
		case '1':
			TGL_BIT(LED_PORT, 1);
			break;
		case '2':
			TGL_BIT(LED_PORT, 2);
			break;
		case '3':
			TGL_BIT(LED_PORT, 3);
			break;
		case '4':
			TGL_BIT(LED_PORT, 4);
			break;
		case '5':
			TGL_BIT(LED_PORT, 5);
			break;
		case '6':
			TGL_BIT(LED_PORT, 6);
			break;
		case '7':
			TGL_BIT(LED_PORT, 7);
			break;
		default:
			UsartPuts("Keine gueltige Eingabe!");
		}
	}
}	


//##############################################################################

// A_2_4_3: HAUSAUFGABE: LED-Ansteuerung vom Terminal �ber Ziffertasten "intelligente" Auswertung
void A_2_4_3(void)
{
	// IHR_CODE_HIER ...
	// LED�s initalisieren, alle Ausschalten
	LED_DDR = 0xff;
	LED_PORT = 0xff;
  
	//USART initialisieren und Eingabeaufforderung an Terminal schicken
	UsartInit(8, 0, 1, 9600);
	UsartPuts("Eingabe:");
	
	while(1){
		// Puffervariable f�r empfangene Daten der USART-Schnittstelle, Auf empfangene Daten warten
		uint8_t data;
		data = UsartGetc();
		
		// Routine f�r g�ltige Eingabe auf dem Terminal
		if(data >= '0' && data <= '7'){
			// ASCII-Zeichen in entsprechende Zahl konvertieren(Offset '0' oder 0x30 subtrahieren) 
			data -= '0';
			
			// Entsprechendes Bit im LED_PORT register invertieren, um die zugeh�rige LED ein- und auszuschalten
			TGL_BIT(LED_PORT, data);
		}
		// Routine f�r ung�ltige Eingabe auf dem Terminal
		else{
			// Fehlermeldung an das Terminal schicken
			UsartPuts("Keine gueltige Eingabe!");
		}
	}
}

//##############################################################################

#endif /* ENABLE_A_2_4 */
#endif /* ENABLE_A_2 */

/*
 *  EoF
 */
