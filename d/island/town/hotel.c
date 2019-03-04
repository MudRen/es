//#pragma save_binary

#include "../island.h"
#include <money.h>

inherit ROOM;
inherit SELLER;

void create()
{
    ::create();
    set_short("���ſ�ջ");
    set_long(@C_LONG
���Ǽ��½������Ŀ�ջ������ϰ���׼��������п�Ϊ�����ڴ˿���
�ҵꡣ��춴˴����������������ر�࣬�˴�����������Ӵ�֮�ء���ջ
�ڳ�����ƹ��ߺ���������˵�����������Ҳ��Щ����ȫ����������ֻ��
���������ڽ������λ�϶��ã������˴�ȷʵ�Ǹ��Ƿ�֮�ء�
C_LONG
             );
      set("exits",([
            "north" : ITOWN"town04"]) );
      set("light",1);
      set("no_monster",1);
      set_inventory( ({
                       ({ IOBJ"wheet", 20 , 20}),
                       ({ IOBJ"lu-wei", 15 , 15}),
                       
        }) );
        set( "objects",([ "lizardman" : "/d/island/hole/monster/valor",
                          "boss" : IMON"boss" ]) );
        reset();

}      
void init()
{
  ::init();
  add_action("do_search","search");
  add_action("do_look","look");
  return;
} 
int do_search()
{
 tell_object(this_player(),"��������̽ͷ̽�Ե�ʱ�򣬹�̨���ⷼƸ���˵�������������Ļ�\n��������Ŀ��(list)�ͺ��ˣ���\n");
 return 1;  
}
int do_look(string arg)
{
  if (!arg || arg != "list") return 0; 
  show_menu();
  return 1;
}                     
 
void reset()
{
    room::reset();
    seller::reset();
}
              