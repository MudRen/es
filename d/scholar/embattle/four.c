#define NEED_NEMBERS 4
#define EMBATTLE_FAIL_DAMAGE 25
#define EMBATTLE_FAIL_RATE 20
#define COST_SP 8
#define EMBATTLE_NAME "四象□玑阵"

string *c_message=({
    "带领著队伍走著四象□玑阵的特殊步法\n",
    "喊著：让我们同心协力把敌人歼灭掉吧\n",
    "发现了敌人的破绽，连出三招攻击敌人的破绽\n",
    "斜退直进，突然出招直击敌人的要害\n",
    "吆喝一声，四人从四个方位一起攻击敌人\n",
    "发现同伴危险，挥动手上的武器攻敌之不可不守\n"
                  });

int check_members(object *usr,object me)
{
        int i,members = 0 ;

	if ( !me ) return 0;
        for( i=0; i<sizeof(usr); i++ ) {
        	if ( !usr[i] ) return 0;
                if (environment(usr[i]) == environment(me))
			members ++ ;
	}
        if ( members == NEED_NEMBERS ) return 1;
                else return 0;
}

void party_kill_ob(object *usr,object victim)
{
        int i ;

        for( i=0; i<sizeof(usr); i++ )
         if(usr[i])
          if (environment(victim)==environment(usr[i]))
		usr[i]->kill_ob(victim);
	return;
}

void setup_effect(object *usr,int total_int,string why)
{
        int i ;

        for( i=0; i<sizeof(usr); i++ ) {
            if(usr[i]) {
		usr[i]->set_temp("embattle_busy",1);
		usr[i]->set_temp("extra_ac/body",(total_int/5)+(int)usr[i]->query_temp("extra_ac/body"));
                usr[i]->set_temp("extra_db/body",(total_int/8)+(int)usr[i]->query_temp("extra_db/body"));
	//	usr[i]->calc_armor_class();
		usr[i]->set_temp("extra_wc",(int)usr[i]->query_temp("extra_wc")+(total_int/8));
                usr[i]->set_temp("embattle_ac",total_int/5);
                usr[i]->set_temp("embattle_db",total_int/8);
                usr[i]->set_temp("embattle_wc",total_int/8);
                tell_object(usr[i],why);
            }
	}
	return;
}

void remove_effect(object *usr,int total_int,string why)
{
        int i;

	why = set_color(why,"HIR");
        for( i=0; i<sizeof(usr); i++ ) {
        	if ( !usr[i] ) continue;
           if(usr[i]->query_temp("embattle_busy")) {
		usr[i]->delete_temp("embattle_busy");
		usr[i]->set_temp("extra_ac/body",(int)usr[i]->query_temp("extra_ac/body")-(total_int/5));
                usr[i]->set_temp("extra_db/body",(int)usr[i]->query_temp("extra_db/body")-(total_int/8));
	//	usr[i]->calc_armor_class();
		usr[i]->set_temp("extra_wc",(int)usr[i]->query_temp("extra_wc")-(total_int/8));
		tell_object(usr[i],why);
           }
	}
	return ;
}

void embattle_fail(object *usr)
{
        int i;
	object victim;

        for( i=0; i<sizeof(usr); i++ ) 
        if (usr[i]) {
	if (victim=usr[i]->query_attacker()) {
		usr[i]->receive_damage(EMBATTLE_FAIL_DAMAGE);
                tell_object(usr[i],set_color(victim->query("c_name")+"突然大吼一声，攻向你的破绽..\n(你"+
		"/adm/daemons/statsd"->status_string(usr[i])+")\n","HIY"));
	}
        }
	return;
}

int is_embattle_fail(object me)
{
	object victim;
	int rate ;

	victim = me->query_attacker();
	rate = (int)me->query_perm_stat("int")+(int)me->query_perm_stat("dex")
		+(int)me->query_perm_stat("kar");
	rate = rate+rate+rate-(int)victim->query_perm_stat("int")
			-(int)victim->query_perm_stat("dex");
	if (random(rate) > EMBATTLE_FAIL_RATE ) return 0;
	return 1;
}

void check_embattle(object me,object *usr,object victim,int total_int)
{
        int is_special;

	if ( ! me ) return ;
	me->add("spell_points",-COST_SP);
	if ( !check_members(usr,me)) {
		remove_effect(usr,total_int,"阵中人数不正确，阵形散乱了..\n");
		return;
	}
        else if ( ! me->query_attacker()) {
                remove_effect(usr,total_int,"战斗结束，收阵了..\n");
                return ;
	}
	else if ( is_embattle_fail(me) ) {
		remove_effect(usr,total_int,"敌人似乎察觉了阵势运转的破绽，你觉得情形不对 ..\n");
		call_out("embattle_fail",3,usr);
		return ;
	}
	else if ( (int)me->query("spell_points") < COST_SP ) {
                remove_effect(usr,total_int,me->query("c_name")+"精神不济了，阵法没有办法再维持下去了..\n");
                return ;
	}
        else if ( member_array(victim,me->query_attackers())==-1 ) {
                remove_effect(usr,total_int,"战斗结束，收阵了..\n");
                return ;
        }
	else {
                is_special=random(sizeof(c_message));
                if (is_special==3)
                   victim->receive_damage(-COST_SP);
                tell_room(environment(me),set_color(me->query("c_name")+c_message[is_special],"HIY",me));
                call_out("check_embattle",5,me,usr,victim,total_int);
        }

	return;
}

int start_embattle(object me,object victim)
{
        int i,total_int=0;
        object *usr,*usr1=({});

        usr = (mixed *)me->query_temp("party_members");
        me->set_temp("effect_usr",({}));
        for( i=0; i<sizeof(usr); i++ )
          if (environment(usr[i]) == environment(me)) {
                usr1+=({usr[i]});
                total_int+=usr[i]->query_stat("int");
          }
        me->set_temp("effect_usr",usr1);

	if ( !check_members(usr1,me)) {
		write("糟糕 !! 人数不对，不能结成正确的阵势 !!\n");
		return 1;
	}

	if ( (int)me->query("spell_points") < COST_SP ) {
		write("你的精神不济了，应该好好休息一下。\n");
		return 1;
	}
	setup_effect(usr1,total_int,me->query("c_name")+"大喊：大家注意 !! 目标"+victim->query("c_name")+"，"+EMBATTLE_NAME+" -- 结阵 !!\n");
        me->set_temp("embattle_victim",victim);
        me->set_temp("embattle_party",usr1);
        me->set_temp("embattle_busy_check","four");
	tell_room(environment(me),set_color(me->query("c_name")+"的队伍突然结成一个阵形，围住"+victim->query("c_name")+"发动攻击。\n","HIY"),usr1);
	party_kill_ob(usr1,victim);
	call_out("check_embattle",5,me,usr1,victim,total_int);
        return 1;
}
