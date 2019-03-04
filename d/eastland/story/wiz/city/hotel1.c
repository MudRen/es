#include "../../story.h"

inherit ROOM;
int number=0;
void create()
{
	::create();
        set_short("�ù�");
	set("long",@LONG
�˴��ǡ����̳ǡ���Ψһ��һ���ùݣ��������������Ϣ��ҹ��������ÿ�����˷�
����������Ҫ���ư������⣬˯��һ�������˿����Ȭ����һ���������Ǿ���������
��ļ�Ǯ�൱�����������ۣ�ȫд��ǽ����һ�Ż�ɫֽ(paper)�ϡ�	
LONG
	);
	set("light", 1);
	set("exits", ([ 
            "west" : SCITY"ww"
        ]) );
        set("c_item_desc", ([
           "paper" :" �����������д������ҹ(sleep)һ�� 500 ��ҡ�\n"
        ]) );
        set("objects", ([
           "boss" : SWMOB"boss1"
        ]) );
	reset();
}

void init()
{
     add_action("do_sleep", "sleep");
}

int do_sleep(string arg)
{
     object player;
     string name;
     if ( number > 5 ) {
        write("��λ������Բ��𣬱����Ѿ������ˣ��´����硣лл��\n"); 
        return 1;
     }
     player = this_player();
     name=player->query("c_name");
     if ( !player->debit("gold", 500) ) {
         write("��λ������Բ���������������Ǯ������\n");
         return 1;
     }
     number++;
     write(@LONG

�ù��ϰ�󺰵���С���������λ������Ϣȥ��


��ǣ���С������ææ�����㵽��¥��׼����Ϣȥ...

LONG 
     );
     tell_room(this_object(),sprintf(
         "%s��������ƣ���������С���϶�¥��Ϣȥ��\n",player->query("c_name")),player);
     player->move_player(SCITY"hotel2","SNEAK");
     player->set_temp("block_command", 1);
     call_out("result", 6,player, 0 ,this_object());
     return 1;
}

void result(object me, int count, object place)
{
     int sp,fp,med,max_fp,max_sp;
     if( !me ) return 0;
     if( count < 10 ) {
     tell_object(me, "Z z �� �� Z z\n");
         if ( me->query("max_fp") ) me->add("force_points",5);
         if ( me->query("max_sp") ) me->add("spell_points",7);
         me->set_temp("block_command",1);
         me->add("medication_resistance",-15);
         me->receive_healing(25);
         call_out( "result",6,me,count+1,place);
         return ;
     }
     med=me->query("medication_resistance");
     fp=me->query("force_points");
     sp=me->query("spell_points");
     max_fp=me->query("max_fp");
     max_sp=me->query("max_sp");
     if ( med<0 ) me->set("medication_resistance",0);
     if ( fp>max_fp ) me->set("force_points",max_fp);
     if ( sp>max_sp ) me->set("spell_points",max_sp);
     me->move_player(SCITY"hotel1","SNEAK");
     me->delete_temp("block_command");
     tell_object(me,
	"���������,����ʱ��,��,��Ϣ����Ҳ����·�ˡ�\n");
     tell_room(place,sprintf(
	"%s��¥����������,����ü��ˡ�\n",me->query("c_name")),me);
     return ;
}
void reset()
{
   number=0;   
   ::reset();
}