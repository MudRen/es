#include <mudlib.h>
#include "academy.h"

inherit ROOM;

void create()
{
	::create();
    set( "max_laod", 100000 );
	set( "light", 1 );    	
	set_short( "Academy of Wizards", "��ʦѧԺ" );
	set_long( @LONG
It needs work here.	
LONG
, @C_LONG
��������վ����ʦѧԺ�Ĵ���, �����ʵϰ��ʦ��������ѧϰ��ν�
�����ǵĹ���ʵ�ֳ���, ͬʱҲ����ѧУ�е����ֿ��顣������ͨ��ѧУ
�����еĿ����ͬʱ, ���Ǿ�ӵ�г�Ϊ��ʽ��ʦ���ʸ�
C_LONG
	);
	set( "exits", ([
		"north"  : HERE"hall"
	]) );
}
