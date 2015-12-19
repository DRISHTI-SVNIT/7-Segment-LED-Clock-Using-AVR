7-Segment-LED-Clock-Using-AVR
=============================

ABOUT THE PROJECT. 
==================
The project uses four seven segment displays and ATmega32 MCU to display time in HH:MM mode.
go through the code provided.

PRE REQUISITES
============== 
-avr programming 
-idea of timers & interrupts. 
-Multiplexing(important).
-idea of Seven Segment Display(common anode & common Cathode).

NOTE:-although with this code im able to display the time correctly. but the problem is that it is not a real time clock ie. once power is switched off the clock looses the time.to make it a real time clock ie. which always stays updated i need to interface a Real Time Clock IC (DS1307) with the MCU.it is still under process.