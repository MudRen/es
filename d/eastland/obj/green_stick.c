#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "green stick", "�����" );
	add( "id", ({ "stick" }) );
   set_short( "�����" );
	set_long(
		"�㿴��һ��ϸϸ����������ɫ�����\n"
	);
	set( "unit", "��" );
	set( "weight", 20 );
   setup_weapon( "bo", 3, 4, 6 );
	set( "value", ({ 5, "silver" }) );
}
