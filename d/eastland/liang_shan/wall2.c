#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "դ��С·" );
	set_long(
	"��������ɽ����կ�ϵ�С·����Ϊ�˷�������������ģ���������\n"
	"������û���˸����ַ��ˣ�վ�����Զ���ķ羰һ�����ţ�С·����\n"
	"���������죮\n"
	  
	);
	set_outside("eastland");
	set( "light",1 );        
        set( "exits", ([
                "east" : TROOM"wall3",
                "west" :TROOM"wall1"      
        ]) );
        reset();
}
int clean_up() { return 0; }