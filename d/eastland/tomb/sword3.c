#include <almuhara.h>

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
	set_short("����ͨ��");
	set_long( 
@C_LONG_DESCRIPTION
�����һ��������ͨ�������ܼ���ذ������㼸�����������Լ��������ͽŲ������Ӧ
������ǰ�������ĺ����������ֱ����£�����������δ���й��ĸо����㲻����ԥ������
���׸ò��ü�����ǰ����??
C_LONG_DESCRIPTION
	);
	
	set( "exits", ([ 
		"east"  : TOMB"/sword2",
		"west"  : TOMB"/sword4"  ]) );
	create_door( "west","east",
		   (["keyword" : ({"door", "iron"}),
		     "name"    : "iron door",
		     "c_name"  : "������",
		     "desc"    : "A huge iron door\n",
		     "c_desc"  : "һ�ȼ�̵Ĵ����š�\n",		
		     "lock"    : "TOMBKEY_2",
		     "status"  : "locked",
		     ]) );		
	reset();	
}

