#include <mudlib.h>
inherit ARMOR;

void create()
{
	if ( clonep(this_object()) ) {
        set_default_ob(__FILE__);
        return;
	}
        set_name( "Wooden plate", "ľ������");
        add( "id", ({ "plate" }) );
        set_short("Wooden plate", "ľ������");
        set_long(@AAA
����һ����ľ�ʱ�֯���ɵ����ף��Ե��൱������Ȥ��
AAA
        );
        set( "unit", "��"); 
        set( "type", "body" );
        set( "armor_class", 30 );
        set( "defense_bonus", 10 );
        set("material","wood");
        set("special_defense",(["electric":15])) ;
        set( "weight", 350 );
        set( "value", ({ 1000, "silver" }) );
}
