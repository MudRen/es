#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("nail cape", "���Ǵ�������");
        add( "id", ({ "cloak","cape" }) );
        set_short("nail cape","���Ǵ�������");
        set_long(
                "This is cape with some nails on it.\n",
                "����һ�����Ļ��ۣ�һ��Ҳ��������ж������涤��Щװ�εĶ��ӣ�\n"
        );
        set("unit","��");
        set( "type", "cloak" );
        set( "material", "cloth" );
        set( "armor_class", 5 );
        set( "defense_bonus", 4 );
        set( "special_defense",(["none":3,"divine":2 ]) );
        set( "weight", 70 );
        set( "value", ({ 890, "silver" }) );
        set( "extra_skills",(["dodge":10]));
}