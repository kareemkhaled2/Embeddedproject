double read_alon(){
		char str[80];
		int i;
		char* token;
		double alon ,alat;
	for(i=0;i<=80;i++){
		str[i]=UART7_read();
		
	  if((strncmp(str,"$GPRMC",6)==0)&& str[17] == 'A' ){

	// Returns first token
     token = strtok(str, ",");
  
    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL) {
			
       // printf("%s\n", token);
        token = strtok(NULL, ",");
			if(i==2){ alon=atof(token);
			}
			if(i==4){ alat=atof(token);
			}}}} 
	return alon ;
	return alat ;}