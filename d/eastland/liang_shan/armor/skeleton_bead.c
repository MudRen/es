#include "takeda.h"

inherit ARMOR;

void create()
{
        set_name("skeleton beads","�˶�������");
        add("id",({"skeleton","beads"}) );
         set_short( "a skeleton beads","�˶�������");
	set_long(
"This is a chain of beads make of skeleton . \n"
"���˶������ɵĴ����飬����ʮ��������������������Ż��Ѫ������\n"
);
	set( "unit", "��" );
	set( "weight", 100 );
	set( "type", "misc" );
	set( "material","stone");
        set( "defense_bonus", 7 );
	set( "no_sale",1);
	set( "value", ({ 250, "gold" }) );
        set( "special_defense",(["evil":-5 ,"divine":7]));
        set( "extra_stats",(["pie":-2]));
}
