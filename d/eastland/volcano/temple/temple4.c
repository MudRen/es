#include "../oldcat.h"

inherit ROOM;

int be_eated;
void create()
{
	::create();
    set_short("���������");
	set_long(
@LONG_DESCRIPTION
һ���������������յİ����������Ķ��˵��л����ͼ�����ĸ���
�����Ƶľ޴����������ĸ����䣬�����������ڶ������������(statue)��
֪���������ᾭ�ģ�������ǰ�Ĺ���(desk)��һЩ��Ʒ��
LONG_DESCRIPTION
	);
set( "exits", ([
     "east": OTEMP"temple6",
     "west": OTEMP"temple5",
     "south": OTEMP"temple1",
     ]) );
set("item_desc",([
    "statue":"һ�����������Ļ��������о�������۾����ڿ�����\n",
    "desk" : @DESK
�����˵�β�ͣ������˵��ԣ����˵ĳ������ħ�Ĵ���Ҳ�����У�����Щ�Ƚ�
��ͬ����һ��С��ʦ����ţ����(beef noodle)Ҳ�ڹ�Ʒ֮�С�
DESK
,
    "noodle":"һ���������ţ���棬����ʳָ�󶯡�\n",
       ]));
set( "objects", ([
     "m_enforcer" : OMONSTER"m_enforcer",
     "wprayer#1" : OMONSTER"wprayer",
     "wprayer#2" : OMONSTER"wprayer",
     "corasho": OMONSTER"corasho",
     ]) );
set("light",1);
reset();
}

void init()
{
  add_action("do_eat","eat");
}

int do_eat(string arg)
{
  object ob1;

  if (!arg || (arg!="noodle" && arg!="ţ����"))
      return notify_fail("\n��Ҫ��������?\n");

  if (be_eated) {
    write( "\n��������һ�������ֺóԵ�ţ�����Ѿ����Ե��ˡ�\n");
    return 1;
  }

  write( "\n����������˲�ע���ʱ�ᣬ͵͵�İ����������������Ե���\n");
  write( "��!�����˼���ζ����������ͻȻ�㷢�ֺ���ҧ��ʲ�ᶫ������ \n");
  write( "���³������������� !  ��Ȼ��һ����ɫ�ɿ�����\n");
  be_eated=1;
  ob1=new(OOBJ"g_chocolate");
  ob1->move(this_object());
  return 1;
  
}

void reset()
{ 
  ::reset();
  be_eated=0;
}
