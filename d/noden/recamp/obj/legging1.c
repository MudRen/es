#include <mudlib.h>
inherit ARMOR;

void create()
{
	if ( clonep(this_object()) ) {
        set_default_ob(__FILE__);
        return;
	}
        set_name( "gold legging","��ϥ");
        add( "id", ({ "legging" }) );
        set_short("Gold legging", "��ϥ");
        set_long(@AAA
����һ���ù��ؽ���������ɵĽ�ϥ���ṩ���ܵı�����
AAA
        );
        set( "unit", "��"); 
        set( "type", "legs" );
        set( "armor_class", 5 );
        set("material","heavy_metal");
	set( "weight", 50 );
        set( "value", ({ 500, "silver" }) );
}
