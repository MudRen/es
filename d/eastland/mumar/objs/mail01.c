#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("highsteel scales","����ۼ�");
        add("id",({"scales"}) );
        set_short("����ۼ�");
        set_long(
"����һ���ۼף�������һƬһƬ��ɫ�ĸ�����Ƭ��\n"
        );
        set( "unit", "��" );
        set( "weight", 200 );
        set( "type", "body" );
        set( "material", "heavy_metal" );
        set( "armor_class", 20 );
        set( "defense_bonus", 0 );
        set( "value", ({ 700, "silver" }) );
}
