// This is a spell object
// By Annihilator@Eastern.Stories

int query_sp_cost(object caster, int level, string target) { return 20 + level * 10; }

int query_need_skill(int level) { return 15+10*level; }

int cast(int level, string target)
{
	int chinese_mode, delay_time;
	object me, dest;

    me = this_player();
	chinese_mode = can_read_chinese(me);
	
	if( (int)me->query_skill("white-magic") < query_need_skill(level) ) {
  		tell_object( me,"��İ�ħ�����ܲ�����ʹ����ȼ���ħ��!\n");
		return 0;
	}
	
	if( target == "NONE" ) dest = me->query_attacker();
	else dest = present( target, environment(me) );
	if( !dest || dest==this_player() || dest->query("no_attack")
	|| dest->stop_attack() ) {
	  tell_object( me,"Ҫ��˭ʹ���������\n");
	  return 0;
	}
	if( me->query("npc") && me->query("magic_delay") )
	    delay_time = (int)me->query("magic_delay");
	else
	    delay_time = 3+level;
	me->block_attack(delay_time);
	me->set_temp("cast_busy", 1);
	write("�㿪ʼ���а�ħ���������������....��\n");
	tell_room( environment(me),
		me->query("c_name") + "��ʼ��һ�ֳٻ���������������....��\n",
		me );
		
	dest->kill_ob(me);
	me->kill_ob(dest);
	call_out( "effect", delay_time, level, me, dest );
	return 1;
}

void effect(int level, object caster, object dest)
{
	int boost, duration;
    object env;
    
    caster->set_temp("cast_busy", 0);
    if( !dest ) {
      tell_object( caster,"�㷢�����Ŀ���Ѿ����ˡ�\n");
      return;
    }
    env = environment(caster);
    if( !env || !present( dest, env ) ) {
      tell_object( caster,"�㷢�����Ŀ���Ѿ����������ˡ�\n");
      return;
    }
	if( dest->query_temp("effect/paralyze") ) {
		tell_object( dest,
		    "һ��ҫ�۵ķۺ�ɫ��â�������㣬��������ò�û��ʲ�᲻ͬ....��\n");
	} else {
		tell_object( dest,
			"һ��ҫ�۵ķۺ�ɫ��â�������㣬�����ȫ���⿪ʼ��ý�Ӳ ....��\n"
		);
		boost = (int)dest->query_stat("dex") / 2;
		duration = (level+1) * 15 + (int)caster->query_stat("pie") * 3;
		dest->modify_stat("dex", -boost );
		dest->set_temp("effect/paralyze", 1);
		call_out( "expire", duration, dest, boost );
	}
	tell_room( environment(dest),
		"һ��ҫ�۵ķۺ�ɫ��â������"+dest->query("c_name")+"��Ȼ����ɢȥ��\n",
		dest );
}


void expire( object player, int boost )
{
    if( !player ) return;
	tell_object( player,"�����ȫ���������»ص������־����֮�� ....��\n");
	player->modify_stat("dex", boost);
	player->set_temp("effect/paralyze", 0 );
}
