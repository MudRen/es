
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	
	::create();
	set_level(4);
	set_name( "Dwarf child", "����С��" );
	add ("id", ({ "child", "dwarf", }) );
	set_short( "Dwarf child", "����С��" );
	set_long(
	"   \n",
    "����ע����ʱ����ͻȻ��ͷ������������\n");

    set( "alignment",-10);
    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "��" );
	set_perm_stat( "str", 5 );
	set ("wealth", ([ "silver": 5 ]) );
	set_natural_weapon(2,1,4);
	set_natural_armor(20,0);
    set("weight", 200);
	wield_weapon(Weapon"/shortsword01");
}
