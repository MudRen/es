#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("fur hat", "����ůñ");
        add( "id", ({ "hat" }) );
        set_short( "fur hat", "����ůñ");
        set_long(
                "A fur hat that can make you feel warm .\n",
                "һ��ë���޵Ĵ�ñ�ӣ�������ʮ�ֱ�ů�� \n"
        );
        set("unit","��");
        set( "type", "head" );
        set( "material", "leather");
        set( "armor_class", 6 );
        set( "defense_bonus", 1 );
        set( "special_defense",
               ([ "cold":4, "fire":-3]) );
        set( "weight", 40 );
        set( "value", ({ 66, "gold" }) );
}



