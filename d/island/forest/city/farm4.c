#include "../tsunami.h"
#include "/include/move.h"

inherit ROOM;

int radish;

void create()
{
    ::create();
    set_short("����������ũ�����Ĳֿ�");
    set_long(@LONG
�����ǡ���������ũ�����Ĳֿ⣬��ͷ�ѷ��˰��������������ճɣ���Ȼ��
�����в�����׼��Ҫ����ħ�嵱˰��ġ���Щ����ħ��ս�����࣬��Ҫ������ս��
��ʳ����˴����߰���������ʳ�裻�������������䲻����������춺���ս����
����ֻ��ĬĬ������
LONG
            );
    set("light",1);
    set("exits",([
        "east":CITY"farm5"]) );
    set("objects",([
        "wife":TMOB"wife"]) );
    reset();
}

void init()
{
    add_action("do_search","search");
}
    
void reset()
{
    ::reset();
    radish = 3;
}

int do_search(string str)
{
    if( !str || str !="there"){
        if(present("farmer's wife")){
        write("��Ҫ����������˵�Ǳ��˰��㻹�����ҷ�.....�Ǳ�������\n");
        return 1;
        }
        write("һֻС�������Ǳ�ҧ�����Ķ��������������Ҫ�ҵ�Ү��\n");
        return 1;
    }
    if( radish == 0){
    write("��������ȥ�������Ҳ����Ǹ������ܲ���һ���Ǳ����ù��ˣ�\n");
    return 1;
    }
    else{
    write("\nΪ���Ǹ������ܲ�����һ������һ�����ӵļ�飬��� ....\n.\n.\n��\n��\n��...\n\n");
    tell_room( environment(this_player()),
       this_player()->query("c_name")+"Ϊ����һ���ܲ�����Ȼ�۵�˯���ˣ�\n",
       this_player() );
    this_player()->set_temp("block_command",1);
    call_out("get_radish",5,this_player());
    return 1;
    }
}

int get_radish(object me)
{    
    tell_object(me,@BLONG
����ԼԼ�����������ڳ��裺........................
          ���Ϻ��ϰ��ܲ������Ϻ��ϰ��ܲ�
��ϸһ����ԭ�������ڰ��ܲ������������ʤ���У��������ӣ���춰����������ˣ�
�㱧����ֻ���ܲ������о��ú�����ร���
һʱ���ܺ�Ȼ�䣬�ܲ�Խ��Խ�󣬴�ÿ�Ҫ����ѹ���ˣ�
��ƴ��������Ŭ������������û�ã����룺���ˣ�ҪȥԶ������...........
BLONG
         );
    call_out("wake",7,me);
    return 1;
}

int wake(object me)
{
	object ob;
   ob=new(TOBJ"radish");
   
   tell_object(me,"\n\n�㱻������ŵþ����ˣ������һ���ֻ������ʱ����Ȼ������������һֻ�ܲ�......\n\n\n");
   me->set_temp("block_command",0);
   ob->set("owner",(string)me->query("name"));
   ob->move(me);
   tell_room( environment(me),
     "�㿴��"+me->query("c_name")+"ͻȻ���ѣ����������е��ܲ�������\n"
     , me );
   radish = radish - 1;
   return 1;
}                  
