//#pragma save_binary

 
/*
* Move living object to another room. Give the appropriate
* message to on-lookers.
* The optional message describes the message to give when the player
* leaves.
*/ 
varargs int move_player(object me,mixed dest, mixed message, string dir)
{
	object prev;
	int res;
	
	prev = environment(me);
	if( !res = me->move(dest) ) {
		tell_object(me, "( ������ԭ��.... )\n");
		return res;
	}

	if( me->query_attackers() && (int)me->clean_up_attackers() == 0) {
		me->set_temp("last_attack_skill", 0);
		//write("combat test6!\n");
		tell_object(me, "ս��������.��\n");
	}

	if(message == "SLIENCE") return 0;
	if(message == "SNEAK") {
		call_other("/cmds/std/_look","cmd_look","");
//		me->command("look");
		return 0;
	} 

	if( !me->query("invisible") && !me->query("player_invisible")) {
		if(message == 0 || message == "") {
			if(dir && dir != "") {
				tell_room(prev, 
					(string)me->query_c_mout(dir) + "\n",
					me);
				tell_room(environment(), 
					(string)me->query_c_min() + "\n",
					me);
			} else {
				tell_room(prev, 
					(string)me->query_c_mmout() + "\n",
					me);
				tell_room(environment(), 
					(string)me->query_c_mmin() + "\n",
					me);
			}
		} else {
			if( pointerp(message) ) {
				tell_room(prev, 
					sprintf(message[0], me->query("c_name"))
					, me );
				tell_room(environment(), 
					sprintf(message[1], me->query("c_name"))
					, me );
			} else {
				tell_room(prev, message + "\n", me);
				tell_room(environment(), 
					(string)me->query_c_min() + "\n",
					me );
			}
		}
	}
	me->set_temp("force_to_look",1);
	me->command("look") ;
	me->set_temp("force_to_look",0);
	return 0;
}

int query_vision(object me)
{
	mixed *contents;
	object env;
	int loop;

	//	If there is no environment, you obviously can't see anything. :)
   if( !env = environment(me) )  return 0;
 
	// 	Check to see if user has special vision capabilities,
	//	either artificial or permanent
	if( me->query("full_vision") ) return 1;
 
	//	Check to see if user is blind, or environment prevents sight
	if(me->query("blind") || env->query("no_vision") )
		return 0;
 
	//	Check light level in the environment
	if( env->query("light")) return 1;
	if( me->query("dark_sight")) return 1;

	contents = all_inventory(env);
 
   //	Check to see if any of the environment's contents have
   //	a light source of any kind
	for(loop=0; loop<sizeof(contents); loop++)
		if(contents[loop]->check_light()) return 1; 
	return 0;
}
