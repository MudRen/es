#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "��Ӫ" );
	set_long(
	"��������ɽ���Ĳ�����Ϣ�ң����ǿ����û���ŵ��������������ʱ��\n"
	"����������ǹ�ҹ��Ϣ�ĵط������û����������Ļ������ӵ�ָ�ӹ�Ҳ\n"
	"����������Ϣ��ֱ�����������ݡ�\n"
	);
	set( "light",1 );
        set( "exits", ([
                "south"  : TROOM"plaza4",    
        ]) );
        set( "objects",(["bandit":TMONSTER"small_bandit",
             "shu":TMONSTER"shu"]));
        reset();
}
int clean_up() { return 0; }