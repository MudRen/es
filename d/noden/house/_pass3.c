// File: /d/noden/house/pass3.c
// Generated by Roommaker Mon Dec  4 20:59:38 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("���Ⱦ�ͷ");
	ob->set_long( @LONG_DESCRIPTION
������վ��һ���������ȵľ�ͷ��������һ��Բ�εĴ���(window)��һ��ľ��
¥��ͨ�����ݵĶ�¥�����ߵ�ǽ�ϸ���һ��ͭ�Ƶ���̨������������ǵ����ģ���
֪����ʲ�����������ģ�
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "c_item_desc", ([ 
		"window" : @LONG_TEXT
����������ȥ��һƬһ���޼ʵı���ɫ�󺣣���������ɭɭ�����ռ�ֱ������֮��
....��������ǵý�����ʱ�򣬱���Ӧ����һƬɭ��....����е�һ������ӽŵ�
����....
LONG_TEXT
 ]) );
	ob->set( "exits", ([ 
		"up" : "/d/noden/house/pass4", 
		"south" : "/d/noden/house/pass2", 
		"west" : "/d/noden/house/kitchen" ]) );
	ob->reset();
}