#include <mudlib.h>
#include "../camp.h"
inherit MONSTER;

void create()
{
	::create();
	set_level(2);
	set_name( "sheet", "ֽ��" );
	add( "id", ({ "sheet" }) );
	set_short( "ֽ��" );
	set_long(
		"�㿴��һ��ȫ����¡��������磬��ٲ��塢���ޱ���Ķ�����\n"
	);
   set( "race", "undead" );
   set( "unbleeding", 1);
   set( "exp_reward",300) ;
   set( "aim_difficulty", ([
     "ganglion" : 100, "vascular" : 100 ]) );
	set( "gender", "female" );
	set( "alignment", -100 );
	set_perm_stat( "str", 5 );
	set_perm_stat( "dex", 5 );
	set_skill( "dodge", 20 );
	set( "natural_armor_class", 10 );
	set( "natural_weapon_class1", 5 );
	set( "natural_min_damage1", 3 );
	set( "natural_max_damage1", 5 );
	set( "alt_corpse", CAMPOBJ"paper" );
	set_c_verbs( ({"%sΧ��ȦȦ��ѹ��%s"}) );
}

void die()
{
   tell_room( environment(this_object()), 
   query("c_name") + "����һ�ɰ��̣���ʧ��....�㿴��ĳ���������ڵذ��ϡ�\n",
      this_object() );
   ::die(1);
}
