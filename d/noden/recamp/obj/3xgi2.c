#include <mudlib.h>
inherit WEAPON;

void create()
{
	if ( clonep(this_object()) ) {
        set_default_ob(__FILE__);
        return;
	}
  set_name("3xgi", "�����");
  add("id", ({"3xgi"}) );
  set_short("3xgi","�����");
  set_long(
   "һ������ꪣ���������ܴ��������õ�˳�֡�\n"
  );
  set( "unit", "��" );
  set( "weapon_class", 30 );
  set( "type","thrusting");
  set( "min_damage", 15 );
  set( "max_damage", 25 );
  set( "weight", 100 );
  set( "value", ({ 1000, "silver" }) );
}
