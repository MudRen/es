
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	
	::create();
	set_level(5);
	set_name( "Dwarf older", "��������" );
	add ("id", ({ "older", "dwarf", }) );
	set_short( "Dwarf older", "��������" );
	set_long(
    "һ���ϰ���,����\����ʱ���Ǹ�սʿ,����������ֻ��ƽƽ�����Ļ���\n"
     );
    set("alignment",0);
    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "��" );
	set_perm_stat( "str", 7 );
	set ("wealth", ([ "silver": 100 ]) );
	set_natural_weapon(4,2,6);
	set_natural_armor(26,0);
    set ("weight", 300);
	wield_weapon(Weapon"/stick01");
}
