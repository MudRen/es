#include <mudlib.h>
inherit ARMOR;

void create()
{
	if ( clonep(this_object()) ) {
        set_default_ob(__FILE__);
        return;
	}
        set_name( "gold head","����ͷ��");
        add( "id", ({ "head" }) );
        set_short("Gold head", "����ͷ��");
        set_long(@AAA
����һ���ù��ؽ���������ɵ�ͷ�����ṩ���ܵı�����
AAA
        );
        set( "unit", "��"); 
        set( "type", "head" );
        set( "armor_class", 10 );
        set("material","heavy_metal");
	set( "weight", 35 );
        set( "value", ({ 1000, "silver" }) );
}
