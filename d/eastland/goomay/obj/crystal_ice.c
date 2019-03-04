#include <../goomay.h>

inherit OBJECT;

void create()
{
	set_name( "crystal of ice", "�������" );
	add( "id", ({ "crystal","ice" }) );
	set_short( "�������" );
	set_long(
		"����һ�ź���������������ǻ��澫��Ŀ��ǣ�Ҫʹ����\n"
		"���� ice <someone>��\n"
	);
	set( "unit", "��" );
	set( "weight", 5 );
	set( "value", ({ 100, "silver" }) );
	set( "no_sale", 1 );
}

void init()
{
	add_action( "do_ice", "ice" );
}

int do_ice(string arg)
{
	object obj;

	if( !arg || arg=="" || !(obj= present(arg, environment(this_player()))) )
		return notify_fail( "Ҫ��˭ʹ�ñ�����\n" );
	if( base_name(obj) != Mob"fire_beast" ) {
		write(
			"���ó���������" + obj->query("short") + "�����ϣ������Է��ƺ�����Ӱ�졣\n");
		tell_room( environment(this_player()), 
			this_player()->query("c_name")+ "�ó�һ��Сʯͷ����"+obj->query("short")+"���ϡ�\n",
			this_player() );
		return 1;
	} else {
		write( 
			"���ó���������" + obj->query("short") + "���� .... \n");
		tell_room( environment(this_player()), 
			this_player()->query("c_name")+ "�ó�һ�ű�������"+obj->query("short")+"���ϡ�\n",
			this_player() );
		obj->iced();
		write( 
			"��ı������˳�ȥ����������" + obj->query("short") + "���ϣ�\n");
		remove();
		return 1;
	}
}
