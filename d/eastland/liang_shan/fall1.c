#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "�����" );
	set_long(
	"�����ڰ���У���ͣ������׹�䣬�����¿�ȥ���ޱߵĺڰ��������\n"
	"�ſ���������ӭ�����������ʶ���������˵��������һ�����ҵĽ���\n"
	);
        set( "pre_exit_func", ([
                "down" : "check_fall"
        ])) ;        
        set( "exits", ([
                "down" : TROOM"fall2"
        ]) );
}
int check_fall()
{
write(
"\n�㲻ͣ������ڵĿռ���ȥ��\n\n");
return 0;
}
int clean_up() { return 0; }