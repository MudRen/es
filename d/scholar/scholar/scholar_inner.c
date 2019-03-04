#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
    set_short("Scholar Inner room", "ī����");
	set_long( @LONG_DESCRIPTION
This is the inner hall of scholar's guild. .
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
�����ڽ��������������ڲ���ī������������������ϰ��ĵط���ֻ������
������˲��ܽ���������������һ�����غ�Ȼ�����ķ�����(book)��
C_LONG_DESCRIPTION
	);
    set("c_item_desc",([
         "book":@BOOK
�����Բ������ɷ����д��[��Ȼ�����ķ�]�������Ҫѧϰ���ķ�������������
��Ļ�Ա��������ǵĻ�ֻҪ�� study inner_force �㽫��ѧ�����ڹ�\�ķ���
BOOK
]));         
	set( "light", 1 );
	set( "exits", ([ 
	  "east"  : "/d/scholar/scholar/hall", ]) );
	reset();
}

void init()
{
	add_action("to_study","study");
}

int to_study(string arg)
{
	if( !arg || arg!="inner_force" ) return 0;
	if( (string)this_player()->query("class") !="scholar" )
		write("��Ǹ�㲻�Ǳ�������������㲻��ѧ���ķ�\n");
	else if( (int)this_player()->query("force_effect") > 1 )
		write("���Ѿ�ѧ�����ķ�������ѧ\n");
	else {
		write("�㾭��һ�γ�ʱ��ĵ�ѧϰ��������򵽺�Ȼ������\���ں�\n");
    	this_player()->set("force_effect", 2);
	}
	return 1;
}
