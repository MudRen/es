#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("����");
	set_long(@LONG
��������һ���ȴ����������������Ǹ߼�ͷ����ާ��ֲ������������Ҫʹ
����赹�ڵأ����������ֲ�����С�棬��ס�ض������ȫ�������ѹ��Ѽ���
վ�������ʱ���������˵�������ԭ������������һ����ɳ̲��
LONG
	);
	set( "exit_suppress", ({
	   "south"}) );
	set("exits", ([ 
       	    "east" : SAREA"coast4", 
            "west" : SAREA"coast1",
           "south" : SAREA"coast7" 
        ]) );
	set("objects", ([
           "insect#1" : SMOB"insect1",
	   "insect#2" : SMOB"insect1",
           "insect#3" : SMOB"insect1"
	]) );
	reset();
}
void init()
{
    add_action("do_search","search");
}
int do_search( string arg )
{
    write("�������ҷ������ϱ�(south)�ƺ�����ͨ����\n");
    return 1;
}