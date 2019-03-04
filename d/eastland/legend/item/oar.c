#include <mudlib.h>
#include "../legend.h"

inherit OBJECT;
int pl1,pl2;

void create()
{
        set( "extra_look", "$N������һ��С����");
        set_name("Oak oar", "��ľ��");
        add("id", ({ "oak oar","oar" }) );        
        set_short("��ľ��");
        set_long( @LONG
    һ֧��ľ���Ľ����������Ѿ��ܾ��ˣ����ǻ��Ǻܼ�ʵ���á�����Դ�
(help_me oak_oar)������㲻֪�����Ữ���Ļ���
LONG
        );
        pl2=random(5);
        set( "unit", "֧" );
        set( "weight", 10 );
        set( "prevent_drop",1);
        set( "prevent_insert",1);
}

void init()
{
  add_action("help_me", "help_me");
  add_action("do_oar", "oar");
}

int do_oar(string arg)
{
    string c_dir,dest;

    if( !arg )
      return notify_fail( "����Ҫ���ı߻��أ�\n");
    switch(arg) {
      case "east"  :
           pl1=pl1+3;
           pl2=pl2+3;
           c_dir="��";
           break;
      case "west"  :
           pl1=pl1+2;
           pl2=pl2+5;
           c_dir="��";
           break;
      case "south" :
           pl1=pl1+5;
           pl2=pl2-2;
           c_dir="��";
           break;
      case "north" :
           pl1=0;pl2=random(5);
           c_dir="��";
           break;
      default :
      return notify_fail( "����Ҫ���ı߻��أ�\n");
    };
    tell_object(this_player(),sprintf("��Ŭ������%s�߻�ȥ��\n",c_dir));
    tell_room(environment(this_player()),sprintf(
     "%sŬ������%s�߻��˹�ȥ��\n",this_player()->query("c_name"),c_dir),this_player());
    if ((pl2==13)||(pl2==19)||(pl2==31)||(pl2==37)) {
      pl2=pl1=0;
      this_player()->move_player(LAKE"lake05","SNEAK");
      tell_room(environment(this_player()),sprintf(
        "%sҡ�����������ػ��˹�����\n",this_player()->query("c_name")),this_player());
      return 1;
    }
    dest=LAKE"l_maze"+(string)((pl1 % 7));
    this_player()->move_player(dest,"SNEAK");
    tell_room(environment(this_player()),sprintf(
        "%sҡ�����������ػ��˹�����\n",this_player()->query("c_name")),this_player());
    pl1=(pl1>100)?0:pl1;
    if ((pl2<-1)||(pl2>40)) pl2=random(5);
    return 1;
}

int help_me(string arg)
{
  if( !arg || arg!="oak_oar" ) return 0;
  tell_object(this_player(),@LONG
   ��ͻȻ�����㲻�Ữ��������������ʹ������ֻ�ǲ�ͣ����ԭ�ش�ת��
   �޼ƿ�ʩ֮�£���ֻ�ô�����  
            ��......��        ��        ѽ������
   
   һֻС�����γ�ˮ�棬�������ĵ��۹⿴���㣬��˵��
   û���������ģ����Ữ��Ҳ���δ󺣡��Ҿͺ��Ľ���һ�°ɣ�ע������: 
   ����Ի���--ĳ������  (oar direction) ������< oar east >��������
   �󺣣�����㻮�κη���  (east south west north)������ײ������
   
   С����˵���һͷ���ˮ��ȥ�ˡ� 


LONG    
    );
      return 1; 
}       
