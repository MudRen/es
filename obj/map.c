#include <mudlib.h>
inherit OBJECT;
inherit MAP;

void create()
{
	seteuid( getuid() );
	set_size( 7, 7 );
#include <compress_obj.h>
	set_name( "map", "��ͼ" );
	set_short( "ħ����ͼ" );
	set_long(
		"����һ��ħ����ͼ������� read map ����ͼ���ݣ�����\n"
		"read legend ����ͼ�Ϸ�������������塣\n"
	);

	set( "virtual_server", "/d/noden/virtual/noden_server" );
	set( "weight", 5 );
	set( "value", ({ 20, "silver" }) );
}
