#include <mudlib.h>
inherit ARMOR;

void create()
{
	if ( clonep(this_object()) ) {
        set_default_ob(__FILE__);
        return;
	}
        set_name( "Magic suit", "ħ����װ");
        add( "id", ({ "suit" }) );
        set_short("Magic suit", "ħ����װ");
        set_long(@AAA
����һ�������������������ɵ�ħ����װ����չ�ֳ����˵�������ߡ�
AAA
        );
        set( "unit", "��"); 
        set( "type", "body" );
        set( "armor_class", 10 );
        set( "defense_bonus", 10 );
        set("material","light_metal");
        set("special_defense",(["electric":10,"fire":10,"cold":10])) ;
        set( "weight", 100 );
        set( "value", ({ 1000, "silver" }) );
}
