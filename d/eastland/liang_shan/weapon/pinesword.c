#include "takeda.h"

inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("pine sword","���ĹŶ���");
       add("id",({"sword","pinesword",}) );
       set_short("���ĹŶ���");
	   set_long(
           "һ�����������������ƵĹŴ�ľ��������ƺ��൱��Զ��\n"
	);
	
	set( "unit", "��" );
 	set( "weapon_class", 35 );
        set("type","longblade");
	set( "min_damage", 20 );
	set( "max_damage", 35 );
	set( "weight", 80 );
	set( "value", ({ 510, "gold" }) );
}
