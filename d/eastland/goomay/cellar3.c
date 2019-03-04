#include "goomay.h"

inherit ROOM;

int letter;
void create()
{
	::create();
  set_short("�����ĵص�");
  set_long(@Long
����һ���ǳ��ƾɵĵط���������֩�����ͻҳ����ص������\��һ��
�����ͼ������Σ�Ҳ��\����ԭ���Ǽ���Ϣ�ң���������һ����������һ��
�Ǻ�(skeleton)�������
Long
);

set("item_desc",([
    "skeleton":"@@to_look_skeleton",
           ]) );
set("search_desc",([
     "skeleton":"@@to_search_skeleton",     
          ]) );
set( "objects", ([
	"rat1" : Mob"salamander",
	"rat2" : Mob"salamander", ]) );

set("exits",([
     "north"	:  Goomay"cellar2",
     ]) );

 reset();
}

void reset()
{
   ::reset();
   letter=0;
}

string to_look_skeleton()
{
   switch(letter) {
   case 0:
   return "����һ���ߴ��޳��ĹǺ����ɴ�С���ж�Ӧ���Ǿ����뾫��ĹǺ���\n"+
		"�����������ƺ�����һ��������\n";
   case 1:
   return "һ���ߴ��޳��ĹǺ����ɴ�С���ж�Ӧ���Ǿ����뾫��ĹǺ���\n";
   }
}

string to_search_skeleton()
{
   object ob1;
   switch(letter) {
   case 0:  
     letter=1;
     ob1=new(Obj"letter01");
     ob1->move(this_player());
     return "��ӹǺ������з�����һ�ŷ��Ƶ���Ƥֽ��\n";
   case 1:
     return "��һ����ϸ��������,��ֻ���ж����Ǹ�����ĹǺ���\n"; 
   }  
}
