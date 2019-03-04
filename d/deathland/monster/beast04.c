#include "../echobomber.h"

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
    
	::create();
	set_level(10);
	set_name( "Hand of Underswamp", "�����µ�ħ��" );
	add("id",({"hand"}));
	set_short( "�����µ�ħ��" );
	set_long(
		"���������µ��������, ��ʱ�������������������������ȥ.\n"
	);
	set( "alignment",-500 );
	set_perm_stat( "dex", 17 );
	set_perm_stat( "str", 11 );
	set_perm_stat( "kar", 16 );
        set_natural_armor(45,5);
 	set_natural_weapon(20,11,28);
    set( "special_defense", (  [ "all":40 , "none": 35 ]  ) );
    set ("aim_difficulty",([ "critical":40 ]) );
    set ("unbleeding",1);
    set ("killer",1);
	
	set("speed",10);
	set_c_limbs( ({  "��" }) );
	set_c_verbs( ({ "%s����������%s׽ȥ" }) );
    
}
