#include "saulin_temple.h"

inherit ROOM;

int turn=0 ,push=0;

void create()
{
       ::create();
       set_short("�����´��۱���");
       set_long( @C_LONG_DESC
�����������˴��۱���Ĵ���������һ̤��������ͱ���ǰ�����ɫ�޴��
����Ĳ����(Statue of Buddha)������ס�ˡ��ڷ���������и������������\��
�ܶ���ʻ��ع������������߸���һյ�����ơ����������������ĸ�����(post)
���������д�֡������������и��㳡���ϱ�����ǰ����
C_LONG_DESC
               );
       set("light",1);
       set("exits",([
           "north" : SAULIN"hallway0",
           "south" : SAULIN"main_temple2"
       ]) );
       set("objects",(["leader" : SAULIN_MONSTER"leader_monk"]));
       set("item_desc",([ "statue": @C_LONG
����һ���ɴ�����죬ʮ�־޴�ķ��񣬾�˵���湩������Ĳ���������
(Relic)��ׯ�����µ�����ʹ���㲻������������Ĥ��(worship)����
�����ǰ���С��¯(censer)��������˵�ȼ��̴�㡣�ƺ��������㣬��
�ݵ��˿��治�١�
C_LONG
                           ,"censer": @C_LONG
���Ǹ�ͭ����С��¯����¯���ߵİ����ƺ�ĥ��ĺ����ء�
C_LONG
       ]));
	   reset();
}

void init()
{
     add_action("turn_censer", "turn");
     add_action("push_statue", "push");
     add_action("enter_hole", "enter");
     add_action("do_worship","worship");
}
int do_worship()
{
	tell_object(this_player(),
	"�����������������˼��ݣ�ͻȻ�о��������������ڶ�����Ц��\n");
	this_player()->save_me();
	"/adm/daemons/backup"->user_backup(this_player());
	return 1;
}
int turn_censer(string str)
{
    if( !str || str != "censer" )
      return notify_fail("��Ҫת��ʲ��?\n");
    tell_object( this_player(),@C_LONG
�㻺����ת����¯��ͻȻ��������ֵ������ӷ������洫���������Ǵ�����
ʲ����ء�����̧ͷһ�������ַ����ƺ������ƶ���
C_LONG
    );
    turn = 1;
    return 1;
}
                   
int push_statue(string str)
{   
    if( !str || str != "statue" || !turn )
      return notify_fail("��Ҫ�ƶ�ʲ��?\n");
    if( (int)this_player()->query_stat("str") < 15 )
      return notify_fail(@ALONG
���þ���ȫ���������������Ϊ����̫С���Ʋ�������
���Ѿ���֫�������ڵ��ϴ����� 
ALONG
      );
    tell_object( this_player(),@C_LONG
��Ѿ���ǧ�������춰ѷ������Ա��ƿ��ˡ��㿴���и�����(hole)��Ҳ��\
���Խ�ȥ������
C_LONG
     );
        this_player()->set_explore("eastland#30");
     push = 1;
     return 1;
}

int enter_hole(string str)
{
      if( !str || str != "hole" || !push )
        return notify_fail( "��Ҫ��ȥ����?\n4");
      this_player()->move_player(SAULIN"road1","SNEAK");
      return 1;
}

void reset()
{
	::reset();
	turn = 0;
	push = 0;
}
