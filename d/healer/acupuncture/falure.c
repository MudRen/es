// This is a acupuncture effect object . rewrite from power-boost
//  spell By Annihilator@Eastern.Stories
// 
// acupuncture by Indra@ES

int query_sp_cost(int eff_lv,int skill_lv)
{
                  return eff_lv * 10 + (5-skill_lv)*2;               
}

int query_need_skill() { return 2 ; }


int cast(int level, object target)
{
	int delay_time;
	object me ;

        me = this_player();
	
//	if( me->query("npc") && me->query("magic_delay") )
//	    delay_time = (int)me->query("magic_delay");
//	else
	  
        delay_time = 3;
	me->block_attack(delay_time);
	me->set_temp("cast_busy", 1);
	target->delete("acupuncted_pts") ;
	target->delete_temp("acupuncted_pts") ;	
	
	write(  "��������²�ǣ��"+target->query("c_name")+
		"����,���������ͳ�ȥ��\n" );
	tell_room( environment(me), ({
		me->query("c_name") + "������²�ǣ��"
		+target->query("c_name")+"����,���������ͳ�ȥ��\n"}),
		me ,target);
        tell_object(target,me->query("c_name") + 
                           "������²�ǣ�������,���������ͽ�����\n" ) ;

	call_out( "effect", delay_time, level, me, target );
	return 1;
}

void effect(int level, object caster, object dest)
{
	int speed, duration;

        caster->set_temp("cast_busy", 0);
	if( !dest || !present(dest, environment(caster)) ) {
	  tell_object( caster, 
	    "��֪�����,Ҳ���Ǿ������Ǹ��ɹŴ����֮,��Ļ����ߵ��ˡ�\n" 
	  );
	  return;
	}
	
	if( dest->query_temp("effect/windex") ) {
		tell_object( dest,
			"��������ڵ�Ѫ����ʼ�������������Ǻ���û��ʲ�᲻ͬ....��\n"
		);
	} else {
		tell_object( dest,
			"��������ڵ�Ѫ����ʼ���ڣ�����������Ǻ�������������״̬�У�\n"
		);
		speed = level ;
		if( caster == dest )
			duration = level * 50 + (int)caster->query_stat("pie") * 4;
		else
			duration = level * 40 + (int)caster->query_stat("pie") * 4;
		dest->modify_stat("dex", speed);
		dest->set_temp("effect/windex", 1);
		call_out( "expire", duration, dest, speed );
	}
	tell_room( environment(dest), ({
		"����Ȼ����"+dest->query("c_name")+"�Ķ�����ÿ���, \n"
		"�����������ƶ������µĲ���\n"}),
		dest );
}

void expire( object player, int speed)
{
    if( !player ) return;
	tell_object( player,
		"���������ٶ�����������ͬʱ��Ѫ��������û���....��\n" );
	player->modify_stat("dex", -speed);
	player->set_temp("effect/windex", 0 );
}


