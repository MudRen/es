#include <mudlib.h>

inherit ROOM;
void create()
{
     ::create();
}
void init()
{
    add_action("do_stun","stun");
}
int do_stun(string arg)
{
   if (this_player()->query("class")!="monk"){
       tell_object(this_player(),"��Ҫ��ʲ��?\n");
       return 1;
   }
   if (!this_player()->query_attackers()){
       tell_object(this_player(),"��û��ս���У��Ҳ�������������!\n");
       return 1;
   }
   tell_object(this_player(),set_color(
        " *** ��ȫ���ע����ʼҪ�һ���ʩչ���Ѩ���� ! *** \n","HIC"));
   call_out("recover",6,this_player());
   return 1;
}
void recover(object obj)
{
   if (environment(obj)==this_object()) {
      tell_object(obj,"����,��������Լ���Ѩ��!!!\n");
      obj->block_attack(10);
      obj->set_temp("msg_stop_attack","(  �㱻��ס��Ѩ���������� !!  )\n");
   } else tell_object(obj,"���ս�������ˣ�����Ҫ��Ѩ��!\n");
}
