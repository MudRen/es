#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("vest","����");
        add("id",({"vest","cloth"}) );
        set_short("����");
        set_long(
"����һ�����ģ�ͨ���Ǽ��ⷢ����������ּ����õġ�\n"
        );
        set( "unit", "��" );
        set( "weight", 70 );
        set( "type", "body" );
        set( "material", "cloth" );
        set( "armor_class", 10 );
        set( "defense_bonus", 1);
        set( "value", ({ 350, "silver" }) );
}
