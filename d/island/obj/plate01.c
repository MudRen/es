#include "../island.h"

inherit ARMOR;

void create()
{
        set_name("short plate","�����˶̼�");
        add("id",({"plate"}) );
         set_short("�����˶̼�");
	set_long(@LONG
��ͨ�����˰����Ķ̼ף�����ĳ�������Ƴɵġ�
LONG
	);
	set( "unit", "��" );
	set( "weight", 75 );
	set( "type", "body" );
	set( "material", "leather" );
	set( "armor_class", 11 );
	set( "defense_bonus", 3 );
	set( "value", ({ 500, "silver" }) );
}
