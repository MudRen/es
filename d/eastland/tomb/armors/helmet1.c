#include "../almuhara.h"

inherit ARMOR;

void create()
{
        set_name("Holy helmet", "��ħʥ��");
        add( "id", ({ "helmet" }) );
        set_short( "��ħʥ��");
        set_long(
        "������ĳ������������Ƴɵ�ͷ�������Ա��������а����˵Ĺ����� \n"
                
        );
        set("unit","��");
        set( "type", "head" );
        set( "material", "light_metal" );
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "special_defense", ([ "evil" : 5 ]) );
        set( "weight", 60 );
        set( "value", ({ 1800, "silver" }) );
}



