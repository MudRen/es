#include <mudlib.h>
inherit OBJECT;
inherit MAP;

void create()
{
         seteuid(getuid());
	set_name( "map", "��ͼ" );
	set_short( "ŵ��������ͼ" );
	set_long(@CLONG
����ŵ��������ȫͼ������� read map ����ͼ���ݣ�����
read legend ����ͼ�Ϸ�������������塣
CLONG
	);
	set_size( 21, 21 );
	set( "prevent_get", 1 );
	set_center_coordinate( 10, 10, "/d/noden/virtual/noden_server");
}
