#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("wool hat", "�׷���ձ��ñ");
        add( "id", ({ "hat" }) );
        set_short( "wool hat", "�׷���ձ��ñ");
        set_long(
                "A white wool hat that can make you feel warm .\n",
                "һ����ɫë���޵Ĵ�ñ�ӣ�������ʮ�ֱ�ů�� \n"
        );
        set("unit","��");
        set( "type", "head" );
        set( "material", "leather");
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "cold":3, "fire":-3]) );
        set( "weight", 35 );
        set( "value", ({ 56, "gold" }) );
}



