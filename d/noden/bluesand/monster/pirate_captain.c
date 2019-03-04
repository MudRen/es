#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(12);
	set_name( "austard", "��˹��" );
	add( "id", ({ "captain" }) );
   set_short( "��˹������" );
	set_long(
		"��˹�������������˴����ĵܵܣ��������ǵ������Ȼ��ͬ��������Ϊ��\n"
		"����ȥ���˿��̴�����˹����������һ������ͷ�ӡ�\n"
	);
	set( "race", "lizardman" );
	set( "gender", "male" );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 16 );
	set_skill( "longblade", 80 );
	set_skill( "shortblade", 80 );
	set_skill( "two-weapon", 80 );
	set_skill( "parry", 70 );
	set_skill( "dodge", 50 );
	set_skill( "tactic", 80 );
	set( "tactic", "assault" );
	set( "killer", 1 );
	set( "pursuing", 1 );
	set( "wealth/gold", 80 );
	set( "special_defense", ([ "all": 30 ]) );
	set( "alignment", -900 );
	set_natural_armor( 50, 9 );
	set_natural_weapon( 5, 6, 8 );

	wield_weapon( "/d/noden/bluesand/item/creset_cutlass" );
	wield_weapon2( "/d/noden/bluesand/item/hook" );
	equip_armor( "/d/noden/bluesand/item/eye_patch" );
	equip_armor( "/d/noden/bluesand/item/boots" );
}

void die()
{
   object killer, head;

   killer = query("last_attacker");
   if( killer ) killer->set_explore("noden#11");
   ::die(1);
	if ( (string)killer->query("class") == "adventurer" ) {
	   tell_object( killer, set_color(
	        "�����������䵶�Ѱ�˹����ͷһ��ն�£�\n", "CYN", killer) );
	   head = new("/d/noden/bluesand/item/head");
	   head->move(environment(killer));
	}
}
