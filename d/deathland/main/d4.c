
#include "../echobomber.h"
inherit "/std/room/waterroom";

int can_enter;
void create()
{
   ::create(); 
   set("light",1);
   set("short","��ͷ��ˮ��");

   set("long","@@c_long");
   set("item_desc",([
    "stones":"ʯͷ�ϵ���̦��ĥ��ĺۼ�,����������ƶ���\n",
    "fish":"һȺ����ֵֹ���,�ƺ�ֻ������ط��Ż����.\n"
     ]) );
   set("exits",([
              "up":Deathland"/main/d1",
              "down":Deathland"/main/d5"
             ]));

reset();
}
void init()
{
  add_action("to_move_stone","move");
  add_action("to_enter_hole","enter");
}

int to_move_stone(string str)
{
   if (!str||str=="")
     return 0;
   if (str=="stones"|| str=="stone") {
       write("�����˺ܴ������ȥ�ƶ�ʯͷ,������һ���������������ǰ\n");

     can_enter=1;
     add( "item_desc",([
          "hole":"һ����ֵĶ�,����ȷ����ͨ���δ�.\n"
              ]) );
    this_player()->set_explore( "deathland#1" );
    return 1;
    }
}

int to_enter_hole(string str)
{
    if ( can_enter==0 ) return 0;
    if (!str||str!="hole") {
      write("��������ط� ?\n"); 
      return 1;
      }
    write("��С���������ν���Ѩ\n");
    say("���㿴��"+this_player()->query("c_name")+
         "�ν�����,ʯͷ�ٶȵذѶ��ڸ�\ס\n");
    this_player()->move_player(Deathland"/main/d6",
    ({"%s swim to hole,then the stone close the hole\n","���㿴��%s�ν�������,ʯͷ�ٶȵذѶ��ڸ�\ס\n" ,
      "%s swim from outside.\n","%s���������˽���.\n"}),"");
    can_enter=0;
    return 1;
}

void reset()
{
   ::reset();
   can_enter=0;
   
}

string c_long()
{
    string longlook;

    longlook="΢���Ĺ��ߴӺ�����������,���ܿ���һЩ��(fish)������������ȥ.\n";
    switch( can_enter ) {         
         case 0:
           longlook+="��ϸһ����������ʯ(stones)�ƺ��������˰ᶯ������.\n";
           break;
         case 1:
           longlook+="��ϸһ����������ʯ(stones)�ƺ��ѱ��˰Ὺ��,��һ����Ѩ\n"
                     "�����������ǰ.\n";
           break; 
          }
    return longlook;       
}
