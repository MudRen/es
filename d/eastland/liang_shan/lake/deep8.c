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
		"down" : TROOM"underwater8", 
		"south" : TROOM"whirl3"]));
	set( "objects", ([
	        "fishman" : TMONSTER"two"
	        ]));
	set( "pre_exit_func",([
	        "south":"check_whirl"
	        ]));
	reset();
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
