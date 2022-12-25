/*
 * Copyright (c) 2022 Gerhard Schiller
 * SPDX-License-Identifier: GPL-3.0-or-later
 * https://www.gnu.org/licenses/gpl-3.0.txt
 */

#include <stdio.h>
#include "pico/stdlib.h"
// "hardware/clocks.h" gets included by "sn74165.pio.h"
#include "sn74165.pio.h"

int main()
{
	int x;

	stdio_init_all();
	printf("SN74xx165 PIO-Interface for %d device(s) with %.2f kHz clock.\n",
		   sn74165_NUM_DEVICES, (float)(sn74165::SHIFT_CLK) / 1000.0) ;

	sn74165::shiftreg_init();

	uint32_t data;
	uint32_t data2;
	bool	inpChanged;

	int loop = 0;
	while (true)
    {
		data = sn74165::shiftreg_get(&inpChanged);
		if(inpChanged){
			loop++;
			printf("\n%4d 0x%08X\t\t", loop, data);
			printf("%08b %08b %08b %08b\n",
				   (data >> 24) & 0xFF,
				   (data >> 16) & 0xFF,
				   (data >> 8) & 0xFF,
				   data & 0xFF);
		}
		else
			printf(".");

		sleep_ms(200);

	}
}


