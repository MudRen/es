#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
    set_name("ring of cat eye","è��ʯָ��");
    add("id",({"ring"}) );
    set_short("è��ʯָ��");
	set_long(@C_LONG
è��ʯ��һ�ֻ���������任ɫ�ʵı�ʯ, 
�������ɵ�ָ���ܰ��˴���������
C_LONG
 	        );
	set( "unit", "ֻ" );
	set( "weight", 10 );
        set("material","stone");
	set( "type", "finger" );
	set( "armor_class", 0 );
	set( "defense_bonus", 4 );
	set( "value", ({ 100, "gold" }) );
}
