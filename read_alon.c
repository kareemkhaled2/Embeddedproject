	double read_alon(){
		char str[80];
		int i;
		char* token;
		double alon ;
	for(i=0;i<=80;i++){
		str[i]=RRAD();
		
	  if((strncmp(str,"$GPRMC",6)==0)&& str[17] == 'A' ){

	// Returns first token
     token = strtok(str, ",");
  
    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL) {
			
       // printf("%s\n", token);
        token = strtok(NULL, ",");
			if(i==4){ alon=atof(token);
			}
	
	
	}
	
	}
} return alon;
	
	}