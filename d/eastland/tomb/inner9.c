#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("��Ĺ�");
	set_long( 
@C_LONG_DESCRIPTION
����������Ĺ�������һ�߾޴����׷���춴ˣ������������������Ĺ��գ�������
�͹�׾�������Ҳ��κ�һ˿�Ľӷ죬�����Ǵ�һ���޴����ʯ�е�̳����Ƶģ�������Ӧ
�þ��ǻʵ۵Ĺ�ľ�ɡ����ܵ�ǽ�ڶ����ûƽ������ɣ�����һ�����˾����׽����ɵķ���
�����ɷǷ�������Կ�����ʯ��ǰ�Ĺ������������ۡ��ʹڡ��Լ�һ����������ĺ챦ʯ��
��������ϱ߿��Կ�������ԭ��
C_LONG_DESCRIPTION
	);

	set( "light",1);
	set( "exits", ([ 
		"south" : TOMB"/inner5" ]) );
	set( "objects", ([
		"robe" : ITEM"/robe",
		"crown" : ITEM"/crown",
		"ruby" : ITEM"/ruby" ]) );
	set( "pre_exit_func", ([
		 "south" : "check_eq" ]) );
	reset();	
}

void init()
{
  if( this_player()) this_player()->set_explore("eastland#36");
}
int check_eq()
{
	if ( !present( "emperor robe", this_object() ) || !present( "emperor crown", this_object() ) )
	{	tell_room( this_object(),
		"\n"+"ͻȻһ��޴��ޱȵ�ʯͷ ---- ������ʯ������������ס�ϱߵĳ��ڡ�\n" );
		delete( "exits/south" );
		return 1; }
	else return 0;
}
