#include <mumar.h>
inherit ROOM;
 
void create()
{
        ::create();
  set_short("��");
  set_long( @CLong
���������ص�����������Զ�������������ս���������ص������ս����
�ͣ�����������Ҳʮ���ܵ������������ɨ��Ǭ�����ʣ����ܱ�ʿ��ס�û�����Щ��
����������С·ͨ���̳���
CLong
);
set_outside("eastland");
set("exits",([
               "northwest":MUMAR"square03",
             ]));
 
set( "pre_exit_func", ([ "northwest" : "can_pass" ]) );
set("objects",([
               "groom":MOB"groom",
               "horse#1":MOB"horse",
               "horse#2":MOB"horse"]));
reset();
}
 
int can_pass()
{ if(this_player()->query_temp("mounting") && !wizardp(this_player()) &&
       present("groom") )
   {  if(this_player()->query_temp("cavalry_mark") )  {
           tell_object(this_player(),
                       "��������ض���˵�������٣���������!\n" );
           this_player()->set_temp("cavalry_mark",0) ;
           return 0;
             }
      else   {
      tell_object(this_player(),
"���ݺݵص�����˵��������������Ϊ�����ܺõ���ȴ���˽�����˵���������\n"
"���˵����ͬʱ������������������һ����͵��������˵����\n"
"��������Ȼ���е㲻��ʹ����һ��Ҳ���϶�...\n" );
      return 1;
             }
   }
else
    return 0;
}
