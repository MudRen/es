#include "../saulin_temple.h"

inherit WEAPON;

void create()
{
    set_name("king-kong thu","�����");
    add("id",({"mace","thu"}) );
    set_short("�����");
    set_long(
		"�ɽ��ɰ�ͺ�������ƳɵĽ����, �ഫ�Ǵ������������ħ�����ķ�����\n"
    );
	set( "unit", "��" );
 	set( "weapon_class", 37 );
	set("type","bo");
	set( "min_damage", 15 );
	set( "max_damage", 38 );
	set( "weight", 230 );
        set( "nosecond",1); 
	set( "value", ({ 200, "gold" }) );
}
