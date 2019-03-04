#include <mudlib.h>

inherit MONSTER;
inherit MOUNT;

void create()
{
	::create();
	set_level(6);
	set_name( "mini horse", "������" );
	add( "id", ({ "horse" }) );
	set_short( "������" );
	set_long(
		"����һƥ�ɰ������������������ϰ�����Ļ�������������(mount)����\n" );
	set( "unit", "ƥ" );
	set_perm_stat( "str", 10 );
	set_perm_stat( "int", 2 );
	set_natural_armor( 25, 12 );
	set_natural_weapon( 8, 4, 10 );
	set( "c_extra_look", "$N������һƥ�ɰ���С������\n");
	set( "alignment", 100 );
	set( "mountable", 1);
	set( "max_load", 1600 );
	set_c_limbs( ({ "ͷ��", "����", "����", "β��" }) );
	set_c_verbs( ({ "%ş�����ȣ���%sһ��", "%s������������ǰ֫��%sһ�����ҵ�" }) );
}

void init()
{
//	monster::init();
	mount::init();
	
}
