void leds(int distance){
		if (distance >=100){
			GPIO_PORTF_DATA_R=red_led;
		}
		
		else GPIO_PORTF_DATA_R&=~red_led;
	}