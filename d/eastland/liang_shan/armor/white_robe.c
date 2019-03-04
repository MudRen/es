#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("milky cape", "��ס�˿ս��");
        add( "id", ({ "cloak","cape" }) );
        set_short("milky cape","��ס�˿����");
        set_long(
                "This is a milky cape for fighters\n",
                "����һ�����ɫ��ս�ۣ�������ƽƽ������\n"
        );
        set("unit","��");
        set( "type", "cloak" );
        set( "material", "cloth" );
        set( "armor_class", 4 );
        set( "defense_bonus", 2 );
        set( "special_defense",(["none":3,"divine":2 ]) );
        set( "weight", 80 );
        set( "value", ({ 675, "silver" }) );
        set( "extra_skills",(["dodge":10]));
}