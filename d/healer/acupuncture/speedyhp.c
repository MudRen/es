// This is a acupuncture effect object . rewrite from power-boost
//  spell By Annihilator@Eastern.Stories
// acupuncture by Indra@ES
#include <conditions.h>

#define EFFECT_ID "speedyhp"
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
	me->block_attack(delay_time) ;
	me->set_temp("cast_busy", 1) ;
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
		 me->query("c_name"),targetname ),
		({ me ,target }) );

	call_out( "effect", delay_time, level, me, target );
	return 1;
}

void effect(int level, object caster, object dest)
{
	int boost, duration, heal_hp,heal_body,*hp_cond,*body_cond;
	mixed *condis ;

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
	            "��������ڵ�Ѫ����ʼ����������ͬʱȫ����˿ڿ�ʼ��Щ΢������\n"
		);
		boost = level - BASIC_NEEDED + 1 ;		
		if( caster == dest )
			duration = level * 55 + (int)caster->query_stat("pie") * 5;
		else
			duration = level * 45 + (int)caster->query_stat("pie") * 5;

                hp_cond = dest->query("conditions/_heal_hp") ;
                body_cond = dest->query("conditions/_heal_body") ;
                
                heal_hp = hp_cond[0]-(hp_cond[0]*boost/8) ;                
                heal_body = body_cond[0]-boost*2 ;

                if( heal_hp < 1 ) heal_hp = 1 ;
                if( heal_body < 20 ) heal_body = 20 ;
                
                HEAL_HP->apply_effect(dest,heal_hp,hp_cond[1]+boost) ;		
                HEAL_BODY->apply_effect(dest,heal_body,body_cond[1]+boost) ;

		dest->set_temp("acup_effect/"EFFECT_ID, 1);
		
        	tell_room( environment(dest),sprintf(
	        	"��֪�ǲ��Ǵ��,�����%s���˿�����������ɫ�Ĺ�â��\n"
	        	,dest->query("c_name")),dest ) ;
		call_out( "expire", duration, dest, hp_cond, body_cond ) ;
	}
	return ;	 
}

void expire( object player,int *hp_cond,int *body_cond )
{
    if( !player ) return;
    tell_object( player,
		"������˿ڵĸ�ԭ��������ǰ�죬ͬʱ��Ѫ��������û���....��\n" );
    HEAL_HP->apply_effect(player,hp_cond[0],hp_cond[1]) ;
    HEAL_BODY->apply_effect(player,body_cond[0],body_cond[1]) ;
    player->delete_temp("acup_effect/"+EFFECT_ID);
    return ;
}

