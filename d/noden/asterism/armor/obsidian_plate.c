#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("obsidian platemail", "����ʯ����");
        add( "id", ({ "platemail" }) );
        set_short( "����ʯ����");
        set_long(
                "����һ���ɺ���ʯ�Ƶ����С�\n"
        );
        set("unit","��");
        set( "type", "body" );
        set("material","element");
        set( "armor_class", 35 );
        set( "defense_bonus", 5 );
        set( "weight", 330 );
        set( "value", ({ 270, "gold" }) );
}






