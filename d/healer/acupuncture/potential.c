// This is a acupuncture effect object . rewrite from power-boost
//  spell By Annihilator@Eastern.Stories 
// acupuncture by Indra@ES
////#pragma save_binary
// #include "/std/object/prop.c"

//#include <priv.h>
#include <mudlib.h>
//#include <uid.h>

#define EFFECT_ID "potential"
#define BASIC_NEEDED 4

// int geteuid(seteuid(ROOT_UID)) ;
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
                     me->query("c_name") ) ) ;
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
	int normal_skill,duration ,eff ,i ,skill_no, mod ;
        string *skill_name ;
        mapping skills ;
        caster->set_temp("cast_busy", 0);
	if( !dest || !present(dest, environment(caster)) ) {
	     tell_object( caster, 
	      "��֪�����,Ҳ���Ǿ������Ǹ��ɹŴ����֮,��Ļ����ߵ��ˡ�\n" 
	         );
	     return;
    	    }
	
	if( dest->query_temp("acup_effect/"+EFFECT_ID) ) 
	    {
		tell_object( dest,
			"��������ڵ�Ѫ����ʼ�������������Ǻ���û��ʲ�᲻ͬ....��\n"
		);
	    }
	 else
	    {
		tell_object( dest,
			"��������ڵ�Ѫ����ʼ����������ͬʱ���ָ�ӦͻȻĪ��������������\n"
		);
		if( caster == dest )
			duration = level * 50 + (int)caster->query_stat("pie") * 5;
		else
			duration = level * 40 + (int)caster->query_stat("pie") * 5;

                skills = dest->query_skills() ;

		skill_name = keys(skills) ;                
                skill_no = sizeof(skill_name) ;
		eff = (level-BASIC_NEEDED+1) ;
                if(!(skill_no)||skill_no==0) {
                     write("�Է�ʲ�ᶼûѧ����\n") ;
                     return ;
				}
                for(i=0;i<skill_no;i++)
                   {
                     normal_skill=dest->query_perm_skill(skill_name[i]) ;
                     mod = normal_skill*eff/10 ;
                     dest->modify_skill( skill_name[i] , mod ) ;  
// in here , skill store the increasement of skills
                     skills[skill_name[i]] = mod ;                           
                   }  
        	tell_room( environment(dest),sprintf(
		    "��ͻȻ����%s����Ī���Ķ����һ�ɱ��˵�Ӣ����\n",
		    dest->query("c_name") ),dest );

		dest->set_temp("acup_effect/"+EFFECT_ID, 1);
		call_out( "expire", duration, dest, skills);
	}
}

void expire(object player,mapping skill_mod)
{
    int i,skill_no,mod_val ;
    mixed skill_name ;
    mapping skills ;
    
    if( !player ) return;
    skills = player->query_skills() ;
    skill_name = keys(skills) ; 
    for(i=0 ; i <sizeof(skill_name);i++)
    {
   //    normal_skill= player->query_perm_skill(skill_name[i]) ;
   //    current_skill= player->query_skill(skill_name[i]) ;         
   //    player->modify_skill(skill_name[i],  normal_skill - current_skill ); 

         mod_val = skill_mod[skill_name[i]] ;

         if(!(mod_val))
         	continue;
/*
   //   �������������Ǹո��м�ǿ�ļ�������ȴ�Ҳ�����..     
              tell_object(player,"��ļ��ܵ����ƺ�������,����Ǣ��ʦ�����\n") ;
// �ⲿ�ݲ���ȷ����Ϊ��� player skill ̫�ͣ����� modify = 0;
By Ruby@ES 96'1/27
*/
         else
              player->modify_skill(skill_name[i],  -mod_val );
    }
    player->delete_temp("acup_effect/"+EFFECT_ID);

    tell_object( player,
		"��Ī���ر�����������Ǳ��,��Ī���Ļص����ճ��ߵ�״̬....��\n" );
    
    return ;	
}

