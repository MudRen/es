#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("suntsu", "���ӱ���");
        add( "id", ({ "book" }) );
        set_short("���ӱ���");
        set_long(
                "����������������ӱ������õ����ͻ�ӵ�а����֮��...\n"
        );
        set( "unit", "��");
        set( "type", "misc" );
        set( "material", "scholar");
        set( "armor_class", 0);
        set( "defense_bonus", 6 );
        set( "special_defense",
             ([ "mental":6, "none":-6 ]) );
        set( "weight", 30 );
        set( "value", ({ 1470, "silver" }) );
        set( "extra_skills",(["tactic":10]));
}
