#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("sable cape", "����Ƥ��");
        add( "id", ({ "cloak","cape" }) );
        set_short("sable cape","����Ƥ��");
        set_long(
                "This is a cape made of fur of sable.\n",
                "�����ڳ���ɽ�Եõ��Ϻ���Ƥ���ɵ�Ƥ�������ɫ������ë��\n"
                "����ĽŲ�ҡҷ���������൱���磮���ǵ�С�ı���������ʿ͵Ϯ�㣮\n"
        );
        set("unit","��");
        set( "type", "cloak" );
        set( "material", "leather" );
        set( "armor_class", 6 );
        set( "defense_bonus", 1 );
        set( "special_defense",([ "evil":2, "fire":-4, "cold":2 ]) );
        set( "weight", 80 );
        set( "value", ({ 999, "silver" }) );
}