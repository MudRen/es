
#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("ice demon's amulet","��ħ��");
        add("id",({"amulet"}) );
         set_short("��ħ��");
        set_long(
"����һ����ɫ�Ļ��������������ȴ�����˰߰�Ѫ�����Եúܹ��졣\n"
        );
        set( "no_sale",1);
        set( "unit", "��" );
        set( "weight", 10 );
        set( "type", "misc" );
        set( "material", "element" );
        set( "armor_class", 0 );
	set( "defense_bonus", 5 );
        set( "special_defense", ([ "ice":8, "fire":-10 ]) );
        set( "value", ({ 88, "gold" }) );
}
