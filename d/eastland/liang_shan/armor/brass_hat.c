#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("brass dauist hat", "��ͭ����");
        add( "id", ({ "hat" }) );
        set_short( "brass dauist hat", "��ͭ����");
        set_long(
                "A brass hat 6used by dauists .\n",
                "ÿ����ʿͷ�϶��е�װ�������֪��û�з������ܣ� \n"
        );
        set("unit","��");
        set( "type", "head" );
        set( "material", "light_metal");
        set( "armor_class", 4 );
        set( "defense_bonus", 1 );
        set( "special_defense",
               ([ "evil":5, "divine":-4, "mental":5 ]) );
        set( "weight", 60 );
        set( "value", ({ 22, "gold" }) );
}



