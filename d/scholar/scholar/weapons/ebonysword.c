#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "Ebony Sword", "���佣" );
	add( "id", ({ "sword" }) );
	set_short( "Ebony Sword", "���佣" );
	set_long(
		"You see a black longsword with a smell of burning spices.\n",
		"����һ��ͨ���ī��ɫ�Ľ�����ѽ����������⴦һ�գ����ǰ��\n"
		"����Ҳû�У�����īɫһƬ������Լ�����ᵽ����ɢ����һ���հ�\n"
		"�ݵĽ�ζ��\n"
	);
	set( "unit", "��" );
	set( "weight", 60 );
	setup_weapon( "longblade", 30, 24, 30 );
	set( "bleeding", 10 );
	set( "value", ({ 365, "gold" }) );
	set( "no_sale", 1 );
}
