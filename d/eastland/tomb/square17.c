#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("���¹㳡");
	set_long( 
@C_LONG_DESCRIPTION
�����һ���޴�Ĺ㳡���ھ������᳤�õ�·���ᣬ��������л�Ȼ���ʵĸо���ʵ��
�޷�������Ĺ�����������ڵص��½�����˴�Ĺ㳡���㲻������Щ�������˷־��⡣
�㳡�Ͽտյ����ģ��ƺ�û���κ�������ڣ�Ҳ��\��\�������ˡ��ڱ��ߺ�����ʲ�ᶫ������
��Ĺ��������ȥ̽��������
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"north" : TOMB"/square21", 
		"south" : TOMB"/square1"  ]) );
	set( "objects", ([
		"guard" : MOB"/holy_guard1" ]) );
	set( "pre_exit_func", ([
		"north" : "check_guard" ]) );
	reset();	
}

int check_guard()
{
	if (present( "guard", this_object() ) ){
		tell_object(this_player(),
		"������ֹ��ǰ��!!\n");
		return 1;}
	else return 0;
}