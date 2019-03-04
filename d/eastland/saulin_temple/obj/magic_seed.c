#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "Relic of Damo", "��Ħ������" );
	add( "id", ({ "relic" }) );
	set_short( "��Ħ������" );
	set_long(@C_LONG
����Ȼֻ�ǿ�СС�������ӣ������汦���������Ե�ʮ�ֲ�ƽ������˵
�����Ե����������Ҫʹ�������ӣ��� throw <someone>��
C_LONG
	        );
	set( "unit", "��" );
	set( "weight", 5 );
	set( "value", ({ 100, "silver" }) );
	set( "no_sale", 1 );
}

void init()
{
	add_action( "do_throw", "throw" );
}

int do_throw(string arg)
{
	object obj;

	if( !arg )
		return notify_fail("Ҫ�������Ӷ�˭��\n");
	if( !( obj = present(arg, environment(this_player())) ) )
		return notify_fail( "����û����ˡ�\n");
	if( undefinedp(obj->query("zapped")) ) {
		write( 
			"���ó������Ӷ���"+obj->query("c_short")+"�������Է��ƺ�����Ӱ�졣\n"
		);
		tell_room( environment(this_player()), 
			this_player()->query("c_name")+
			"�ó�һ��СС�Ķ�������"+obj->query("c_short")+"��\n"
			, this_player()
		);
	} else {
		write( 
			"���ó������Ӷ���"+obj->query("c_short")+".... \n" 
		);
		tell_room( environment(this_player()), 
			 this_player()->query("c_name")+
			"�ó�һ�������Ӷ���"+obj->query("c_short")+"��\n"
			, this_player()
		);
		write( "���������ֱֱ����"+obj->query("c_short")+"�����Ŵ�ȥ��\n");
		obj->zapped();
		remove();
	}
	return 1;
}
