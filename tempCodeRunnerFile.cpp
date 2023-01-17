if(rem[2]==0){x=min(n/2,rem[0]);y=n/2-x;}
		else if(rem[0]==0){z=min(n/2,rem[2]);y=n/2-z;}
		else{x=rem[0];z=rem[2];y=n/2-x-z;}
		print(1,n,x,y,z,s);