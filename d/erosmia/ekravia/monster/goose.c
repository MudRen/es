#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "goose", "�׶�" );
	set_short( "�׶�" );
	set_long(
		"��ֻ������һ�����ŵ�������������\n"
	);
	set("unit", "ֻ" );
	set("alignment", 200);
	set_c_limbs( ({ "��Ѿ", "ͷ��", "����", "���" }) );
	set_c_verbs( ({ "%s�ſ������%s�Ĵ�", "%s�����������%s" }) );
}
