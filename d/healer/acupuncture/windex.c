// This is a acupuncture effect object . rewrite from power-boost
//  spell By Annihilator@Eastern.Stories
// 
// acupuncture by Indra@ES

#define EFFECT_ID "windex"
#define BASIC_NEEDED 2
int query_sp_cost(int eff_lv,int skill_lv)
{
       return eff_lv * 10 + (5-skill_lv)*2;               
}

int query_need_level() { return BASIC_NEEDED ; }


int acu_effect(int level, object target)
{
	int delay_time;
	string targetname ;
	object me ;

        me = this_player();
	
        delay_time = 3;
	me->block_attack(delay_time);
	me->set_temp("cast_busy", 1);
	target->delete("acupuncted_pts") ;
	target->delete_temp("acupuncted_pts") ;	

        if(target == me) targetname = "�Լ�" ;
        else
        { 
          targetname = target->query("c_name") ;
          tell_object(target,sprintf(
                     "%s������²�ǣ�������,���������ͽ�����\n",
                     me->query("c_name")
                     ) ) ;
         }

	write(sprintf("��ϯ�����²�ǣ��%s����,���������ͳ�ȥ��\n",
	               targetname));

	tell_room( environment(me),sprintf( 
		"%s������²�ǣ��%s����,���������ͳ�ȥ��\n",
		 me->query("c_name"),targetname ) ,
		({ me ,target }) );

	call_out( "effect", delay_time, level, me, target );
	return 1;
}

void effect(int level, object caster, object dest)
{
	int speed, duration ,verify, cur_val;

        caster->set_temp("cast_busy", 0);
	if( !dest || !present(dest, environment(caster)) ) {
	  tell_object( caster, 
	    "��֪�����,Ҳ���Ǿ������Ǹ��ɹŴ����֮,��Ļ����ߵ��ˡ�\n" 
	  );
	  return;
	}
	
	if( dest->query_temp("acup_effect/"+EFFECT_ID) ) {
		tell_object( dest,
			"��������ڵ�Ѫ����ʼ�������������Ǻ���û��ʲ�᲻ͬ....��\n"
		);
	} else {
		tell_object( dest,
			"��������ڵ�Ѫ����ʼ���ڣ�����������Ǻ�������������״̬�У�\n"
		);
		speed = level - BASIC_NEEDED + 1 ;
		if( caster == dest )
			duration = level * 50 + (int)caster->query_stat("pie") * 4;
		else
			duration = level * 40 + (int)caster->query_stat("pie") * 4;
	
	        cur_val = (int)dest->query_stat("dex") ;
	        
	        if( (cur_val+speed) > 30 ) speed = 30 - cur_val ; 
	        
		dest->modify_stat("dex", speed);
		dest->set_temp("acup_effect/"+EFFECT_ID, 1);
		tell_room( environment(dest),sprintf( 
	        	"����Ȼ����%s�Ķ�����ÿ���, \n"
		        "�����������ƶ������µĲ���\n"
		        ,dest->query("c_name")), dest );
		call_out( "expire", duration, dest, speed );
	}
	return ;
}

void expire( object player, int speed)
{
    if( !player ) return;
    tell_object( player,
		"���������ٶ�����������ͬʱ��Ѫ��������û���....��\n" );
    player->modify_stat("dex", -speed);
    player->delete_temp("acup_effect/"+EFFECT_ID);
    return ;	
}


