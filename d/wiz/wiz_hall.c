#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "��ʦ����" );
	set_long(
		"��������վ����ʦ����Ĵ���֮�У������������ĳ�ְ��д�������ɫ��\n"
	"·��ʯ�Ľ��ɵģ�һЩ��ɫ��ֲ��Ͳ�֪���Ļ���װ�����������ܵ�Բ������\n"
	"���������ġ���ʦѧԺ���������Ǵ�˵�еġ�����㳡��������������ʦ�ǰ�\n"
	"�������ڵء����ߵ�ǽ����һ��޴�ľ��ӡ�\n"
	);
	set( "light", 1 );
	set( "pre_exit_func", ([
		"east" : "to_farwind"
	]) );
	set( "exits", ([
		"east"  : "/d/adventurer/hall/adv_guild",
		"south" : "/d/wiz/wiz_office",
        ]) );
}

int to_farwind()
{
		write("�㴩�����ӣ�����ð���߹��ᡣ\n");
	return 0;
}
