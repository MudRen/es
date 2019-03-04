//#pragma save_binary
// usage_d.c
// Keeps a running track of how much the MUD has been used in the
// last 24 hours. Make fancy displays if asked to do so.
// Mobydick, 6-6-93
// The idea is not mine, I saw something very similar to this on another
// MUD. But I can't remember where, or when... so I cannot track down
// the original author to give credit. Whoever it was, that author's
// work is gratefully acknowledged.
// This version of it was coded from scratch.

// Every CALL_TIME, the daemon collects the various information that
// it tracks and adds it to a running total. Every AVERAGING_NUM number of
// times, it computes the average usage and stores it in the history
// array. TRACK_NUM is the length of the history array. HEIGHT is the height
// of the resulting graph, in screen lines.

#define CALL_TIME 600
#define AVERAGING_NUM 12
#define TRACK_NUM 20
#define HEIGHT 14.0

// Currently tracking number of users, memory and CPU use, and number
// of objects loaded.

int obs, users, memory ;
float cpu ;
float *pastobs, *pastusers, *pastmem, *pastcpu ;
int counter, times ;

void update_history() ;

// At create time, start the call_out loop.

void create() {
	call_out ("sample", CALL_TIME) ;
	memory = 0 ;
	users = 0 ;
	cpu = 0.0 ;
	obs = 0 ;
	pastobs = allocate(TRACK_NUM) ;
	pastusers = allocate(TRACK_NUM) ;
	pastmem = allocate(TRACK_NUM) ;
	pastcpu = allocate(TRACK_NUM) ;
	counter = 0 ;
}

void sample() {

	mapping r ;

	memory = memory + memory_info() / 1000 ;
	users = users + sizeof(users()) ;
	obs = obs + sizeof(objects()) ;
//	r = rusage() ;
//	cpu = cpu + (r["usertime"] + r["stime"]) / uptime() / 10.0 ;
	times = times + 1 ;
	if (times == AVERAGING_NUM) {
		update_history() ;
		times = 0 ;
	}
	call_out ("sample", CALL_TIME) ;
}

void update_history() {
	pastmem[counter] = memory / AVERAGING_NUM.0 ;
	pastusers[counter] = users / AVERAGING_NUM.0 ;
	pastobs[counter] = obs / AVERAGING_NUM.0 ;
	pastcpu[counter] = cpu / AVERAGING_NUM.0 ;
	counter = counter + 1 ;
	if (counter==TRACK_NUM) counter=0 ;
	memory = 0 ;
        users = 0 ;
        cpu = 0.0 ;
        obs = 0 ;
}

void graph(string str) {

	mixed *data ;
	int i, j, elem, max, time, limit ;
	float scale, ylevel ;
	string line ;

	switch (str) {
		case "mem" : { data = pastmem ; break ; }
		case "obs" : { data = pastobs ; break ; }
		case "users" : { data = pastusers ; break ; }
		case "cpu" : { data = pastcpu ; break ; }
	}
// First, we need to find the maximum value, for scaling.
	max=0 ;
	for (i=0;i<TRACK_NUM;i++) {
		if (data[i]>max) max=data[i] ;
	}
	scale = max/(HEIGHT + 2.0) ;
	if (scale==0.0) scale = 1.0 ;
	write ("Graphing "+str+" over time.\n") ;
	write ("Each vertical bar represents ") ;
	time = CALL_TIME*AVERAGING_NUM ;
	if (time<61) {
		write (time+" seconds.\n") ;
	} else {
		if (time<3601) {
				write (time/60+" minutes.\n") ;
		} else {
			write (time/3600+" hours.\n") ;
		}
	}
	write ("Sampling every "+CALL_TIME+" seconds, "+AVERAGING_NUM+
		" samples per bar.\n") ;
	write ("Vertical scale is "+scale) ;
	switch (str) {
		case "mem" : { write (" Kbytes per line.\n") ; break ; }
		case "obs" : { write (" objects per line.\n") ; break ; }
		case "users" : { write (" users per line.\n") ; break ; }
		case "cpu" : { write (" percent CPU per line.\n") ; break ; }
	}
	limit = max/scale+1 ;
	for (i=limit;i>0;i--) {
		ylevel = scale*i ;
		line = "|" ;
		for (j=0;j<TRACK_NUM;j++) {
			elem = j+counter ;
			if (elem>=TRACK_NUM) elem = elem - TRACK_NUM ;
			if (data[elem]>=ylevel) {
				line = line + " * " ;
			} else {
				line = line + "   " ;
			}
		}
		write (sprintf("%10f %s",ylevel,line)+"\n") ; 
	}
	write ("------------------------------------------------------------------------\n") ;
	write ("           | 1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20\n") ;
}

void print_data(string str) {

	float *data ;
	int i, j ;

	switch (str) {
		case "mem" : { data = pastmem ; break ; }
		case "obs" : { data = pastobs ; break ; }
		case "cpu" : { data = pastcpu ; break ; }
		case "users" : { data = pastusers ; break ; }
	}
	for (i=0;i<TRACK_NUM;i++) {
		j = i + counter ;
		if (i==0) {
			write ("Current:          ") ;
		} else {
			if (i==1) { 
				write ("Last period:    ") ;
			} else {
				write (i+" periods ago: ") ;
				if (i<10) write (" ") ;
			}
		}
		write (data[i]+"\n") ;
	}
}
