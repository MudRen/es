// translation done. -Elon 03-10-94
#include "../moyada.h"
inherit ROOM;

void create()
{
	::create() ;
	set_short( "��Ѩ" );
	set_long( @C_LONG
ʮ�������Ķ�Ѩ, ������, ��֪ͨ���δ����Ĵ��Եó�ʪ, ������ɭɭ
�ĸо�, ��޲��øϽ��뿪���
C_LONG
	);
	
	set( "exits", ([ 
	   "south" : MOYADA"shop/cellar",
	   "north" : MOYADA"shop/strange_room",
	]) );
	set( "pre_exit_func", ([
	  "south" : "to_cellar",
	]) );
	set( "objects", ([
	  "small_bat#1" : MOYADA"monster/bat",
	  "small_bat#2" : MOYADA"monster/bat",
	  "small_bat#3" : MOYADA"monster/bat",
	  "small_bat#4" : MOYADA"monster/bat",
	  "small_bat#5" : MOYADA"monster/bat",
	  "small_bat#6" : MOYADA"monster/bat",
	  "small_bat#7" : MOYADA"monster/bat",
	  "small_bat#8" : MOYADA"monster/bat",
	  "bats_king#1" : MOYADA"monster/large_bat",
	  "bats_king#2" : MOYADA"monster/large_bat",
	]) );
	reset();
}

int to_cellar()
{
    if( MOYADA"shop/cellar"->query("move") ) 
      return 0;
    write( "���ں������ᶫ����ס��, ����ȥ. \n" );
    return 1;
}
