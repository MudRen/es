#include <takeda.h>

inherit ROOM;

void create()
{
       object song;
	::create();
	set_short( "С�鷿" );
	set_long(
	"����һ��СС���鷿���������������ص��ţ�һ�Ź��ⰻȻ�ĺ�ľ������\n"
	"���������Ŀ�⣬�����\��\һ��СС����¯�������Ʊ�������Ķѷ�������\n"
	"���ɼ������൱�İ�ϧ�鱾��һ��������������ǰ���������£�������˼��\n"
	);
        set( "light",1);
        set( "exits", ([
                "west" : TROOM"yard3"
        ]) );
        song = new(TMONSTER"song");
        song->move(this_object());
        set( "objects",([
                "cap1":TMONSTER"captain",
                "cap2":TMONSTER"captain",
                "cap3":TMONSTER"captain"
                ]));

        
        reset();
}
void init()
{
  if(this_player()) this_player()->set_explore("eastland#21");
}
int clean_up() { return 0; }
