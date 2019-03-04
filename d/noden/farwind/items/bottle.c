#include <mudlib.h>

inherit WEAPON;

int breaked;

void create()
{
	set_name( "wine bottle", "��ƿ" );
	add( "id", ({ "bottle" }) );
	set_short( "��ƿ" );
	set_long(@CLONG
����һ��....��....��ƿ�ӣ��������Ѻȵ�һ��Ҳ��ʣ��ƿ��
����һ�Ѷ��ĵ���ĭ������������������˰ɡ�
CLONG
	);
	set( "weight", 30 );
	set( "value", ({ 3, "silver" }) );
	set( "useless", 1 );
	breaked = 0;
}

void init()
{
	add_action( "break_bottle", "break" );
}

int break_bottle(string arg)
{
	if( breaked ) return 0;

	if( !arg || !id(arg) )
		return notify_fail("����ʲ�᣿\n");
	breaked = 1;
	write( 
		"�㽫��ƿˤ�ڵ��ϣ���....���������ؾ�ƿ�ƺ����Ե���������\n"
	);
	tell_room( environment(this_player()), 
		this_player()->query("c_name") + "��һ����ƿˤ�ڵ��ϣ��Ƴ����ء�\n",
		this_player() );
	set( "type", "dagger" );
	set( "weapon_class", 7 );
	set( "min_damage", 3 );
	set( "max_damage", 7 );
	set_name( "broken wine bottle", "�ƾ�ƿ" );
	add( "id", ({ "broken bottle" }) );
	set_short( "�ƾ�ƿ" );
	return 1;
}

