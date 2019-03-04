//#pragma save_binary
// Weather daemon
// Originally coded by Megadeath@TMI-2
// Overhauled by Mobydick@TMI-2

#include <mudlib.h>
#include <weather_d.h>
#include <daemons.h>

inherit DAEMON ;

// A list of all objects which get the weather change messages. All outdoor
// rooms are placed on this list, but other objects such as monsters can
// be placed on it (so you can code vampires and so on.)

object *notifications ;

// These variables store the current game time. The length of game days,
// months, and years is all controlled by defines in weather_d.h.

int current_day, current_month, current_year ;

// This variable stores the data on the day phases.

mapping *day_phases ;
int num_phases ;
int current_phase ;

// And these on the weather states.

mapping *weather_states ;
int num_states ;
int current_state ;

// And these on the months.

mapping *months ;
int num_months ;

// And _these_ on the moon phases :)

mapping *moon_phases ;
int num_moon_phases ;
int moon_phase_days ;
int current_moon_phase ;


// This function reads in the data on the daytime phases.

void read_day_phases() {

	int i, data, size ;
	string str, estr, cstr ;
	string *datafile ;
	int which_line ;
	mapping new_phase ;

// Which_line keeps track of where in the file format we are.
	which_line = 0 ;
	datafile = explode(read_file(DAY_PHASE_FILE),"\n") ;
	size = sizeof(datafile) ;
	day_phases = allocate(NUM_DAY_PHASES) ;
	num_phases = -1 ;      // sorry.... this is silly but easiest.
// Loop through each line of the file and try to parse it appropriately.
	for (i=0;i<size;i++) {
// Make sure that this line is a proper data line: if not, skip it.
	    if (sscanf(datafile[i],"%d %s @@ %s",data,estr,cstr)==3) {
		if (which_line) {
// We're looking at the second of the two lines in this case.
			day_phases[num_phases]["change_msg"] = estr ;
			day_phases[num_phases]["c_change_msg"] = cstr ;
			day_phases[num_phases]["daylight"] = data ;
		} else {
// In this case, the first of the two lines.
			num_phases = num_phases + 1 ;
			day_phases[num_phases] = allocate_mapping(6) ;
			day_phases[num_phases]["length"] = data ;
			day_phases[num_phases]["look_msg"] = estr ;
			day_phases[num_phases]["c_look_msg"] = cstr ;
		}
		which_line = !which_line ;
	   }
	}
	if (which_line) {
		shout ("Incomplete last day phase.\n") ;
	}
	num_phases = NUM_DAY_PHASES ;
	return ; 
}

// This function reads in the weather data.

void read_weather() {

	int i, j, data1, data2, size ;
	string *changes ;
        string *datafile ;
        int which_line ;

// Which line keeps track of where we are in the file format.
	which_line = 0 ;
        datafile = explode(read_file(WEATHER_FILE),"\n") ;
        size = sizeof(datafile) ;
	weather_states = allocate(NUM_WEATHER) ;
	changes = allocate(NUM_WEATHER) ;
	num_states = -1 ;   // hack :(
// Loop through each line of the file, and parse it.
	for (i=0;i<size;i++) {
	    switch(which_line) {
// How we parse it depends on what line we are expecting.
		case 0 : {
		    if (sscanf(datafile[i],"%d %d",data1,data2)==2) {
				num_states = num_states+1 ;
				weather_states[num_states]=allocate_mapping(6) ;
				weather_states[num_states]["length"] = data1 ;
				weather_states[num_states]["inclement"] = data2 ;
				which_line = 1 ;
		    }
		    break ;
 			}
		case 1 : {
		    changes = explode(datafile[i]," ") ;
		    weather_states[num_states]["changes"] = 
					allocate(NUM_WEATHER) ;
		    for (j=0;j<sizeof(changes);j++) {
				sscanf(changes[j],"%d",weather_states[num_states]
					["changes"][j]) ;
		    }
		    which_line=2 ;
		    break ;
			}
		case 2 : {
		    weather_states[num_states]["worse_msg"] = datafile[i] ;
		    which_line=3;
		    break ;
			}
		case 3 : {
		    weather_states[num_states]["c_worse_msg"] = datafile[i] ;
		    which_line=4;
		    break ;
			}
		case 4 : {
			weather_states[num_states]["better_msg"] = datafile[i] ;
			which_line=5 ;
			break ;
			}
		case 5 : {
			weather_states[num_states]["c_better_msg"] = datafile[i] ;
			which_line=6 ;
			break ;
			}
		case 6 : {
			weather_states[num_states]["look_msg"] = datafile[i] ;
			which_line=7;
			break ;
			}
		case 7 : {
			weather_states[num_states]["c_look_msg"] = datafile[i] ;
			which_line=0 ;
			break ;
			}
	    }
        }
	num_states = NUM_WEATHER ;
	return ;
}

// This function reads in the months and their names.

void read_months() {

	int i, ding ;
	string str, c_str;
	string *datafile ;

	datafile = explode(read_file(MONTH_FILE),"\n") ;
	months = allocate(NUM_MONTHS) ;
	num_months = -1 ;    // same hack as always.
	for (i=0;i<sizeof(datafile);i++) {
	    if (sscanf(datafile[i],"%s %s %d", str, c_str, ding)==3) {
		num_months = num_months + 1 ;
		months[num_months]=allocate_mapping(2);
		months[num_months]["length"] = ding;
		months[num_months]["name"] = str;
		months[num_months]["c_name"] = c_str;
	    }
	}
	num_months = NUM_MONTHS ;
	return ;
}

// This function reads in the data on the moon phases.

void read_moon() {

        int i, ding ;
        string estr, cstr;
        string *datafile ;

        datafile = explode(read_file(MOON_FILE),"\n") ;
        moon_phases = allocate(NUM_MOON_PHASES) ;
        num_moon_phases = -1 ;    // same hack as always.
        for (i=0;i<sizeof(datafile);i++) {
	    if (sscanf(datafile[i],"%d %s @@ %s",ding,estr,cstr)==3) {
                num_moon_phases = num_moon_phases + 1 ;
                moon_phases[num_moon_phases]=allocate_mapping(3) ;
                moon_phases[num_moon_phases]["length"] = ding ;
                moon_phases[num_moon_phases]["look_msg"] = estr;
                moon_phases[num_moon_phases]["c_look_msg"] = cstr;
            }
        }
	num_moon_phases = NUM_MOON_PHASES ;
}

// This function is called at the end of each day to advance the calendar
// and the moon phase. You can do other things as well.

void do_day_end() {
	current_day=current_day+1 ;
	if (current_day>months[current_month]["length"]) {
		current_day=1 ;
		current_month = current_month+1 ;
		if (current_month==num_months) {
			current_month=0 ;
			current_year = current_year + 1 ;
		}
	}
	moon_phase_days = moon_phase_days + 1 ;
	if (moon_phase_days==moon_phases[current_moon_phase]["length"]) {
		moon_phase_days=0 ;
		current_moon_phase = current_moon_phase + 1 ;
		if (current_moon_phase==num_moon_phases) {
			current_moon_phase = 0 ;
		}
	}
}

// This function changes us from one state of day to the next. It call_outs
// to itself recursively so there's always one version in the call_out
// queue.

void change_phase()
{
	int i;

	notifications -= ({ 0 });
	i = sizeof(notifications);
	while(i--)
		tell_room(notifications[i], 
			day_phases[current_phase]["c_change_msg"]+"\n" 
		);
	current_phase = current_phase + 1;
	if (current_phase==num_phases) {
		current_phase=0 ;
		do_day_end() ;
	}
	call_out("change_phase",day_phases[current_phase]["length"]) ;
}

int filter_victim(object obj)
{
//	if( (int)obj->query("alignment") > 0 ) return 0;
	if( !environment(obj) || !environment(obj)->query("outside") ) return 0;
	if( wizardp(obj) ) return 0;
	return 1;
}

int sort_victim(object ob1, object ob2)
{
	if( (int)ob1->query("alignment") > (int)ob2->query("alignment") )
		return 1;
	else if( (int)ob1->query("alignment") < (int)ob2->query("alignment") )
		return -1;
	else return 0;
}

varargs void invoke_thunder(string who)
{
	int i;
	object *usr, victim, obj;

	usr = filter_array( users(), "filter_victim", this_object() );
	if( sizeof(usr) ) usr = sort_array( usr, "sort_victim", this_object() );
	else return;
	notifications -= ({ 0 });
	if( who && victim= find_living(who) ) {
		if( (i = member_array(victim, usr))!=-1 ) {
			usr[i]= usr[0];
			usr[0] = victim;
		} else usr = ({ victim }) + usr;
	}
	if( (int)usr[0]->query("alignment") >= -400 ) return;
	for( i=0; i<sizeof(usr); i++ )
		if( !present(usr[0], environment(usr[i])) )
			tell_object( usr[i], 
				"\n�㿴�������һ����⣬����������¡��һ�����������������\n");

	// The possibility of being hit: align -400: 30%, align -5000: 100%, linear.
	if( random(100) < 30 - 70 * ((int)usr[0]->query("alignment") + 400) / 4600 ) {
		if( environment(usr[0])->query("outside") ) {
			tell_room( environment(usr[0]), 
				"\n�㿴�������һ����⣬����������¡��һ���׵�Ю���֮���������������\n"
				"\n����ǰ��" + usr[0]->query("c_name") + "ͷ�ϣ�\n",
				usr[0] );
			tell_object( usr[0], 
				"\nͻȻ��һ����������������������ͷ���������ǰһ�������ð��Ȼ����\n"
				"\nȫ���ʹ��һ�ɽ�ζ ....\n");

			if( (obj = usr[0]->query_attacker()) && obj->query("alignment") < 0 )
				usr[0]->receive_special_damage( "electric", 70 );
			else
				usr[0]->receive_special_damage( "electric", 100 );
			for( i=0; i<sizeof(usr); i++ )
				tell_object( usr[i],
					"\n�����һ������˵��: ���в��壬������Ǵ�����ճʹ�" + 
					STATS_D->alignment_string(usr[0]->query("alignment"))+"֮ͽ: " 
					+ usr[0]->query("c_name") + "\n         һ�����������˾��� ....��\n\n");
		}
	} else {
	/* give more chance to aviod the thunder.     -EGA */
		if( environment(usr[0])->query("outside") ) {
			tell_room( environment(usr[0]), 
				"\n�㿴�������һ����⣬����������¡��һ���׵�Ю���֮���������������\n"
				"\n����ǰ��" + usr[0]->query("c_name") + "���ԣ�\n",
				usr[0] );
			tell_object( usr[0], 
				"\nͻȻ��һ�������������������������ԣ��޴������������л��첻�ѣ���\n"
				"\n�˺�һ���Ӳ�����ɢȥ...\n");

			for( i=0; i<sizeof(usr); i++ )
				tell_object( usr[i], 
					"\n�����һ������˵��: ���в��壬������Ǵ�����վ�ʾ" + 
					STATS_D->alignment_string(usr[0]->query("alignment"))+"֮ͽ: " 
					+ usr[0]->query("c_name") + "\n         �������ڸģ����ձر���\n\n");

		}	
	}
}

varargs void call_thunder(string who)
{
	int i;
	object *usr;

	usr = filter_array( users(), "filter_victim", this_object() );
	if( !sizeof(usr) ) return;
	for( i=0; i<sizeof(usr); i++ ) {
		message( "weather", 
			"\n�㿴������е������������һ�������Ƶ����� .....\n\n"
			,usr[i] );
		if ( (string)usr[i]->query("race") == "beholder" ) {
			tell_object(usr[i],"�� !! �ִ����� !! �Ͽ��Ҹ��ط���㡡\n");
			tell_room(environment(usr[i]),sprintf("%s�����������ŵ�ȫ��ת����ɫ��\n",usr[i]->query("c_name")),usr[i]);
		}
		else if ( (string)usr[i]->query("race") == "shapeshifter" ) {
			usr[i]->drop_eq();
			tell_room(environment(usr[i]),sprintf("%s����һ���������ϵ�װ�����������ĵ���һ�ء�\n",usr[i]->query("c_name")),usr[i]);
		}
	}
	call_out( "invoke_thunder", 10, who );
}

// This function changes the weather. Based on the current weather
// state, it picks a new weather state and call_outs itself, so that there
// is always one version of the function in the call_out queue. If the new
// state is the same as the old one, then nothing else is done, otherwise
// we notify each object of the new state.

void change_weather()
{
	int i, j, new_state ;

	notifications -= ({ 0 });
	j = random(100) ;
	for (i=0;i<sizeof(weather_states[current_state]["changes"]);i++) {
	    if (j<weather_states[current_state]["changes"][i]) {
			new_state = i ;
			j=200 ;		// This way we don't select again.
	    } else {
			j = j - weather_states[current_state]["changes"][i] ;
	    }
	}
	call_out("change_weather", weather_states[new_state]["length"]);
	if (new_state==current_state) return;
	i=sizeof(notifications);
	while (i--) {
	    if (new_state<current_state) {
			tell_room(notifications[i], 
				weather_states[new_state]["c_better_msg"]+"\n" 
			);
	    } else {
			tell_room(notifications[i], 
				weather_states[new_state]["c_worse_msg"]+"\n" 
			);
	    }
	}
	current_state = new_state;
	// The thunder god's anger ....
	if( new_state==sizeof(weather_states)-1 )
		call_out( "call_thunder", 10 );
}

// correct_date is added by Ruby@Eastern_Story for
// correct the bug of query_game_time() & query_c_game_time()
// get code from init_game_time() because lazy to modify too much :P)
int correct_date()	
{
        int current_time;

        current_time = time() - START_GAME_TIME;
        current_year = START_YEAR;
        while (current_time>YEAR_LENGTH) {
                current_time -= YEAR_LENGTH ;
                current_year ++;
	}
        current_month = START_MONTH ;
        while (current_time>months[current_month]["length"]*DAY_LENGTH) {
                current_time -= months[current_month]["length"]*DAY_LENGTH;
                current_month ++;
                if( current_month==num_months ) {
                        current_month=0;
                        current_year ++;
		}
	}
        current_day = START_DATE + current_time/DAY_LENGTH;
	current_time -= (current_time/DAY_LENGTH)*DAY_LENGTH - START_TIME;
	return current_time ;

}

// This function is called at create time. It gets the current time,
// and it sets the game time appropriately. We could just calculate the
// game times as needed, but that would be slower. Best to calculate it from
// real time once, then update it occasionally.

void init_game_time()
{
	int current_time;

	current_time = correct_date();

	current_phase= 0;
	while (current_time> day_phases[current_phase]["length"]) {
		current_time -=	day_phases[current_phase]["length"];
		current_phase ++;
		if( current_phase >= num_phases ) current_phase = 0;
	}
	call_out("change_phase", day_phases[current_phase]["length"] -
				current_time);

// Now, we have to figure out the right phase of the moon and the number
// of days into that phase that we are.
	current_time = time() - START_GAME_TIME;
	current_time = current_time % (MOON_PERIOD*DAY_LENGTH) ;
	moon_phase_days = current_time/DAY_LENGTH;
	current_moon_phase = 0;
	while (moon_phase_days > moon_phases[current_moon_phase]["length"] )
		moon_phase_days -= (int)moon_phases[current_moon_phase]["length"];
}

void create() {
	seteuid(getuid()) ;
// Read in the day phases file.
	read_day_phases() ;
// Read in the weather data file
	read_weather() ;
// Read in the month data.
	read_months() ;
// Read in the moon data.
	read_moon() ;
// Initialize current date.
	init_game_time() ;
	notifications = ({ }) ;
	current_state = 0 ;
	change_weather() ;
}

// This function checks if there is outside light or not. The rule is,
// in daytime there is always light. At nighttime, there is light if
// the sky is clear, otherwise there is not light.

int query_ambient_light()
{
	if ( day_phases[current_phase]["daylight"] ) {
		return 1 ;
	} else {
		return !weather_states[current_state]["inclement"] ;
	}
}

// Returns the message associated with this time of day.

varargs string query_current_day_phase(int chinese_mode)
{
	return day_phases[current_phase]["c_look_msg"]+"\n";
}

// Returns the message associated with this weather state.
// Usually you want to use the query_weather_msg instead, which makes
// sure you can see the sun and the like.

string query_current_weather() {
	return weather_states[current_state]["look_msg"]+"\n" ;
}

// This function returns a string describing the current moon phase.

query_current_moon_phase() {
	return moon_phases[current_moon_phase]["look_msg"]+"\n" ;
}


// This function returns a string describing the current weather. If the
// weather is not inclement, it tells you where the sun/moon is, otherwise
// it doesn't, and it describes the current weather also.

varargs string query_weather_msg(int chinese_mode)
{
	string str ;

	str = "" ;
	if (!weather_states[current_state]["inclement"]) 
		str = sprintf("%s%s��",str, day_phases[current_phase]["c_look_msg"] );
	
	str += weather_states[current_state]["c_look_msg"];
	if(!day_phases[current_phase]["daylight"] &&
		!weather_states[current_state]["inclement"]) 
		str = sprintf("%s��%s",str,moon_phases[current_moon_phase]["c_look_msg"]);
	else
		str += "��";
	if(strlen(str)>50)
		return extract(str, 0, 59) + "\n" + extract(str, 60) + "\n";
	else return wrap(str, 70);
}

string query_game_time() {

	int i,j,k ;

	i = correct_date();
	i = i * 86400 / DAY_LENGTH ;
	j = i / 3600 ;
	k = i % 3600 ;
	k = k / 60 ;
//	if( j > 23 ) j = 0;
	return sprintf("%02d:%02d, %s %d, Year %d", j, k,
	months[current_month]["name"], current_day, current_year );
}


string query_c_game_time() {

	int i,j,k ;
	string msg;

	i = correct_date();
	i = i * 86400 / DAY_LENGTH ;
	j = i / 3600 ;
	k = i % 3600 ;
	k = k / 60 ;
//	if( j > 23 ) j = 0;
	if( j < 4 ) msg = "��ҹ";
	else if( j < 6 ) msg = "�賿";
	else if( j < 9 ) msg = "����";
	else if( j < 12 ) msg = "����";
	else if( j < 17 ) msg = "����";
	else if( j < 19 ) msg = "����";
	else if( j < 23 ) msg = "����";
	else msg = "ҹ��";
	if( j > 12 ) j -= 12;
	return sprintf("������ %d �꣬%s %d �գ�%s %d ʱ %d ��",current_year,
	months[current_month]["c_name"], current_day, msg, j, k );
}


// This function adds the object passed to the list of objects that
// will receive time and weather notices. Call this in any object that
// wants them. Outside rooms automatically add themselves to this list.
// Other objects like vampires can recieve_message() and take any actions
// they might want to.
void request_weather_notices (object ob) {
	if( !ob ) return;
    if (member_array(ob,notifications)>-1) return ;
	notifications += ({ ob }) ;
}

// This function requests that an object be taken off the list
// of notified objects.
void cease_weather_notices (object ob) {
	notifications -= ({ ob }) ;
}

// Diagnostics.

void write_obs() {
	write(dump_variable(notifications)) ;
}
