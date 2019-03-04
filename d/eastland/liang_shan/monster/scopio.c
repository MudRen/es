#include "../takeda.h"
#include "/include/move.h"
#include "conditions.h"
#include "stats.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name( "Red scorpion", "���Ы" );
	add ("id", ({ "scorpion" }) );
	set_short( "scorpion","���Ы");
	set("unit","β");
	set_long("",
	   "�㿴��һβ�ǳ������ľ޴��ʺ�Ы�ӣ�����ı��泤�������ļ�ͻ\n"
	   "����������£��ƺ���һ��а�����ڡ�\n"
	   
	);
	set( "likefish",1);
	set( "unbleeding",1);
	set("alignment",-1000);
	set_perm_stat("str", 15);
	set_perm_stat("dex", 25);
	set_perm_stat("kar",18);
	set( "aggressive", 1 );
	set( "forgetful", 1 );
	set( "time_to_heal", 8 );
	set_natural_weapon( 25, 10, 18 );
	set_natural_armor( 45, 20 );
	set ("tactic_func","poison");
	set ("race", "monster");
	set_c_limbs(({"Ыβ","Ы��","β��","����"}));
	set_c_verbs( ({"%s����˫ǯϮ��%s","%s��β��%s���ݺ���¡�"}));
}

void die()
{  
   object ob1,killer;
   
   ob1 = new(TWEAPON"scor_whip");
   killer = query("last_attacker");
   if( !killer ) {
     ::die();
     return;
   }
   tell_room(environment(this_object()),
      "\n�������һ�������˴��Ы������β������������һ��\n\n\n\n"
      "�㿴�˾���ʮ�ֿɰ���˳�ְ�����β�͸��������档\n"
      ,this_object() );
   if( (int)(ob1->move(killer)) != MOVE_OK )
		ob1->move(environment(this_object()));  
   ::die();   
}


int poison()
{
	object victim;

	if( random(20)>4 || !(victim = query_attacker()) ) return 0;
	tell_object( victim, 
		"��Ы��βһ˦��׼ȷ������������\n" );
	tell_room( environment(this_object()), 
		"��Ы��Ыβ���" + victim->query("c_name") + "������\n",
		({ this_object(), victim }) );
	(CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 10, 10 );
	return 1;
}
