#include "takeda.h"

inherit ARMOR;

void create()
{
        set_name("golden ring","̫ԭ��Ŧ˿��");
        add("id",({"ring"}) );
         set_short( "golden ring","̫ԭ��Ŧ˿��");
	set_long(
"This is a golden ring . \n"
"����̫ԭ�����ز���������½���ο͵�̫ԭ��һ������һ��������\n"
);
	set( "unit", "��" );
	set( "weight", 10 );
	set( "type", "finger" );
	set( "material","adventurer");
	set( "armor_class", 0 );
	set( "defense_bonus", 6 );
	set( "value", ({ 150, "gold" }) );
        set( "extra_skills",(["whip":10]));
}
