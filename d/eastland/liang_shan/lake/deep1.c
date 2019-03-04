#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short("����");
	set_long( @C_LONG_DESCRIPTION
�����Ǻ��е���ˮ���򣬳��˴�������ż���������˴��⣬һ���ð������
���Ӿ�������ѣ����������˴�������ɫɫ���������Ϊû����Ϊ�ĸ��ţ�����ˮ
�п��ֵ�������ȥ��
C_LONG_DESCRIPTION
	);

	set_outside("eastland");
	set( "exits", ([ 
		"down" : TROOM"underwater1", 
		"south" : TROOM"shallow21",
		"east" : TROOM"deep2" ]) );
	set( "pre_exit_func",([
	        "east":"check_deep",
	        "south":"check_shallow"
	        ]));
	set( "objects",([
	        "fish": TMONSTER"fish1"]));
	reset();
}
int check_deep()
{    
    if ((int)this_player()->query_skill("swimming")-random(15)<40){
    write (
    "��Ŭ������Ҫ�ε��𴦣���������ȴ����ʹ�������³�ȥ.......\n");
    this_player()->move_player(TROOM"underwater1","SNEAK");
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
