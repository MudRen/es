#include "almuhara.h"

inherit ROOM;

void create()
{
	::create();
	set_short("������");
	set_long( 
@C_LONG_DESCRIPTION
�����һ����������������Կ���ǰ����Լ���������⡣һ����ķ��ǰ��������
�����ſ쵽�˰�.......
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"north" : TOMB"/room5", 
		"south" : TOMB"/room1",  ]) );
	set( "objects", ([
		"guard1" : MOB"/guard1", 
		"guard2" : MOB"/guard1"]) );
	set( "pre_exit_func", ([
		"north" : "check_guard" ]) );
	reset();	
}

int check_guard()
{
   object guard;

   guard = present("guard", this_object());
   if( present("guard", this_object()) && guard->query("right_guard") )  {
		write("����˵��: ��ʦ����κ��˲��ý��롣\n");
		return 1; }
	return 0;
}
