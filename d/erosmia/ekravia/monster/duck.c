#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "duck", "Ѽ��" );
	add( "id", ({ "duck" }) );
	set_short( "Ѽ��" );
	set_long(
		"ũ������Ѽ��, �����̶̵Ĳ������ɫ����ë��\n"
	);
	set( "unit", "ֻ" );
	set_c_limbs( ({ "�Ľ�", "ͷ��", "����" }) );
	set_c_verbs( ({ "%s��%sһ��", "%s�����%sײȥ" }) );
}
