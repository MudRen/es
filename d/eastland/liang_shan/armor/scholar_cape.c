#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("scholar cape", "��ʦ����");
        add( "id", ({ "cloak","cape" }) );
        set_short("scholar cape","��ʦ����");
        set_long(
                "This is a cape for great scholars only.\n",
                "����һ����ʽ�߹ŵĳ��ۣ�����д��һЩ����������������֣�\n"
        );
        set("unit","��");
        set( "type", "cloak" );
        set( "material", "scholar" );
        set( "armor_class", 6 );
        set( "defense_bonus", 10 );
        set( "special_defense",(["evil":-3,"cold":-10,"fire":2,"divine":4 ]) );
        set( "weight", 70 );
        set( "value", ({ 1375, "silver" }) );
        set( "extra_skills",(["inner-force":10]));
}