#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
        set_short( "����");
	set_long( 
@LONG_DESCRIPTION
�������ڴ�Ͱ��������ϳ���һЩ��̦�����������Ͽ�ȥ�����ֻʣ��һ��㣬
�������ȥֻ�н��˰�æ�ˣ���ˮ�п�ȥ���ƺ��е�����������ˮ���£���֪���ɲ�
����Ǳ��ȥ���ơ�
LONG_DESCRIPTION
	);
set("search_desc", ([
    "here":"@@to_search_here" ]) );
reset();
}

string to_search_here()
{
  string str;

  str="\n���������ϸ��������һ�飬û�з����κ�ͨ·������֪����γ�ȥʱ��\n"
       +"ͻȻ�����˺ܾ���ǰ�Ͽ�ѧ����Ħ˹�������\n\n";
  return str;
}

void init()
{
  add_action("do_sos","sos");
  add_action("do_dive","dive");
}

int do_sos()
{
  object ob;

  ob=new(OOBJ"g_chocolate"); /* stupid method to init the room above well*/
  write("���ھ���������Ħ˹���룮����������������\n");
  ob->move(OGROUP"warea10");
  ob->remove();
  if(present("well guard",find_object(OGROUP"warea10"))) {
     write("����̽ͷ�����㣺���㲻Ҫ��ɱ���ƫ������\n");
     write("����˵����ס���ӣ�������������\n\n");
     tell_room(this_object(),"�����"+this_player()->query("c_name")+"��һ������������������ȥ��\n",this_player());
     this_player()->move_player(OGROUP"warea10","SNEAK");
     return 1;
  }

  write("\n��մ�����è���������Բ����ܰ���������Ѿ��������ˡ�\n");
  return 1;
}

int do_dive()
{
  if (this_player()->query_skill("swimming")<50) {
    write("���Ӿ���ƺ�������������Ǳ��ˮ�С�\n");
    return 1;
  }
  if (random ( (int)this_player()->query_skill("swimming")) < 50) {
    write("�������Լ���Ӿ����Ǳˮ�ǲ�����ɶ����ģ���Ǿ�������ȥ��\n");
    write("�����˼��£��ͷ��ֺ����������ˣ�ֻ���ֻص�ˮ�档\n\n");
    tell_room(this_object(),"�����"+this_player()->query("c_name")+ "����ˮȥ����һ�����������ţ����������ľͰ���\n",this_player());
    return 1;
  }
  write("���������Ӿ����տ������һ�����֮�ᣬ�Ͳ���һ�е�����ˮ�С�\n");
  tell_room(this_object(),this_player()->query("c_name")+"����ˮȥ������һ��Ƭˮ����������ϵ�������Сˮ�顣\n",this_player());
  this_player()->move_player(OTEMP"well2","SNEAK");
  return 1;
}
