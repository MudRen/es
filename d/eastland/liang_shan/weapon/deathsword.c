#include "takeda.h"

inherit WEAPON;

void create()
{
       set_name("death sword","ɥ�Ž�");
       add("id",({"sword"}) );
       set_short("ɥ�Ž�");
	   set_long(
           "����һ�ѷ����ı������������׵Ķ�ȥ��������������ɥ�ţ�\n"
	);
	
	set( "unit", "��" );
 	set( "weapon_class", 26 );
        set("type","longblade");
	set( "min_damage", 18 );
	set( "max_damage", 29 );
	set( "weight", 100 );
	set( "value", ({ 81, "gold" }) );
	
}	
