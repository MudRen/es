#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("small gold amulet", "�ƽ���Ƭ");
        add( "id", ({ "amulet" }) );
        set_short( "�ƽ���Ƭ");
        set_long(
                " һ���ؾ�����Ϊ������������֮�õĻƽ���Ƭ��\n"
        );
        set("unit","��");
        set( "type", "misc" );
        set("material", "light_metal") ;
        set( "armor_class", 0 );
        set( "defense_bonus", 2 );
        set( "weight", 5 );
        set( "value", ({ 5, "gold" }) );
}



