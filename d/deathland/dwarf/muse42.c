
#include "../echobomber.h"

inherit Deathland+"/dwarf/daemon/muse";
inherit ROOM;

void create()
{
	::create();
    set("light",1);
    set_short("Muse Fountain","��˼Ȫ");
    set_long(@Long
Long
,@CLong
���ܹ�����ĸо���һ����ʥ������Χ���Ȫˮ������, �Ǿ��Ǵ�˵�е���˼Ȫ��.
�����˼Ȫ�Ĵ�˵ʵ��̫����, ����Ŀǰ���������ǰ. ����������ĵط��������ʱ��
�������ķ���, ��������������ط�����������ʵĸо�. 
CLong
    );
   set("muse_color",7);
   set("item_func",([
       "fountain":"look_fountain",
       "muse":"look_fountain",
       ]) );
   
   set("exits",([
       "southeast":Deathland"/dwarf/muse51",
       ]) );
   reset();
}

void init()
{
     add_action("to_drink","drink");
     add_action("to_fill","fill");
}

int to_fill(string str)
{
    if (!str || str=="") return 0;
    if ( str=="water" || str=="fountain")
    return fill_muse_water(this_player(),query("muse_color"));          

}

int to_drink(string str)
{
    if (!str || str=="") return 0;
    if ( str=="water" || str=="fountain")
      write(
      "��ȷ��Ҫ������Ȫˮ��??��Ȫˮ������ȫȫ��֪������������ɷ�....\n"
      "����������Ѿ��˽��������ԵĻ�, �ͺȰ�! ����û���˻ᱣ֤������\n"
      "����ᷢ��.\n"
      "�� < drink <color>_muse_water > ȥ������Ȫˮ��!!\n"
      );
    else if (str=="black_muse_water")  {
       drink_muse( query("muse_color") , this_player() );
       
       }
    else return 0;
    return 1;   
}

int look_fountain()
{ 
    write("һ����һ���Ȫˮû����������˼Ȫ, Ҳ\��\������ط�����ĸо�, Ҳ\��\��\n"
          "һ����ʥ��������Ȫˮ��ɢ������, ����ȷ������ط�������˼Ȫ. \n"
          "��Ȫˮ�����������ྻ, ֻ��������ɫ��һ�ֹ���ĺ�(black)ɫ.........\n"
          );
    
    return 1;
}

