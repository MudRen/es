#include "../story.h"

inherit ROOM;
int on_war=0;
void create()
{
        ::create();
	set_short("Ѫ�ٲ�");
	set_long( @LONG
������Ǵ�˵�е�Ѫ�ٲ���������һ�ź�������ٲ�������������Ѫ����к
��������һĨ��ɫ��ƥ�����ڻ谵��������֮�£��淢�Եø��Ӻ��ˡ���˵�У�Ѫ
�ٲ�������������������ֻҪ�ѡ�����(bury)������ǡ���ͻ��л���õ��µ�
���������˲���˼�顣
LONG
	);
	set( "exits", ([ 
       	      "crack" : SAREA"vhole2" 
        ]) );
	reset();
}
void init()
{
   add_action("do_bury","bury");
}
void resetwar()
{
    on_war=0;
}
void trigger()
{
   find_object_or_load(WMOB"war")->start_war();
}
int do_bury(string arg)
{
   object player,corpse;
   string name,pname;
   if ( !arg ) return notify_fail("��Ҫ��ʲ�ᶫ����\n");
   player=this_player();
   corpse=present(arg,player);
   if ( !corpse ) return notify_fail("��û������������\n");
   name=corpse->query("c_name");
   pname=player->query("c_name");
   if ( ( !corpse->query("chicorpse") ) || on_war ) {
      tell_object(player,sprintf("���%s����Ѫ�ٲ���ȴû�����κ����顣\n",name));      
      tell_room(this_object(),sprintf("%s��%s����Ѫ�ٲ���ȴû�����κ����顣\n",pname,name),player);
      corpse->remove();
      return 1;           
   }
   corpse->remove();
   on_war=1;
   tell_object(player,sprintf("������Ѫ�ٲ����%sͻȻ�����˱仯��\n\n",name));     
   tell_room(player,sprintf("%s����Ѫ�ٲ����%sͻȻ�����˱仯��\n\n",pname,name),player);
   call_out("count1",5,name);
   return 1;
}
void count1(string name)
{
   tell_room(this_object(),set_color(sprintf(
     "��Ȼ�䣬Ѫ�ٲ����%s���˹���������������Ī���Ŀ־�...\n\n",name),"HIR"));
   call_out("count2",10);
}
void count2() 
{  
   trigger();
}
