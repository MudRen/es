#define NEED_NEMBERS 4
#define AC_EFFECT 25
#define DB_EFFECT 15
#define WC_EFFECT 15
#define EMBATTLE_FAIL_DAMAGE 30
#define EMBATTLE_FAIL_RATE 25
#define COST_SP 10
#define EMBATTLE_NAME "����������"

int total_int=0,flag=1;

string *c_message=({
    "����������������������������ⲽ��\n",
    "������������ͬ��Э���ѵ��˼������\n",
    "�����˵��˵��������������й������˵�����\n",
    "б��ֱ����ͻȻ����ֱ�����˵�Ҫ��\n",
    "����ȫ����ťʹ�������ݰ�����ĵ��⽣Ӱ֮��",
    "����ͬ��Σ�գ��Ӷ����ϵ���������֮���ɲ���\n"
                  });

int check_members(object *usr)
{
        int i,members = 0 ;

        for( i=0; i<sizeof(usr); i++ ) 
                if (environment(usr[i]) == environment(this_player())) {
                   if(flag) total_int+=(int)usr[i]->query_stat("int");
			members ++ ;
		}

        if ( members == NEED_NEMBERS ) return 1;
                else return 0;
}

void party_kill_ob(object *usr,object victim)
{
        int i ;

        for( i=0; i<sizeof(usr); i++ )
          if (environment(victim)==environment(usr[i]))
		usr[i]->kill_ob(victim);
	return;
}

void setup_effect(object *usr,string why)
{
        int i ;

        for( i=0; i<sizeof(usr); i++ ) {
		usr[i]->set_temp("embattle_busy",1);
		usr[i]->set_temp("extra_ac/body",(total_int)/4+(int)usr[i]->query_temp("extra_ac/body"));
                usr[i]->set_temp("extra_db/body",(total_int/6)+(int)usr[i]->query_temp("extra_db/body"));
		usr[i]->calc_armor_class();
		usr[i]->set_temp("extra_wc",(int)usr[i]->query_temp("extra_wc")+(total_int/6));
                usr[i]->set_temp("embattle_ac",total_int/4);
                usr[i]->set_temp("embattle_db",total_int/6);
                usr[i]->set_temp("embattle_wc",total_int/6);
//  ���Ƕ��ŵĹ�����extra_wc ���ظ� weapon_class1 �����趨 weapon class2 ��
//	��ɲ����ڵ�˫����������Ӧȥ����
//  �Ҳ��˽�������������ԭ������ check һ��
//  ���ս������ϸ������ο� /std/body/attack.c
                tell_object(usr[i],why);
	}
	return;
}

void remove_effect(object *usr,string why)
{
        int i;

	why = set_color(why,"HIR");
        for( i=0; i<sizeof(usr); i++ ) {
		usr[i]->delete_temp("embattle_busy");
		usr[i]->set_temp("extra_ac/body",(int)usr[i]->query_temp("extra_ac/body")-(total_int/4));
                usr[i]->set_temp("extra_db/body",(int)usr[i]->query_temp("extra_db/body")-(total_int/6));
		usr[i]->calc_armor_class();
		usr[i]->set_temp("extra_wc",(int)usr[i]->query_temp("extra_wc")-(total_int/6));
		tell_object(usr[i],why);
		}
	return ;
}

void embattle_fail(object *usr)
{
        int i;
	object victim;

        for( i=0; i<sizeof(usr); i++ ) 
	if (victim=usr[i]->query_attacker()) {
		usr[i]->receive_damage(EMBATTLE_FAIL_DAMAGE);
                tell_object(usr[i],set_color(victim->query("c_name")+"ͻȻ���һ���������������..\n(��"+
		"/adm/daemons/statsd"->status_string(usr[i])+")\n","HIY"));
	}
	return;
}

int is_embattle_fail()
{
	object me,victim;
	int rate ;

	me = this_player();
	victim = me->query_attacker();
	rate = (int)me->query_perm_stat("int")+(int)me->query_perm_stat("dex")
		+(int)me->query_perm_stat("kar");
	rate = rate+rate+rate-(int)victim->query_perm_stat("int")
			-(int)victim->query_perm_stat("dex");
	if (random(rate) > EMBATTLE_FAIL_RATE ) return 0;
	return 1;
}

void check_embattle(object *usr,object place,object victim)
{
        int is_special,flag;

	this_player()->add("spell_points",-COST_SP);
	if ( !check_members(usr)) {
		remove_effect(usr,"������������ȷ������ɢ����..\n");
                place->set("eight_zeng_ok",0);
		return;
	}
        else if ( ! this_player()->query_attacker()) {
                remove_effect(usr,"ս��������������..\n");
                place->set("eight_zeng_ok",0);
                return ;
	}
	else if ( is_embattle_fail() ) {
		remove_effect(usr,"�����ƺ������������ת����������������β��� ..\n");
                place->set("eight_zeng_ok",0);
		call_out("embattle_fail",3,usr);
		return ;
	}
	else if ( (int)this_player()->query("spell_points") < COST_SP ) {
                remove_effect(usr,this_player()->query("c_name")+"���񲻼��ˣ���û�а취��ά����ȥ��..\n");
                place->set("eight_zeng_ok",0);
                return ;
	}
        else if (!(int)place->query("eight_zeng_ok")) {
                remove_effect(usr,"��һ���鷢�����⣬������ʧ��..\n");
                return;
        }
        else if ( member_array(victim,this_player()->query_attackers(),flag)==-1 ) {
                remove_effect(usr,"ս��������������..\n");
                return ;
        }
	else {
                is_special=random(sizeof(c_message));
                if (is_special==3)
                   victim->receive_damage(-COST_SP);
                tell_room(environment(this_player()),set_color(this_player()->query("c_name")+c_message[is_special],"HIY"));
                call_out("check_embattle",5,usr,place,victim);
        }

	return;
}

int start_embattle(object me,object victim)
{
        object *usr,place;

        usr = (mixed *)me->query_temp("party_members");
        place=environment(me);

	if ( !check_members(usr)) {
		write("��� !! �������ԣ����ܽ����ȷ������ !!\n");
                place->set("eight_zeng_ok",0);
                place->delete("eight/"+me->query("cap_name"));
		return 1;
	}

        flag=0;

	if ( (int)me->query("spell_points") < COST_SP ) {
		write("��ľ��񲻼��ˣ�Ӧ�úú���Ϣһ�¡�\n");
                place->set("eight_zeng_ok",0);
                place->delete("eight/"+me->query("cap_name"));
		return 1;
	}
        call_out("check_party",1,me,victim,usr,place);
	call_out("check_embattle",5,usr,place,victim);
        return 1;
}

int check_party(object me,object victim,object *usr,object place)
{
  if (place->query("eight_zeng_ok")==0)
    write("��һ�����������⣬����ʧ�� !\n");
  else {
    setup_effect(usr,me->query("c_name")+"�󺰣����ע�� !! Ŀ��"+victim->query("c_name")+"��"+EMBATTLE_NAME+" -- ���� !!\n");
    me->set_temp("embattle_victim",victim);
    me->set_temp("embattle_party",me->query_temp("party_members"));
    me->set_temp("embattle_busy_check","eight");
    tell_room(environment(me),set_color(me->query("c_name")+"�Ķ���ͻȻ���һ�����Σ�Χס"+victim->query("c_name")+"����������\n","HIY"),usr);
    party_kill_ob(usr,victim);
  }
  me->delete_temp("embattle_ready_check");
  call_out("delete_mark",2,me,place);
  return 1;
}

int delete_mark(object me,object place)
{
  place->delete("eight/"+me->query("cap_name"));
  return 1;
}
