#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "upstair of Chung Yi Hall", "������¥��" );
	set_long(
	"����һ��СС�ķ��䣬���õĺ������õ����ӣ�һ���㰸��\�����У�����\n"
	"����ǰ������\���������˸�\��������˼�ֻ������������ȼ�գ��������\n"
	"�����£����˶�������֮�޳���\n"
	);
        set( "exits", ([
                "down" : TROOM"hall"
        
        ]) );
        set( "objects",([
                "bandit":TMONSTER"small_bandit",
                "wizard":TMONSTER"wizard"
        ]) );        
        reset();
}
int clean_up() { return 0; }