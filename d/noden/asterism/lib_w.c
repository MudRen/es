// File: /d/noden/asterism/lib_w.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("Office of library administer", "ͼ��ݹݳ���");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		,@C_LONG_DESCRIPTION
�������Ĳ��������ӵģ�ټ��ķ����������һ�Ŵ��İ칫����
�ı�ǽ�Ϲ��˲���ʮ���Ļ��������������������Ψһ�ĵ�׺��
C_LONG_DESCRIPTION
	);

//	set_outside( "asterism" );
	set( "light", 1 );
        set("c_item_desc",(["paintings":
             "һ�������˸е���Ŀ�Ļ�����ϸһ��ȫ�������ø�ɫ��ʯ��ɵ�.\n"
             "�ñ�ʯ�ܡ�������Ф�񻭣����ּ������ǿ��¡�\n"]));       
	set( "exits", ([ 
		"east" :ASTR"lib01",
		]) );
//	set( "objects","Administer" : MOB"lib_adm" , ) ;
	
	reset();
	
}                         

