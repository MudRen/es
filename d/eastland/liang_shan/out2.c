#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "С·" );
	set_long(
"����һ����ͼ���Ҳ�����С·�����Գ����˳�����«έ�����ҡҷ��\n"	  
"��˵��������徶ǿ�˳�û�����ǻ᲻��Ͷ���«������?\n"
	);
	set_outside("eastland",1);
        set( "exits", ([
                "north" : TROOM"out1",
                "south" : TROOM"out3"
        ]) );
        reset();
}
void init()
{
object bandit;
if ( random(100)>1 || present("thief") ) return 0;
write(
"ͻȻһ���󺰣�һ��ɽ�����ֱ��ŵĴ�«����������߾������λε�\n"
"�ֵ�������¶��������΢Ц��\n");
bandit =new("/d/eastland/monster/mt_bandit");
bandit->move(TROOM"out2");
}
int clean_up() { return 0; }