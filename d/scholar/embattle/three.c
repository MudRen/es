#define NEED_MEMBERS 3
#define EMBATTLE_FAIL_DAMAGE 22
#define EMBATTLE_FAIL_RATE 15
#define COST_SP 6
#define EMBATTLE_NAME "�����������"

string *c_message=({
    "������������ͬ��Э���ѵ��˼������\n",
    "�����������������������������ⲽ��\n",
    "�����˵��˵��������������й������˵�����\n",
    "б��ֱ����ͻȻ����ֱ�����˵�Ҫ��\n",
    "������һ�����ñ��й��������̣���һ���ñ��й������Ϸ�����һ�˻ӱ����й�ֱ��\n",
    "����ͬ��Σ�գ��Ӷ����ϵ���������֮���ɲ���\n"
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
        if ( members == NEED_MEMBERS ) return 1;
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
        	if ( !usr[i] ) continue ;
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
                tell_object(usr[i],set_color(victim->query("c_name")+"ͻȻ���һ���������������..\n(��"+
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

	if ( ! me ) {
		remove_effect(usr,total_int,"������������ȷ������ɢ����..\n");
		return;
	} else
		me->add("spell_points",-COST_SP);
	if ( !check_members(usr,me)) {
		remove_effect(usr,total_int,"������������ȷ������ɢ����..\n");
		return;
	}
        else if ( ! me->query_attacker()) {
                remove_effect(usr,total_int,"ս��������������..\n");
                return ;
	}
	else if ( is_embattle_fail(me) ) {
		remove_effect(usr,total_int,"�����ƺ������������ת����������������β��� ..\n");
		call_out("embattle_fail",3,usr);
		return ;
	}
	else if ( (int)me->query("spell_points") < COST_SP ) {
                remove_effect(usr,total_int,me->query("c_name")+"���񲻼��ˣ���û�а취��ά����ȥ��..\n");
                return ;
	}
        else if ( member_array(victim,me->query_attackers())==-1 ) {
                remove_effect(usr,total_int,"ս��������������..\n");
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
		write("��� !! �������ԣ����ܽ����ȷ������ !!\n");
		return 1;
	}

	if ( (int)me->query("spell_points") < COST_SP ) {
		write("��ľ��񲻼��ˣ�Ӧ�úú���Ϣһ�¡�\n");
		return 1;
	}
	setup_effect(usr1,total_int,me->query("c_name")+"�󺰣����ע�� !! Ŀ��"+victim->query("c_name")+"��"+EMBATTLE_NAME+" -- ���� !!\n");
        me->set_temp("embattle_victim",victim);
        me->set_temp("embattle_party",usr1);
        me->set_temp("embattle_busy_check","three");
	tell_room(environment(me),set_color(me->query("c_name")+"�Ķ���ͻȻ���һ�����Σ�Χס"+victim->query("c_name")+"����������\n","HIY"),usr1);
	party_kill_ob(usr1,victim);
	call_out("check_embattle",5,me,usr1,victim,total_int);
        return 1;
}
