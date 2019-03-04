#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "incantation of exorcise", "��ħ��" );
	add( "id", ({ "incantation" }) );
	set_short( "��ħ��" );
	set_long(
		"������ħ����һ�Ż�ɫ��ֽ�����滭�����������������ͷ��ţ�Ҫʹ��\n"
		"��ħ�䣬�� zap <someone>��\n"
	);
	set( "unit", "��" );
	set( "weight", 5 );
	set( "value", ({ 100, "silver" }) );
	set( "no_sale", 1 );
}

void init()
{
	add_action( "do_zap", "zap" );
}

int do_zap(string arg)
{
	object obj;

	if( !arg || arg=="" || !(obj= present(arg, environment(this_player()))) )
		return notify_fail( "Ҫ��˭ʹ����ħ�䣿\n");
	if( base_name(obj) != "/d/noden/house/monster/devil" ) {
		write( 
			"���ó���ħ����" + obj->query("short") + "��ǰ���裬�����Է��ƺ�����Ӱ�졣\n");

		tell_room( environment(this_player()), 
			this_player()->query("c_cap_name")+ "�ó�һ�Ż�ɫ������"+obj->query("short")+"��ǰ���衣\n",
			this_player() );
		return 1;
	} else {
		write("���ó���ħ����" + obj->query("short") + "��ǰ���� .... \n");
		tell_room( environment(this_player()), 
			this_player()->query("c_cap_name")+ "�ó�һ�Ż�ɫ������"+obj->query("short")+"��ǰ���衣\n",
			this_player() );
		obj->zapped();
		write("�����ħ��ͻȻ�Լ����˳�ȥ����������" + obj->query("short") + "���ϣ�\n");
		remove();
		return 1;
	}
}
