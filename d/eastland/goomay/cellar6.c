#include "goomay.h"

inherit ROOM;

int mark;
void create()
{
        ::create();
        set_short("����ķ���");
        set_long( @LONG_DESCRIPTION
��������λ�һ������ķ����У�����������ط��������Ĳ�ͬ��
һ��Ҳ���Ե����Һ����ȣ��ҾߺͰ�\�趼ʮ��ǡ������ǽ�ĵط�����
һ��СС�ĳ���(closet)�;�̨��һ�ɹɵ����粻֪�������ﴵ����
����ʮ���泩��
LONG_DESCRIPTION
        );

set("item_desc",([
    "closet":  "����һ�������ĵ񻨳��񣬿�����ֻ�Ǹ��¹�\n" 
           ]) );
set("search_desc",([
     "closet":"@@to_search_closet",     
          ]) );

set("exits",([
     "east"	:  Goomay"cellar5",
     ]) );

 reset();
}

void init()
{
        if (this_player()) this_player()->set_explore("eastland#11");
}
void reset()
{
   ::reset();
   mark=0;
}

string to_search_closet()
{
   object ob1;
   switch(mark) {
   case 0:  
     mark=1;
     ob1=new(Obj"ingot");
     ob1->move(this_player());
     return "����ϸ�ķ��䵹������ֻ������һ����ֵ��ƽ��ơ�\n";
   case 1:
     return "��һ����ϸ�������£���Ҳ�Ҳ�����Ȥ�Ķ����ˡ�\n"; 
   }  
}
