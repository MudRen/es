#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name( "waiter", "��С��" );
	set_short( "��С��" );
	set_long(
		"��С��˵: ��������������\n"
	);
	set( "gender", "male" );
	set( "race", "human" );
	set_perm_stat( "dex", 5 );
	set_skill( "dodge", 30 );
	set( "natural_weapon_class1", 5 );
	set( "natural_min_damage1", 4 );
	set( "natural_max_damage1", 8 );
	set( "wealth/copper", 100 );
	set( "chat_chance", 50 );
	set( "att_chat_output", ({
		"��С��˵��: ��ү���� ....\n",
		"��С��˵��: ��������˭��˭�� ....\n",
		"��С�������Ҷ㣬˵��: ���а��У��л���˵��\n"
	}) );
}
