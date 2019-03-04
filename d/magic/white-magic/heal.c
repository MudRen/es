// By Annihilator@Eastern.Stories
// update by Kyoko.

int query_sp_cost(object caster, int level, string target) { return 20 + level * 20; }

int query_need_skill(int level) { return 100>20+20*level? 20+20*level:100; }

int cast(int level, string target)
{
	int delay_time;
	object me, dest;

    me = this_player();
	
	if( (int)me->query_skill("white-magic") < query_need_skill(level) ) {
		tell_object( me,
			"��İ�ħ�����ܲ�����ʹ����ȼ���ħ��!\n"
		);
		return 0;
	}
	
	if( target == "NONE" ) dest = me;
	else if( !(dest= present( target, environment(me) )) ) {
		tell_object( me, "Ҫ��˭ʩչҽ������\n"	);
		return 0;
    }
    if( me->query("npc") && me->query("magic_delay") )
	    delay_time = (int)me->query("magic_delay");
	else
	    delay_time = 3;
	me->block_attack(delay_time);
	me->set_temp("cast_busy", 1);
	write("�㿪ʼ���а�ħ����ҽ����������....��\n");
	tell_room( environment(me), 
		me->query("c_name") + "��ʼ��һ����͵�������������....��\n",
		me );
	call_out( "effect", delay_time, level, me, dest );
	return 1;
}

void effect(int level, object caster, object dest)
{
	int heal, now_sp;
    
    caster->set_temp("cast_busy", 0);
    if( !dest || !present(dest, environment(caster)) ) {
      tell_object( caster, "��ʩ����Ŀ���ߵ��ˡ�\n" );
      return;
    }
    
    if( caster == dest )
    	heal = 20 + level * 25;
    else
		heal = 18 + level * 17;
	heal += random( (int)caster->query_stat("pie") / 2 );
	dest->receive_healing(heal);
	tell_object( dest, 
		"һ����͵���ɫ��â�������㣬�����ϵ��˿ڿ�ʼ�����ˣ�\n"
	);
	tell_room( environment(dest), 
		"һ����͵���ɫ��â������"+dest->query("c_name")+"��Ȼ����ɢȥ��\n",
		dest
	);
	if( caster == dest ) return;
	now_sp = (int)dest->query("spell_points");
	now_sp += heal / ( 10 - level );
	if( now_sp > (int)dest->query("max_sp") ) 
	  now_sp = (int)dest->query("max_sp");
	dest->set("spell_points", now_sp);
}
