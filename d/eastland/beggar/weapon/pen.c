#include "../dony.h"

inherit WEAPON;

void create()
{
	set_name( "judge pen", "�йٱ�" );
	add( "id", ({ "pen","judge" }) );
	set_short( "�йٱ�" );
	set_long( "����һ֦�������йٱʡ�\n");
	set( "unit", "֦" );
	setup_weapon("thrusting",30,15,30);
	set( "weight", 30 );
	set( "second", 1 );
	set( "value", ({ 1140, "silver" }) );
	set_c_verbs( ({ "��%s��%s��ֱ����", "%sб��%s", "%s��%sһ��",
		"��%s���һƲ, ˳�ƹ���%s", "%s���һ��, ������%sֱ����ȥ",
		"%s�ʷ�һ��, ת��%s", "%s�Ṵ%s","%s��%sһ��" 
		}) );
}
