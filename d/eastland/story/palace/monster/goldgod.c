#include "../../story.h"
#include "../../magic.c"
#include <ansi.h>
inherit MONSTER ;

void create ()
{
	::create();
	set_level(19);
	set_name( "The Gold-God Ru", "����" );
	add ("id", ({"the god-god ru","ru","Ru"}) );
	set_short( "��������");
	set_long(@CLONG
����ȫ�������Ҳ�Ƶģ�һ���۾�����ͭ�壬��ò�������ǡ�����ԭ�Ǹ�������
����껵ģ��ƹ����ļ��е����졣�����������������е����𣬲�����Щ���丽
��֮˵��һ�����������ܻ�Ƹ�������	
CLONG
	);
	set("race","god");
	set("gender","male");
	set_perm_stat("str", 28 );
        set_perm_stat("dex", 25 );
        set_perm_stat("kar", 20 );
        set_perm_stat("int", 27 );
	set( "alignment", 500 );
	set( "hit_points", 1500 );
	set( "max_hp", 1500 );
        set( "spell_points",100);
        set( "max_fp",500);
	set_natural_weapon( 18, 14, 21 );
        set_natural_weapon2( 38, 23, 35 );
	set_natural_armor( 70, 52 );
        set("aim_difficulty",([ 
    	  "critical":50,"vascular":50,"weakest":50 ]) );
        set("wealth/gold",400);
        set("stun_difficulty",100);
        set_skill("block",100);
        set_skill("two-weapon",100);
        set_temp("detect_invi",1);
        set_skill("parry",100);
        set_skill("thrusting",100);
        set_skill("chain",100);
        set("tactic_func","my_tactic");
        wield_weapon(SPWEA"ruler");
        equip_armor(SPARM"goldgod_shield");
        wield_weapon2(SPWEA"chain");
        set("special_defense",(["all":50,"none":30]));
}
int my_tactic()
{
    object victim;
    if ( !victim=query_attacker() ) return 0;
    if ( random(18) > 1 ) return 0;
    tell_room(environment(),
      "�������е����߲�ͣ����ת�����һ�������Ĺ�Ȧ���������\n",victim);
    tell_object(victim,
      "\n�������е����߲�ͣ����ת�����һ�������Ĺ�Ȧ ...\n\n���Ź�Ȧ��Ȼ��������ɺ����������ȫ��!��\n\n\n");
    tell_object(this_object(),sprintf(
      "\n�����е����߲�ͣ����ת�����һ�������Ĺ�Ȧ ...\n���Ź�Ȧ����%s��������ɺ���!��\n\n\n"
      ,victim->query("c_name")));
    victim->receive_special_damage("energy",40+random(10));
    report( this_object(), victim );
    return 1;
}
void die()
{
   int i,max;
   object env, *atk;
   env=environment();
   atk=all_inventory(env);
   max=sizeof(atk);
   tell_room(environment(),"��������ǰ��������Ķ������������Щ�˻��ܵ�����ģ�\n");
   for ( i=0;i<max;i++ ) 
      if ( userp(atk[i]) ) 
         damn_player(atk[i]);
   ::die();
}
