
#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("fish-scale suit","��Ƥս��");
        add("id",({"suit"}) );
         set_short("��Ƥս��");
        set_long(
"����һ�������⴦�������Ƥ�ƳɵĽ���ս�ף������õķ�������\n"
        );
        set( "unit", "��" );
        set( "weight", 220 );
        set( "type", "body" );
        set( "material", "leather" );
	set( "armor_class", 20 );
	set( "defense_bonus", 0 );
        set( "value", ({ 87, "gold" }) );
}
