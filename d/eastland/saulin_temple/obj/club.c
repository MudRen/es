#include "../saulin_temple.h"

inherit WEAPON;

void create()
{
   set_name("Club","��ü��");
   add("id",({ "staff", }) );
   set_short("��ü��");
   set_long(
       "����ɮ���õġ��Ƶ���ü����\n"
   	);
	set( "unit", "��" );
 	set( "weapon_class", 10 );
	set( "type", "bo");
	set( "min_damage", 8 );
	set( "max_damage", 15 );
	set( "weight", 45 );
	set( "value", ({ 250, "silver" }) );
}
