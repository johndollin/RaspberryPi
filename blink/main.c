/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: jdollin
 *
 * Created on 14 November 2015, 23:32
 */

#include <stdio.h>
#include <stdlib.h>
#include <bcm2835.h>
#define PIN0 RPI_GPIO_P1_11
#define ON HIGH
#define OFF LOW

/*
 * 
 */

int main(int argc, char** argv) {

	int i;

	printf ("Initialising BCM2835...\n");
	
	if (!bcm2835_init())
	{
        printf ("Unable to Initialise BCM2835\n");
		return 1;
	}
	
    // Set the pin to be an output
	printf ("Set the pin (%d) to be an output\n", PIN0);
    bcm2835_gpio_fsel(PIN0, BCM2835_GPIO_FSEL_OUTP);

    for (i=5; i>0; i--)
    {
        printf ("Switching LED ON...\n");
		bcm2835_gpio_write(PIN0, ON);

		bcm2835_delay(1000);
		
        printf ("Switching LED off...\n");
		bcm2835_gpio_write(PIN0, OFF);

		bcm2835_delay(1000);
    }

    bcm2835_close();

	return (EXIT_SUCCESS);
}