#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("red pants","��̿�");
        add("id",({"pants"}) );
        set_short("��̿�");
        set_long(
"����һ����ɫ�Ķ̿㣬ͨ���ھ���ֻ��ʿ�ٺ��ܱ����ܴ���\n"
        );
        set( "unit", "��" );
        set( "weight", 30 );
        set( "type", "legs" );
        set( "material", "cloth" );
        set( "armor_class", 3 );
        set( "defense_bonus", 0 );
        set( "value", ({ 50, "silver" }) );
}
