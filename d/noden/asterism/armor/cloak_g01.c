#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("cloak of elder", "���϶���");
        add( "id", ({ "cloak" }) );
        set_short( "���϶���");
        set_long(
                "�ؾ�����Ժ��Ϊʶ��Ķ��\n"
        );
        set("unit","��");
        set( "type", "cloak" );
        set("material","cloth") ;
        set( "armor_class", 8 );
        set( "defense_bonus", 4 );
        set("special_defense",
              (["fire":8,"cold":8,"evil":15,"magic":10]) );
        set( "weight", 90 );
        set( "value", ({ 205, "gold" }) );
}


