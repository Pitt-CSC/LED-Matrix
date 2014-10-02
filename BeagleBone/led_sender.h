/*
 * =============================================================================
 *
 *       Filename:  led.h
 *
 *    Description:  This header declares the Beaglebone interface
 *    			used to recive commands from programs using
 *    			the LED matrix
 *
 *        Version:  0.1
 *        Created:  10/02/14 17:15:36
 *       Revision:  none
 *
 *         Author:  Matthew Gruda (mg), matthewgruda@gmail.com
 *   Organization:  Pitt-CSC
 *
 * =============================================================================
 */

#ifndef		__LED_H
#define		__LED_H


/*  Will attemt to initalize the LED matrix.
 *  	Flags will control various options(none yet).
 *	If successful, it will return 0.
 *	Otherwise it will return an error code.
 */
extern int led_matrix_init(unsigned int flags);

/*
 * Will close all resources related to the LED matrix, and send a clear screen
 * 	to the matrix.
 * 	If sucessful, returns 0,
 * 	Else it will return an error code
 */
extern int led_matrix_close();

/*
 * Clears the LED matrix to the color RGB.
 * 	If sucessful, returns 0,
 * 	Else it will return an error code
 */
extern int led_matrix_clear(unsigned int RGB);

/*
 * If there are any changes waitng to written, this command will force the
 * 	LED matrix to update.
 * 	If sucessful or no changes, returns 0,
 * 	Else it will return an error code
 */
extern int led_matrix_update();

/*
 * Sets a LED to a color.  This may not be immedeiatly applyed.  Use
 * 	led_matrix_update() to force an update.
 * 	If sucessful, returns 0,
 * 	Else it will return an error code
 */
extern int led_matrix_set(unsigned int x, unsigned int y, unsigned int RGB);

#endif	/* 	__LED_H		*/

