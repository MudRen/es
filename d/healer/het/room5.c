#include <mudlib.h>
#include "wang.h"

inherit ROOM;

void create()
{
	::create();
    	set_short("����");
	set_long( 
		 @C_LONG_DESCRIPTION
��������ҩʦ�����ң�����������Ǭ���ģ����񳣳����˳��롣���������
����ʵ���ٵĿ�����ֻ�����ֱ���һ�����ӣ����Ϸ���һ���е�ɵ��顣
C_LONG_DESCRIPTION
	);

	set( "c_item_desc", ([ 
		"book" : @LONG_TEXT
�Ȿ��Ӧ������ҩʦ�ıʼǰɣ��ظ��������ܡ�����Բ鿴(read)�Ȿ���
ҩ����(list)��
LONG_TEXT
 ]) );
    	set( "exits", ([ 
		"west" : WANG"room4" ]) );
	reset();
}

void init()
{
	add_action( "do_read", "read" );
}

int do_read( string str )
{
	int page;

	if( !str || str=="" ) return notify_fail( "�Ķ�ʲ�᣿\n" );
	if( str=="list" ) {
		cat(POISON_INFO"c_list"); 
		return 1;
	} else if( sscanf(str, "page %d", page)==1 ) {
		if ( file_exists(POISON_INFO"c_page" + page) )
			cat( POISON_INFO"c_page" + page );
		else
			write("��ҳ�ּ�ģ��������������Ҳ�������\n");
		return 1;
	}
}
