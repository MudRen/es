#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("beast-face", "��������");
        add( "id", ({ "face" }) );
        set_short("��������");
        set_long(
                "����һ�ֻ��ľ��������������ѣ�����ɽ������廢�������\n"
        );
        set( "unit", "��");
        set( "type", "misc" );
        set( "material", "leather");
        set( "armor_class", 0);
        set( "defense_bonus", 8 );
        set( "special_defense",
             ([ "poison":-5,"none":4 ]) );
        set( "weight", 20 );
        set( "value", ({ 470, "silver" }) );
}
