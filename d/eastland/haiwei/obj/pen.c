#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "judge-pen", "�йٱ�" );
	add( "id", ({ "pen" }) );
	set_short( "�йٱ�" );
	set_long( "����һ֦�������йٱʡ�\n");
	set( "unit", "֦" );
	set( "type", "thrusting" );
	set( "weapon_class", 22 );
	set( "min_damage", 8 );
	set( "max_damage", 18 );
	set( "weight", 50 );
	set( "second", 1 );
	set( "value", ({ 440, "silver" }) );
	set_c_verbs( ({ "��%s��%s��ֱ����", "%sб��%s", "%s��%sһ��",
		"��%s���һƲ��˳�ƹ���%s", "%s���һ�£�������%sֱ����ȥ",
		"%s�ʷ�һ����ת��%s", "%s�Ṵ%s" }) );
}
