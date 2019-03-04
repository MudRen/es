
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(7);
	set_name( "believer", "��ͽ" );
	add ("id", ({ "dwarf", }) );
	set_short( "Yang's believer", "Yang ����ͽ" );
	set_long(
	"   \n",
    "һ����������ͽ,�ƺ����������õ�����Yang��ף��\n");

    set("alignment", 100 );
    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "��" );
	set_perm_stat( "str", 10 );
	set_perm_stat( "int", 15 );
	set_perm_stat( "kar", 10 );
	set ("wealth", ([ "silver": 200 ]) );
	set_natural_weapon(12,13,18);
	set_natural_armor(33,0);
    set ("weight", 300);
    set_skill("unarmed",50);
    set_skill("dodge",40);
    
	equip_armor(Armour"/cloth03");
}
