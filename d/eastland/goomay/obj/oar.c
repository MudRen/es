#include "mudlib.h"

inherit WEAPON;

void create()
{
       set_name("wooden oar","ľ��");
       add("id",({"oar",}) );
       set_short("wooden oar","ľ��");
       set_long(
           "A oar made by oak.\n",
           "����һ�����Ϻ���ľ���ƶ��ɵĴ�����\n"
     	);
	
	set( "unit", "��" );
 	set( "weapon_class", 25 );
	set("type","blunt");
	set( "min_damage", 10 );
	set( "max_damage", 25 );
	set( "weight", 200 );
	set( "value", ({ 20, "gold" }) );
}
