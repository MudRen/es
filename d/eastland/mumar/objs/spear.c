#include <mudlib.h>
inherit WEAPON;
 
void create()
{
        set_name("snake spear", "��ì");
        add ("id",({ "spear" }) );
        set_short("��ì");
        set_long(
            "һ֧��ì��ìͷ���߰��������ݷ�Ҫ���ɵ��ˡ�\n"
        );
        set( "unit", "֧" );
        set( "weapon_class", 17 );
        set( "type", "thrusting" );
        set( "min_damage", 8 );
        set( "max_damage", 18 );
        set( "weight", 190 );
        set( "value", ({ 500, "silver" }) );
}
