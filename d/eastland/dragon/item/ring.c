#include "../../layuter.h"
inherit ARMOR;

void create()
{
        set_name("occult ring", "���ؽ�ָ");
        add( "id", ({ "ring" }) );
        set_short("���ؽ�ָ");
        set_long(
                "���������������е�����ʩ�����صĽ������ƳɵĽ�ָ��\n"
        );
	set("unit","ֻ");
        set( "type", "finger" );
        set( "material" ,"light_metal" );
        set( "armor_class", 0 );
        set( "defense_bonus", 7 );
	set("special_defense",(["fire" :3,"cold":3,"divine":-4]));
        set( "weight", 20 );
        set( "value", ({ 500, "gold" }) );
}