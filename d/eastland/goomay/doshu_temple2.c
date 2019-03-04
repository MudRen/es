#include "goomay.h"

inherit ROOM;

int ice;

void create()
{
        ::create() ;
        set("light", 1) ;
        set_short( "�ڵ�" );
        set_long(
@LONG
���߽������۵��ڵ�����������������޵ĵط���һ��\��\������
��������¯��������Ե�ʮ�������������Ϲ�����������ʦ�Ļ���ǽ
�Ϲ���һ�����Ǳ������˿̵�������һ�ˣ�û����øϿ��뿪����ñ�
������Ϊ���Ͼ��ӡ�
LONG
        );
        
        set( "exits", ([ 
		"south" : Goomay"doshu_temple",
        ]) );
	set("search_desc",([
	"here":"@@to_search_here",]) );
        ice=0;
        reset();
}
void reset()
{
   ::reset();
   ice=0;
}

string to_search_here()
{
   object ob1;
   this_player()->set_explore("eastland#9");
   switch(ice) {
   case 0 :
	ice=1;
        new(Mob"doshu" )->move(this_object() );
	return "";
   case 1:
	if (present("master daoist",this_object() ) || present("daoist",this_object() ))
	return "�ǵ��˴�ȵ����������޷������С͵�����ڻ���͵�����𣿡�\n";
	ice=2;
	ob1=new(Obj"crystal_ice");
	ob1->move(this_player());
	return "����ϸ�ķ��䵹�����ᷢ����һ�����������\n";
   case 2:
	return "��һ����ϸ�������£���Ҳ�Ҳ�����Ȥ�Ķ����ˡ�\n";
     }
}
