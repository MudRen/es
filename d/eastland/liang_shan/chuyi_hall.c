#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "������" );
	set_long(
	"��������ɽ���������µľ����������е�ͷĿ���������ѪΪ�ˣ���\n"
	"�ɽ���ֵܣ���ͬ�������ڶ�����½�������������߱��֡������ĳ���\n"
	"�ǳ��򵥣�����С���ţ�һ��С�㰸���㰸��һ����ˮ�������㣬һ��ţ\n"
	"���⵶�������ȫ���İ�\���ˡ�������һ��С�ſ����뿪���\n"
	);
	set( "light",1 );
        set( "exits", ([
                "out"  : TROOM"path5",    
                "north"  : TROOM"path6",
        ]) );
        reset();
}
int clean_up() { return 0; }