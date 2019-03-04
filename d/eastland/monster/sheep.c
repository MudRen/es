#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "white sheep", "������" );
	add( "id", ({ "sheep" }) );
	set_short( "������" );
	set_long(
		"�㿴��һֻ��ѱ�İ����򣬾������ڲݵ��ϳԲݡ�\n"
	);
	set( "unit", "ֻ" );
	set( "alignment", 500 );
	set_perm_stat("kar", 5 );
	set_c_verbs( ({ "%s��������%sһ��" }) );
	set_c_limbs( ({ "ͷ��", "����", "�Ȳ�" }) );
}

int stop_attack()
{
	object girl;

	girl = present("shepherdess", environment());
	if( !girl ) return 0;
	girl->protect_sheep(this_object(), this_player());
	return 0;
}
