#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("holy robe", "ʥ��");
        add( "id", ({ "robe" }) );
        set_short( "ʥ��");
        set_long(
              "����һ������ؾ���ʥ�����ķ��ۡ������·�����ҫ����ɫ�ķ��š� \n"
        );
        set("unit","��");
        set( "type", "body" );
        set("material","cloth");
        set( "armor_class", 40 );
        set( "defense_bonus", 7 );
        set("special_defense",
              (["fire":30,"cold":30,"evil":30]) );
        set( "weight", 170 );
        set( "value", ({ 270, "gold" }) );
}
