#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("fur armband", "��ţƤ�ۻ�");
        add( "id", ({ "armband" }) );
        set_short( "fur armband", "��ţƤ�ۻ�");
        set_long(
                "A fur armband .\n",
                "һ����ţƤ���Ƶıۻ��� \n"
        );
        set("unit","��");
        set( "type", "arms" );
        set( "material", "adventurer");
        set( "armor_class", 5 );
        set( "defense_bonus", 3 );
        set( "special_defense",
               ([ "cold":-10]) );
        set( "weight", 40 );
        set( "value", ({ 66, "gold" }) );
        set( "extra_stats",(["str":-1,"con":-1]));
        set( "extra_skills",(["bandage":15,"whip":20]));
}



