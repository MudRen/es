#include "../tsunami.h"
#include "move.h"



inherit ROOM;

int seed;

void create()
{
    ::create();
    set_short("��\ľ");
    set_long(@LONG
������ܳ��������ι�״��ֲ������Ŀǰ�в�Ϊ��֪�ġ���Ҳ�Ѿ�
�ͻ����ˣ������������ǰ�ǿ�����£����˲�����ǣ�Ϊ�������ֲ�ﶼ��
�����٣�Ψ�����ʮ�־޴����(tree)���ή�����أ�
LONG
             );
    set("exits",([
            "south":AREA"way4"]) );
    set_outside("island");
    set("item_desc",(["tree":@ALONG
��ϸ����һ����޴�Ŀ�ľ���ƺ��ͺӱߵ��ǿ�����ͬƷ�ֵ�ֲ�ֻ
�ǣ�Ϊ�κӱ��ǿû᳤������ïʢ�������ȴ�Ѿ���ή���أ���......
�ѵ���˵�е��ػ��飭���ʡ��������ģ����
ALONG
              ]) );          
    reset();
}

void init()
{
    add_action("do_pray","pray");
}

void reset()
{
    ::reset();
    seed = 1;
}
int do_pray(string str,object obj)
{
     
     obj=new(TOBJ"seed");
    
     if( !str || str != "seed")
        return notify_fail("��Ŭ������������ϣ����ľ��ð��һ�����Ӹ���..\n"); 
     if( !this_player()->query_temp("luoko_quest")) {
   write("���ϵ����˰��죬���ֻ��һֻ��ѻ����ͷ�����ɽ����ɹ�....:P\n");
       return 1;
       }      
     
     if( seed == 0){
     write(@ALONG
ͻȻһ���âΧ�����㣬һλ��̬��������˳����������ǰ��
    ���ӣ����ǲ��ɣ��Ѿ������ڰ����ˣ���������лл�㣡
ALONG
       );
       return 1;
     }
       else{         
     write(@BLONG
ͻȻһ���âΧ�����㣬һλ��̬��������˳����������ǰ��
�������ӣ���Ը�����æ�ǰɣ������ҵ����ӣ�Ҳ������������Դ�����㽫������
����԰�У��������������������㹻������������������壻���ӣ�һ�оͶ�����
���ˣ�
����ֻ����һ�����ӻ�����Ʈ�������У�������â����ʧ��.........
BLONG
          );
     obj->set("getter",(string)this_player()->query("name") );
     obj->move(this_player());
     tell_room(environment(),
     "ͻȻһ���â£����"+this_player()->query("c_name")+"�������þ���ʧ�ˣ�\n");
     this_player()->delete_temp("luoko_quest");
     seed = 0;
     this_player()->set_explore("island#4");
     return 1;
     }
}
