#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("thief ring", "������ָ");
        add( "id", ({ "ring" }) );
        set_short("������ָ");
        set_long(
                "����һֻ������ָ��������˪���İ�֮�\n"
        );
        set("unit","ֻ");
        set( "type", "finger" );
        set( "material", "thief");
        set( "armor_class", 0 );
        set( "defense_bonus", 4 );
        set( "extra_skills", (["sneak":5, "hide":5, "steal":5, "backstab":5]));
        set( "weight", 30 );
        set( "value", ({ 300, "gold" }) );
}
