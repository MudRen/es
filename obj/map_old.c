
inherit "std/map";

void create()
{
	seteuid( getuid() );
	set_name( "map", "��ͼ" );
	set_short( "a magical map", "ħ����ͼ" );
	set_long(
		"This is a magical map of the realms of Noden Kingdom. You can either\n"
		"\"read map\" to see the map or \"read legend\" to see what the symbol\n"
		"on the map means.\n",
		"����һ��ħ����ͼ������� read map ����ͼ���ݣ�����\n"
		"read legend ����ͼ�Ϸ�������������塣\n"
	);
	set_size( 7, 7 );
	set( "virtual_server", "/d/noden/virtual/noden_server" );
	set( "weight", 5 );
	set( "value", ({ 20, "silver" }) );
}
