#include "../../story.h"
inherit WMOB"warmob";

void create()
{
	::create();
	set_level(17);
	set_name( "Troll warrior", "������սʿ" );
	add( "id", ({ "warrior","troll" }) );
	set_short( "������սʿ" );
	set_long(@LONG
һλ���͵ľ�����սʿ����ȫ�����֣�һ˫�����ֵĴ�׳�ֱۣ�����ǧ�ٸ���
�ۡ�
LONG
	);
	set( "unit", "λ" );
	set( "weight",1300);
        set( "race","����");
	set( "gender","male");
	set( "alignment", -500 );
	set_natural_armor(60,30);
	set_natural_weapon(3,4,4);
	set_temp("detect_invi",1);
	set_perm_stat("str",28);
	set_perm_stat("dex",24);
	set_perm_stat("kar",25);
	set_perm_stat("int",10);
	set( "wealth/silver", 500 );
	set( "killer", 1 );
        set( "war_points", 150 );
	equip_armor(WARM"cloth1");
	wield_weapon(WWEA"axe1");
	set_skill( "axe", 100 );
	set_skill( "parry", 100 );
}
