#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "ninja clothes", "������");
        add( "id", ({ "ninja","clothes"}) );
        set_short("ninja clothes", "������");
        set_long(@AAA
һ�������Ǵ��ķ����£����ü���Ĳ������ɵģ��Է����˵��ж���ֻ
�����Ҳ�����˷�����        
AAA
        );
        set( "unit", "��"); 
        set( "type", "body" );
        set( "armor_class", 16 );
        set( "defense_bonus", 2 );
        set("material","leather");
        set( "weight", 90 );
        set( "value", ({ 760, "silver" }) );
}
