#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("��ԭ");
	set_long(@LONG
��������һ���տ��Ĳ�ԭ�����ͱ����ǲ�ԭ�����죬�ϱ��Ǵ���Ⱥ�����Ϸ���
����Щ��̫���Ե��㼣���ڲ�ԭ�ϳ�����ЩСС�İ���������ɫ�ʡ�����ζ�˱�
��һȺҰ�������յش�����䣬���������ۡ��㶫����һ��ǧ��ߵ�ɽ�ڣ�����
ͻ�������СС���ҿ�������Ӱ�һ���ľ�Ȼ��������˵��ɽ���Ǿ���ʯͷ��
�������ģ��ҿ��������ѷ죬�������Է������С�����������һֻ�ŵ������
LONG
	);
	set("light",1);
	set( "exit_suppress", ({
	   "southwest"}) );
	set("exits", ([ 
                "west" : SAREA"plain1",
               "north" : SAREA"plain4",
           "southwest" : SAREA"village1",
        ]) );
        set("objects" , ([
           "boy#1" : SMOB"boy1",
           "boy#2" : SMOB"boy1",
          "girl#1" : SMOB"girl1",
          "girl#2" : SMOB"girl1",
        ]) );
	reset();
}
void init()
{
   add_action("do_search","search");
}
int do_search(string arg)
{
    write("�㷢���������ϱ�(southwest)�Ĵ���Ⱥ�������߹��ĺۼ���\n");
    return 1;   
}