#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short("����");
	set_long( @C_LONG_DESCRIPTION
�����Ǻ��е�ǳˮ����ˮ���������Լֻ�����ʣ����㲻��ӾҲ���ص���
����Σ�գ�Ҳ�������ܺú����͵������ľ�ɫ����ˮһ���޼ʣ��̲���嫣��� 
ֻ�������з�Խˮ�ϣ���Ŀ���Ѽ�֮�����ƺ���Ⱥɽ���ƣ�����춺��ϵ���ϼ����
�ò��Ǻ������
C_LONG_DESCRIPTION
	);

	set_outside("eastland");
	set( "exits", ([ 
		"west" : TROOM"deep3",
		"east" : TROOM"shallow4",
		"north" : TROOM"shallow2",
		"south" : TROOM"shallow6" ]) );
	set( "pre_exit_func",([
	        "west":"check_deep",
	        "north":"check_shallow",
	        "east":"check_shallow",
	        "south":"check_shallow"
	        ]));
	reset();
}
int check_deep()
{    
    if ((int)this_player()->query_skill("swimming")-random(15)<40){
    write (
    "��Ŭ������Ҫ�ε��𴦣���������ȴ����ʹ�������³�ȥ.......\n");
    this_player()->move_player(TROOM"underwater3","SNEAK");
  return 1;
  }
    else return 0;
}
int check_shallow()
{
    if ((int)this_player()->query_skill("swimming")-random(5)<13){
    write (
    "��Ŭ�������ε��𴦣����㷢������һ��Ҳ����.....\n");
  return 1;
    }
    else return 0;
}
