// File: /d/noden/bluesand/office.c
// Generated by Roommaker Mon Dec  4 22:09:19 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("�칫��");
	ob->set_long( @LONG_DESCRIPTION
��������ɳ�۾����ӳ��İ칫�ң��ྻ�Ĵ���ӳ���������׼��ӵ�ɳ̲��ʹ��
���ò���Ľ�����ǵĹ���������������һ����������ֿ�Ľֵ��������ӳ�������
��Ѳ�ߣ�����С͵��Ű��
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"north" : "/d/noden/bluesand/street2" ]) );
	ob->set( "no_monster", 1 );
	ob->set( "objects", ([ 
		"captain" : "/d/noden/bluesand/monster/captain" ]) );
	ob->reset();
}