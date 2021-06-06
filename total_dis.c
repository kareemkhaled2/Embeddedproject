int total_dis(double lat1,double lon1){
		for (lat1!=55.999/*endpoint*/&&lon1!=55.999){
		
			double lat2=55.9/*from gps*/; double lon2=55.6/*from gps*/;
	
		double d= distance(double lat1, double lat2, double lon1, double lon2) ;
	
	
	double total_distance= total_distance+d;
		delay_ms(1000);
		lat1=	lat2;
			lon1=lon2;
	}
	return (int)total_distance;}