// File: /d/noden/house/pass4.c
// Generated by Roommaker Mon Dec  4 20:59:51 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("���Ⱦ�ͷ");
	ob->set_long( @LONG_DESCRIPTION
������վ��һ���������ȵľ�ͷ�������ǹ��ݵĶ�¥��һ��ľ�Ƶ�¥������ͨ
��һ¥�����ߵ�ǽ����һ��Բ�εĴ���(window)�����ƺ������ϱ���Ů���ڳ����
����������������Ǹ����������Ĺ����ﲻ����Ů���ڳ��裬��׳������׼�����
�κ����ι�״�Ĺ��֡�
LONG_DESCRIPTION
	);

	ob->set( "c_item_desc", ([ 
		"window" : @LONG_TEXT
�Ӵ���������ȥ��һƬ���ï�ܵ�ɭ�֣���������������Ŀյ�������������
������Ϸ....���������ӣ�....��ܿ��ת��ͷ������ȥ���Ĵ���ľ�ɫ��
LONG_TEXT
 ]) );
	ob->set( "exits", ([ 
		"down" : "/d/noden/house/pass3", 
		"south" : "/d/noden/house/pass5", 
		"west" : "/d/noden/house/bedroom" ]) );
	ob->reset();
}