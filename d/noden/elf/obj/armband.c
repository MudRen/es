#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("elven armband", "����ۻ�");
        add( "id", ({ "armband" }) );
        set_short( "����ۻ�" );
        set_long(
                "���Ǿ��鳤���ö����޵Ķ�����ĥ�Ƴɵıۻ��������������صı�����â�� \n"
        );
        set( "unit", "˫");
        set( "type", "arms" );
        set( "material", "wood");
        set( "armor_class", 2 );
        set( "defense_bonus", 4 );
        set( "special_defense",
               ([ "mental":7, "evil":-3, "fire":-1, "poison":-2 ]) );
        set( "weight", 30 );
        set( "value", ({ 1800, "silver" }) );
}
