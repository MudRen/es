// This is a acupuncture effect object . rewrite from power-boost
//  spell By Annihilator@Eastern.Stories
// 
// acupuncture by Indra@ES

int query_sp_cost(int eff_lv,int skill_lv)
{
    return eff_lv * 10 + (5-skill_lv)*2;               
}

int query_need_skill() { return 0 ; }


int acu_effect(int level, object target)
{
	int delay_time;
	object me ;

        me = this_player();
	
        delay_time = 3;
	me->block_attack(delay_time);
	me->set_temp("cast_busy", 1);
	target->delete("acupuncted_pts") ;
	target->delete_temp("acupuncted_pts") ;	
	
	write(  "��������²�ǣ��"+target->query("c_name")+
		"����,���������ͳ�ȥ��\n" );
	tell_room( environment(me), 
		me->query("c_name") + "������²�ǣ��"
		+target->query("c_name")+"����,���������ͳ�ȥ��\n",
		({ me ,target}) );
        tell_object(target,me->query("c_name") + 
                           "������²�ǣ�������,���������ͽ�����\n" ) ;

	call_out( "effect", delay_time, level, me, target );
	return 1;
}

void effect(int level, object caster, object dest)
{
	if( !dest || !present(dest, environment(caster)) ) 
	{
	  tell_object( caster, 
	    "��֪�����,Ҳ���Ǿ������Ǹ��ɹŴ����֮,��Ļ����ߵ��ˡ�\n");
	  return;
	}
	
	tell_object( dest,
	    "��������ڵ�Ѫ����ʼ����������������ȫ��ͻȻ��ʼ��ʹ....��\n");
	tell_room( environment(dest), 
	        dest->query("c_name")+"������ʼ����, �������Ҫ����Ѫ���ˡ�\n"
		,dest );
	tell_object( caster,
	    "��ͻȻ���ֶԷ�Ѫ�����㼤������,�����������Ѿ�������....��\n");
	dest->receive_damage( level * 5 );        
	caster->receive_damage( level * 5 );        
        return ;
}



