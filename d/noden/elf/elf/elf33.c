#include "../layuter.h"

inherit ROOM;

void create()
{   
    object lord;

	::create();
	set_short("����");
	set_long( @LONG_DESCRIPTION
  ������һ���������䣬��һ�ž޴��ʯ�η������ӵı��ߣ��������
  ����ͼ��������������Ư���Ľ�֯��̺ʹ�������俴�����߹��쳣��
  �ݶ���һ�޴���εƣ��ɴ˷����Ĺ��������������䡣
LONG_DESCRIPTION
	);

	lord=new( "/d/noden/elf/monster/lord" );
	lord->move( this_object() );

	set( "light", 1 );
	set( "exits", ([
		"south" :LELF"elf32"
	]) );
	reset();	
}

int clean_up() { return 0; }
