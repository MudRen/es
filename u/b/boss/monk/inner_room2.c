
#include "saulin_temple.h" 

inherit ROOM;

void create()
{
        ::create();
    set_short("���ֳ����ķ���");
        set_long( @LONG_DESCRIPTION
�ⷿ��������Ϲ���һ��ز�����������������������һ�ɺ���ׯ�ϵ����ա�
�����ѧ�����޺��ķ��������ʴ������������¶���Ϊһ�������Ļ���������ڴ˵�
ѧ�����ֵ�����һ���ķ������ֳ����ķ��������������ǿ���ķ���Ϳ���ĸ��� 
�ͻ����ˡ�ǽ�ϻ���һ�����ľ�������(shape)���㲻��ȥ������
����ͨ�������ڹ�\�ķ�����
LONG_DESCRIPTION
        );
    set("c_item_desc",([
         "shape":@BOOK
ǽ��д�������ֳ����ķ��������������ζ��Ѱ��䲻���ˣ���Ҳ���������ϵ�����  
�������? �ĳ����飬Ҳ��\��������ز�����(pray god) �������᲻�������顣


ע�������ֵ��С�� [��ϰ�ķ�] �� [�����ڹ�\] �й� 
BOOK
]));         
        set( "light", 1 );
        set( "exits", ([ 
                "south" : "/u/b/boss/workroom.c" ]) );
        reset();
}

void init()
{
 add_action("to_study","pray");
}

int to_study(string arg)
{
  string class;
  int alignment,effect,inte;

  inte=(int)this_player()->query_stat("int"); 
  effect=(int)this_player()->query("force_effect"); 
  alignment=(int)this_player()->query("alignment"); 
  class=(string)this_player()->query("class");

  if ( !arg || arg!="god") return 0;

  else if ( class !="monk") {
     tell_object(this_player(),"��Ǹ�㲻�Ǳ�������������㲻��ѧ���ķ�\n");
     return 1;
                            }
  else if (effect>=5) {
tell_object(this_player(),
" �㿴���ز����ڵ��㣬�ƺ�Ҫ����̰�ģ������ϸĿ�˵\n 
������������������л���̵��ҡ������ķ����ģ��������ٶ�ѧЩʲ�����!!!��
  �����ĵ�����һЦ���ز���������ӹ�����ˤ����...\n\n " );
          return 1;
                    }       
  else if (effect<2) {
tell_object(this_player(),
" һ���Ϻ��о�������ߣ�ҡ��ҡͷ˵\n 
�����޺��ķ���������˻���ѧ�����ķ�����... ���Ĳ���������!��\n\n " );
          return 1;
                    }       
else if (inte<=8) {
tell_object(this_player(),
"\nһ��Сɳ���ܳ�������: 
��һ��һ��춼�? ��!!! ���������֪��! �����ڻ���̫���ˣ�����ѧ��!��\n\n");
         return 1;
                  } 
else if (alignment<5000) {
tell_object(this_player(),
" һ��������ǽ�����˳�������Ž����߳�����ȥ  
��������\ֻ����һ����������ƾ��Ҳ��ѧ!!!�� \n\n" );
this_player()->move_player( SAULIN"inner_room","SNEAK");
          return 1;
                                 }       
   else      {

        this_player()->set_temp("chutan", 1 );
    if( !wizardp( this_player() ) ) {
          this_player()->set_temp("block_command", 1 );
        }
          this_player()->set_temp("chutaning", 1 );

 tell_object(this_player(),"��ͻȻ���ú��ۣ������������˯����......
 
�ڣڣڣ���������.... \n\n\n\n\n\n" ); 
 call_out("appear_old",5,this_player());
        return 1;  
             } 
}


void appear_old(object player)
 {
tell_object(player,@APPEAR
ͻȻ�㿴��һ���׷��Ϲ������˹��������������ĳ���Ц������˵ :
���ţ������ִ�������һ�ź��ĳ����Ҿʹ��㳯���ķ���! �����������!
 �츣����! �м� �м�!!!��


��������һƬ�������Ϲ���ȫ������������... һƪƪ�ķ���Ҫ��ͻȻ
����������Ժ�... �㲻����ϲ���񣬹���лл�Ϲ���������Ѹ�ٴ�������
��ϰ�������ֳ����ķ���
APPEAR
        );
player->set("force_effect",5);
call_out("wake_up",25,player);
 }
void wake_up(object player)
 {
 tell_object(player,"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n����...��.��..��!!! ��.��...��..��.!!! ż..ż.Ҫ..ɨ.��..��....����
  һ���ڳԵ�ɨ��ɮ��ɨ�ѱ��������ͷ�� 

  �㷢����ȫ���ǿ�ˮ����ȴ����������������ڹ�\��Ϊ�ƺ���������...
  ̧ͷһ�����㷢�ֵز��������Ӻ��Ϲ������񰡣����ƺ�Ҳ�ڶ���΢Ц��...
  �����������վ������ \n\n");
        player->set_temp("chutan", 0 );
    if( !wizardp( player ) ) {
          player->set_temp("block_command", 0 );
        }
          player->set_temp("chutaning", 0 );
}


