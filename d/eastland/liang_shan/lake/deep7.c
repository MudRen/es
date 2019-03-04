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
		"down" : TROOM"underwater7", 
		"south" : TROOM"shallow16",
		"east" : TROOM"shallow14", 
	        "north" : TROOM"whirl2",
	        "west" : TROOM"shallow13"]));
	set( "pre_exit_func",([
	        "south":"check_shallow",
	        "east":"check_shallow",
	        "west":"check_shallow",
	        "north" :"check_whirl"
	        ]));
	reset();
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
 int check_whirl()
 {
   int n;
   string place;
   write (
   "ͻȻ�䣬�㷢����������һ�������У�ǿ����ˮ�����ϵİ��㳶���������ġ�\n"
   "�㲻�ϵ�����...................................\n\n\n\n"
   "����춾�ƣ�������������о���ˮ�ף���������Ӱ��ʱռ�����������.....\n");
   switch (n=random(3) ){
   case 0: place = "whirl1"; break;
   case 1: place = "whirl2"; break;
   case 2: place = "whirl3"; break;
   }
   this_player()->move_player( TROOM+place,"SNEAK");
   return 1;
 }
