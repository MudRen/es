
#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("fighters' cloth","�಼�̴�");
        add("id",({"cloth"}) );
         set_short("�಼�̴�");
        set_long(
"����һ����ר�õ��·����������������... ֻ���������ѡ�\n"
        );
        set( "unit", "��" );
        set( "weight", 70 );
        set( "type", "body" );
        set( "material", "cloth" );
        set( "armor_class", 8 );
        set( "defense_bonus", 0 );
	set( "special_defense", ([ "mental":2, "fire":-2, "acid":-2 ]) );
        set( "value", ({ 120, "silver" }) );
}
