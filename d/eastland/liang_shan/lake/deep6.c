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
		"down" : TROOM"underwater6", 
		"south" : TROOM"shallow13",
		"east" : TROOM"whirl2", 
	        "north" : TROOM"deep4",
	        "west" : TROOM"shallow10"]));
	set( "pre_exit_func",([
	        "south":"check_shallow",
	        "east":"check_whirl",
	        "west":"check_shallow",
	        "north" :"check_deep"
	        ]));
	reset();
}
int check_deep()
{    
    if ((int)this_player()->query_skill("swimming")-random(15)<40){
    write (
    "��Ŭ������Ҫ�ε��𴦣���������ȴ����ʹ�������³�ȥ.......\n");
    this_player()->move_player(TROOM"underwater6","SNEAK");
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
