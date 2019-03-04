#include <takeda.h>

inherit ROOM;

void create()
{
	object dong;
	::create();
	set_short( "ͥԺ����" );
	set_long(
	"����һ��Բ�͵�С�ţ��ڶ�����½��������ͨ����ͥԺ�ĳ���ڣ����ŵ�\n"
	"��һ���㿴��һ��СС��ͥԺ(yard)�����滨ľ���裬�������̫Զ��������\n"
	"���ֵ���ʲ�ᡣ\n"
	);
        set( "c_item_desc", (["yard":
        "����ע��������ͥԺ���й�˵�����Ĺ���о���������ɢ����ĵ�������\n"
        "ֹ����������ͷ��\n"
        ]));
        set_outside("eastland");
        set( "exits", ([
                "east" : TROOM"yard8",
                "south" : TROOM"hall"
        ]) );
        dong = new(TMONSTER"dong");
        dong->move(this_object());
        set( "pre_exit_func",([
               "east" : "check_leave"
        ]));
        reset();
}
int check_leave()
{
write( 
"�߹�������ţ�������鲻�������Ľ�������������������һƬԭʼɭ�֣��Լ�\n"
"��Ȼû���ɵľ����Լ�ʮ����С������˷������ǳ����˲��ɲ��Σ�ա�\n\n");
return 0;
}
int clean_up() { return 0; }
