#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("thunder cape", "�������Ļ���");
        add( "id", ({ "cloak","cape" }) );
        set_short("thunder cape","�������Ļ���");
        set_long(
                "This is a cape that can avoid thunder...\n",
                "����һ����ɫ�ĵ��ۣ�����д��һЩ����ķ�������˵����ʤ\n"
                "���绽��ʱ�ض��ᴩ������������͵ķ��ۣ��Ա������������Լ���\n"
        );
        set("unit","��");
        set( "type", "cloak" );
        set( "material", "mage" );
        set( "armor_class", 7 );
        set( "defense_bonus", 10 );
        set( "special_defense",(["electric":20 ]) );
        set( "weight", 70 );
        set( "value", ({ 1275, "silver" }) );
}