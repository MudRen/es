#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("buddha hood", "���ޡ��ֶ���");
        add( "id", ({ "hood" }) );
        set_short( "buddha hood", "���ޡ��ֶ���");
        set_long(
                "A hood with a buddha mark .\n",
                "����һ����ɴ������һ����ɫ�ġ��֣���˵����ѹ�����ڷ��� \n"
                "���ԣ������ν��صؽ����͸����ӣ�\n"
        );
        set("unit","��");
        set( "type", "head" );
        set( "material", "cloth");
        set( "armor_class", 6 );
        set( "defense_bonus", 3 );
        set( "special_defense",
               ([ "evil":7,"mental":5 ]) );
        set( "weight", 60 );
        set( "value", ({ 300, "gold" }) );
}


