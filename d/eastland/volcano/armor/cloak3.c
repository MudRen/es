#include "../oldcat.h"

inherit ARMOR;

void create()
{
	set_name( "warrior's cloak", "���߶���" );
	add( "id", ({ "cloak" }) );
	set_short( "���߶���" );
	set_long( 
    @LONG
����һ���Ŵ������������Ķ�����������������֣�մ���˵��˵�Ѫ����
LONG
	);
	set( "unit", "��" );
	set( "type", "cloak" );
	set( "material", "cloth");
	set( "armor_class", 8 );
	set( "defense_bonus", 0 );
	set( "special_defense", ([
	  "energy" : 10, "electric" : -5 ])
    );
	set( "weight", 50 );
	set( "value", ({ 1500, "silver" }) );
}
