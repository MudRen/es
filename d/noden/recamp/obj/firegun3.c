#include <mudlib.h>
inherit WEAPON;

void create()
{
	if ( clonep(this_object()) ) {
        set_default_ob(__FILE__);
        return;
	}
  set_name("fire gun", "���ǹ");
  add("id", ({"fire gun","gun"}) );
  set_short("fire gun","���ǹ");
  set_long(
   "һ�������ǹ��\n"
  );
  set( "unit", "��" );
  set( "weapon_class", 45 );
  set( "type","polearm");
  set( "min_damage", 15 );
  set( "max_damage", 25 );
  set( "weight", 100 );
  set( "value", ({ 1000, "silver" }) );
}
