#include <mudlib.h> 
inherit ARMOR;

void create()
{
        set_name("headband", "��ʤͷ��");
        set_short("a headband", "��ʤͷ��");
        set_long(
                "A cloth headband .\n",
    "����һ�������޵�Ƥ�ױ�ɵĺ�ͷ����һ�㶼�ǽ�������ͷ����������ʤ���� \n"
    "�����沼����ˮ�ͻҳ������л�ɫ��ϸɳ�� \n"
        );
        set("unit","��");
        set( "type", "head" );
        set( "material", "leather");
        set( "armor_class", 6 );
        set( "defense_bonus", 0 );
        set( "special_defense",
               ([ "fire":1, "cold":1, "electric":-2 ]) );
        set( "weight", 45 );
        set( "value", ({ 100, "gold" }) );
}



