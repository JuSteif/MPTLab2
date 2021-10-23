/*
 * MPT.c
 *
 * Created: 25.05.2012 18:12:01
 *  Author: holtv
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#include "MPT_LAB_MAIN.h"
#include "MPT_LAB_UTIL.h"

#include "Labor_2/MPT_LAB_2.h"


int main(void)
{

  //------------------------------------------------------------------------------
  // Aufgabe A_2_1: LED-Lauflicht mit Einführung allgemeiner Makros und Dienstfunktionen
  // A_2_1_1: Lauflicht L-R-L-... mit CLR_BIT, SET_BIT und Wait_x_ms
  // A_2_1_2: Lauflicht L-R-L-... mit Port- und Pindefinitionen, sonst wie A_2_1_1
  // A_2_1_3: Lauflicht L-R-L-... mit Tastertriggerung für Hin- und Rücklauf, sonst wie A_2_1_2
  //------------------------------------------------------------------------------
  //A_2_1_1();
  //A_2_1_2();
  //A_2_1_3();

  //------------------------------------------------------------------------------
  // Aufgabe A_2_2: Inbetriebnahme der Seriellen Schnittstelle
  // A_2_2_1: Kommunikation zu PC-Terminal "zu Fuß" realisieren (Ausgabe 'xxxxx...')
  //------------------------------------------------------------------------------
  //A_2_2_1();

  //------------------------------------------------------------------------------
  // Aufgabe A_2_3: Ausgabe auf Serieller Schnittstelle mit Dienstfunktionen realisieren
  // A_2_3_1: Kommunikation uC=>PC mit UsartInit und UsartPutc
  // A_2_3_2: Kommunikation uC=>PC mit UsartPuts, sonst wie A_2_3_1
  //------------------------------------------------------------------------------
  //A_2_3_1();
  //A_2_3_2();

  //------------------------------------------------------------------------------
  // Aufgabe A_2_4: Eingabe von Serieller Schnittstelle mit Dienstfunktionen realisieren
  // A_2_4_1: Echo Eingabe=>Ausgabe
  // A_2_4_2: LED-Ansteuerung vom Terminal über Ziffertasten und switch
  // A_2_4_3: HAUSAUFGABE: LED-Ansteuerung vom Terminal über Ziffertasten "intelligente" Auswertung, sonst wie A_2_4_2
  //------------------------------------------------------------------------------
  //A_2_4_1();
  A_2_4_2();
  //A_2_4_3();
  
  //------------------------------------------------------------------------------
  // Aufgabe A_2_5: Serielle Kommunikation uC=>uC
  // A_2_5_1_Client: Abfrage der Taster => Senden uC
  // A_2_5_1_Server: Empfangen von uC => Toggeln der LED zu Taster
  // A_2_5_2_Client: HAUSAUFGABE: Abfrage der Taster => Senden uC mit Rücksetzen
  // A_2_5_2_Server: HAUSAUFGABE: Empfangen von uC => Toggeln der LED zu Taster mit Rücksetzen
  //------------------------------------------------------------------------------
  //A_2_5_1_Client(); 
  //A_2_5_1_Server(); 
  //A_2_5_2_Client();
  //A_2_5_2_Server();

  while(1)
  {
      //TODO:: Please write your application code 
  }
}

