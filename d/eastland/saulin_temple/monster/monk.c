#include "saulin_monkb.c"

void create()
{
	::create();
	set_level(12);
	set_name( "damo monk", "��Ħ�ú��º���" );
	add( "id", ({ "monk" }) );
	set_short( "��Ħ�ú��º���" );
	set_long( @LONG
��Ħ���������ر���\��\��ݵĺ�������ĵط�... ���Ǵ�������,
��������, ����\��\���ǰ���ȡһ��ֻ������һ�����ӱȽϸ�, ��ò�
Ҫ�����ǡ�
LONG
	);
	set("unit", "��" );
	set("race", "human" );
	set("gender", "male" );
	set("alignment",  200 );
	set("max_hp", 442);
	set("hit_points", 442);
	set("max_fp", 250);
	set("force_points", 250);
	set("force_effect",2);
	set("special_defense", ([ "all" : 30, "none" : 20 ]) );
	set("aim_difficulty", ([ "critical" : 45, "vascular" : 35 ]) );
	set_perm_stat( "str", 18 );
	set_perm_stat( "dex", 19 );
	set_perm_stat( "int", 17 );
	set_perm_stat( "pie", 18 );
	set_skill( "dodge", 90 );
	set_skill( "unarmed",80);
	set( "wealth/gold", 25 );
	set( "pursuing", 1 );
	set_natural_armor( 65, 20 );
	set_natural_weapon( 25, 14, 29 );
	set("attack_skill",CLASS"keep_flower");
	set("monk_gonfu/keep-flower",10);
	equip_armor( SAULIN_OBJ"ring4" );
}
