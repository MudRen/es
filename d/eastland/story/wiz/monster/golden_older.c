#include "../../story.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "golden older", "��ʯ����" );
	set("id",({"older"}));
	set_short( "��ʯ����" );
	set_long(@C_LONG
����ǰ��������һλ��ò���ǡ���ļ�Ϊ��С�����ˡ��������������ǿ����죬��
�����ݣ�üë����ϡ�裬ȫ��Ƥ�����ֽ��ɫ��һ����̫�����˵����ӣ��Ź��Ѽ�
����ʯ������ƽ��ϲ���ռ������˽���(exchange)�����챦������֮�⣬û��ʲ��
�Ⱥá�
C_LONG
        );
	set( "gender", "male" );
        set_natural_armor(30,0); 
        set("no_attack",1);
        set("inquiry",([
          "exchange":"@@ask_exchange",
          "fly_building":"@@ask_building"
        ]) );
}
void init()
{
   ::init();
   add_action("do_help","help_me");
   add_action("do_select","select_me");
}
int do_help(string arg)
{
    object player;
    player=this_player();
    if (!player->query_temp("golden_older_asked")) return 0;
    switch ( arg){
    case "1":
        write(@LONG
��ʯ���˵���
����׮�Ƕݷ���һ�֣����������÷������ģ�������������ʲ������Σ�ջ���
����ǧ��֮�⣬��ֻҪ(use_dragon_wood)���������������ҵ�ס��������
LONG
    );
       return 1;
    case "2":
        write(@LONG  
��ʯ���˵���
������������Ҷ����о��������ε����ʵ��ĵö����ġ�����������������
���ѵ����ٱ�ɿ����еĳ��������ڿռ����һ���Լ��ķ���������ƭ���ˣ�
�Դﵽ�������ѵĹ��á�����������о��Ĳ���ȫ������ֻ�ܶ�ĳЩ�ض��Ĺ�
���ʹ�á�ʹ��ʱ����ֻҪ��(��cast-me wonderful��)���Ϳ����ˣ�������
�мǣ�������ʹ�õ�ʱЧ���������ֻ�衡( uncast-me wonderful )����
�����ˣ����ҵĹ��ƣ�ȫ���а��ʱ����ʱЧ��
LONG   
    );
        return 1; 
    case "3":
        write(@LONG
��ʯ���˵���
�����������ӣ��е�����֮��ģ���������װ(package)���
LONG
    );        
        return 1;
    default:
        write("��ʯ���˵����Ⲣ�����Ҹ��㽻���Ķ���֮�ڡ�\n"); 
        return 1;
    }
}
int do_select(string arg)
{
    object player,item;
    player=this_player();
    if (!player->query_temp("golden_older_asked")) return 0;
    player->delete_temp("golden_older_asked");
    switch(arg) {
    case "1":
         write("�������룬����Ҫ����׮������������ǽ�ʯ�����ó��˶���׮���ڵ��ϡ�\n");         
         item=new(SWITEM"flee1");
         item->move(environment());
         return 1;
    case "2":
         write("�������룬����Ҫ���������������������ǽ�ʯ�����ó���������������ڵ��ϡ�\n");
         item=new(SWITEM"spell2");
         item->move(environment());
         return 1;   
    case "3":
         write("�������룬����Ҫ��ɫ����������������ǽ�ʯ�����ó��˽�ɫ���ӷ��ڵ��ϡ�\n");
         item=new(SWITEM"basket1");
         item->move(environment());
         return 1;
    default:
         write("��ʯ���˵����Ⲣ�����Ҹ��㽻���Ķ���֮�ڡ�\n");                       
         player->set_temp("golden_older_asked",1);
         return 1;
    }
}
void ask_exchange(object asker)
{
   
   if ( asker->query_temp("golden_older_asked") ) {   
       write(@LONG
��ʯ���˵���������Ҫ��������ʲ�����Ķ����أ�

     **********************************
       1.����׮(dragon wood)��
       2.���������(wonderful-spell)��
       3.��ɫ����(golden basket)��

       
����������(help_me number)��������������ѡһ��(select_me number)��
LONG
   );
   return;
   }

   if ( asker->query_temp("exchange_things_with_older") ) {
       write("��ʯ���˵������ᣬ�����д�ʲ�ᶫ�������ҽ�����\n");   
       return ;
   }
   if ( !asker->query_temp("golden_older_asked") ) {
      write("��ʯ���˰�����һ�۵���С����û�²�Ҫ�������ң��ʶ������ģ��������ˡ�\n");
   return ;
   }
}
void ask_building(object asker)
{   
   if ( asker->query_temp("exchange_things_with_older") ) {
   write(@LONG
��ʯ���˵����춼����������ҽ��������ķ��ϣ��Ҿ�ָ����һ�Խ��춼������
��������������ס�ĵط�����ȥ�춼�ý衸����֮�ѡ�(fly_flute)���ܵ��
LONG
   );
   return ;   
   }
  write("��ʯ���˰�����һ�۵���С����û�²�Ҫ�������ң��ʶ������ģ��������ˡ�\n");
  return ;
}
int accept_item(object player, object item)
{
    if ( !item->query("special_things") ) {
       item->remove();
       tell_object(player,@LONG

��ʯ���˽ӹ�������Ķ������Ҵ���һ��...
��ʯ���˿��ڵ������������������������������Ȼ������Ķ���������Ҳ����ʧ��
������ʯ���˴ӿڴ����ͳ�һ�����Ҹ��㣬�����Ͳ������ˡ�

LONG        
    ); 
       player->add("wealth/silver",1);
       return 1;
    }
    item->remove();
    player->set_temp("golden_older_asked",1);
    tell_object(player,@LONG
��ʯ���˽ӹ�������Ķ�������һ����ɴ����ۣ�
��ʯ����ϲ�����ؿ��ڵ����ţ���ȷ�Ǹ��Ƿ��Ķ����������ɣ���Ҳ����һ��
                       ������Ϊ�������ˡ�
��ʯ���������ܷ��������˼���������
��ʯ����˵�����ţ������м�����������һ���ɣ������֪����һ���ã����
              ( help_me number )���ˣ��һ����˵���������������ᣬѡ
              ��( select_me number )һ����ϲ���ģ�����ѡ�������Ͳ�
              ׼����ˡ�����

     **********************************
       1.����׮(dragon wood)��
       2.���������(wonderful-spell)��
       3.��ɫ����(golden basket)��       


LONG
    );
    player->set_temp("exchange_things_with_older",1);
    return 1;
}
