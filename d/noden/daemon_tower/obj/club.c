#include "mudlib.h"

inherit WEAPON;

void create()
{
#include <compress_obj.h>
       set_name("wooden club","��ľ��");
       add("id",({"club",}) );
       set_short("��ľ��");
       set_long(
           "һ������Ƥ����û��Ǭ������ľ��\n"
     	);
	
	set( "unit", "��" );
 	set( "weapon_class", 25 );
	set("type","blunt");
	set( "min_damage", 5 );
	set( "max_damage", 25 );
	set( "weight", 200 );
	set( "value", ({ 1, "gold" }) );
}
