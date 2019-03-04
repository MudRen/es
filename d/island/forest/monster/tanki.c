#include "../tsunami.h"

inherit HOME+"magic";
inherit MONSTER;

void create()
{
    ::create();
    set_level(18);
    set_name( "Prince Tanki", "���");
    add( "id",({"tanki","prince"}) );
    set_short( "��ػ���");
    set_long(@C_LONG
������������ҵĵ�һ���ӣ�Ҳ����λ�̳��ˣ���Ȼ��λ�Ӹ�λ����������ȴ��
�����º͡�Ŀǰ����Ŭ����ѧϰǹ������ɲ�Ҫȥ������Ŷ����һ�����񣬲�С�Ľ�
ǹ�����������к��������ǿ��Ǻ�ʹ��Ŷ��
C_LONG
            );
    set_perm_stat("str",20);
    set_perm_stat("dex",20);
    set_perm_stat("pie",16);
    set("unit","λ");
    set("race","daemon");
    set("class","knight");
    set("age",20);
    set("gender","male" );
    set("alignment",100);
    set("weight",500);
    set("wealth/gold",200);
    set("hit_points",600);
    set("max_hp",600);
    set("aim_difficulty",
    (["critical":10,"weakest":50,"ganglion":60,"vascular":100]) );
    set("special_defense",(["evil":70,"electric":30,"fire":50,"cold":50,
                            "energy":50,"none":30]) );
    set_skill("jousting",100);
    set_skill("block",70);
    set_skill("tactic",100);
    set("tactic","melee");
    set("tactic_func","my_tactic");
    set_natural_armor(40,35);
    set_natural_weapon(30,10,15);
    set("exp_reward",24000);   
   
    wield_weapon(TWEP"key");
    equip_armor(TOBJ"headband");
    equip_armor(TOBJ"cloth");
    equip_armor(TOBJ"feet");
    equip_armor(TOBJ"gloves1");
    
}

int my_tactic()
{
        string *envname ;
	object victim, *usr, who,env;

     if( (int)this_object()->query("hit_points") >= 120 ) return 0;	
        if( random(100)>15 || !victim = query_attacker() ) return 0;
	usr = users();
	who = usr[ random( sizeof(usr)-1 )];
        env = environment(who) ;
     if(!env) return 0 ;
        envname = explode(base_name(env),"/") ;

     if((envname[0] != "d")|| !environment(who)->query("outside")) return 0 ;
            
     if( wizardp(who) || who == victim ) return 0;
     if( (string)victim->query("class")!="knight"){
	             tell_object( victim, 
	    "\n���ͦ��������Կ����һָ����Ƭ����˲�佫������������!!\n\n");
     	             tell_room( environment(this_object()),
     	    "\n���ͦ��������Կ�� "+victim->query("c_name")+" һָ�����˾ͷ�����ȥ��!!\n\n"
		 ,victim );
          victim->move_player( environment(who),"SNEAK" );	
        tell_object( victim,"\nͻȻ������ʧ�ˣ���ˤ�������������������������\n");
	tell_room( environment(victim), 
		  "\nͻȻ���ˡ����ˡ��䡹һ����"+victim->query("c_name")+"���ص�ˤ�����ǰ����\n\n"
		,victim );
	  victim->receive_spevial_damage("none",50);
          report(this_object(),victim);
	return 1;
	}
        else{
        tell_object( victim,
        "\nͻȻ�䣬���ͦ��������Կ����׼�Ĵ������ҪѨ����е�����ֵֹ�....\n\n");
        tell_room( environment(victim),
        "\nͻȻ�䣬���ͦ��������Կ����׼�Ĵ��� "+victim->query("c_name")+" ������ɫ���̴��...\n\n"
        , victim );
        victim->add("medication_resistance",100);
        return 1;
        }
}

void die()
{
    object killer;
    killer = query("last_attacker");
    killer->set_temp("get_key",1);
    ::die();
    return;
}
