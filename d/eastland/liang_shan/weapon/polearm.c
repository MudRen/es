#include "takeda.h"

inherit WEAPON;

void create()
{
       set_name("Chinese halbert","���컭�");
       add("id",({"halbert"}) );
       set_short("���컭�");
	   set_long(
           "������ǹ�ͳ������ɵ��������������ߵ��ŵ㣬���컭�������\n"
	   "����������һ�֣�\n"
	);
	
	set( "unit", "��" );
 	set( "weapon_class", 26 );
    set("type","polearm");
	set( "min_damage", 16 );
	set( "max_damage", 30 );
	set( "nosecond",1);
	set( "weight", 130 );
	set( "value", ({ 90, "gold" }) );
	
}	
