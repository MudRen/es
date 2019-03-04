#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
    set_short("�����岿��");
	set_long( 
@LONG_DESCRIPTION
�����ǰ����岿��Ⱥ�����߿�ͨ���㳡������Ľ��������ʯ��ģ�������ס
��������úܶ�ʯ���̳ɵ�·�ᴩ�������䣬����������˵ĸо��Ƿǳ������Ұ�
��ģ���춻�ɽ�Ѿ��кܶ���û�б����ˣ������һ��������Ҳ�����ľ͵����˴���
���������·��һ����һ�ھ�(well)�������
LONG_DESCRIPTION
	);
set( "exits", ([ 
     "west" : OGROUP"warea9",
     "southeast" : OGROUP"warea11",
     "northeast" : OGROUP"warea13" ]) );
set("item_desc",([
    "well":@Well
һ���ǳ��峺��ˮ������������ף����ǰ������˵�ˮԴ�����Զ����Ǻ���Ҫ��
������һ���������￴������
Well
   ]) );
set("objects", ([
    "wellguard":OMONSTER"wellguard" ]) );
set_outside("eastland");
reset();
}

void init()
{
  add_action("do_toss","toss");
  add_action("do_jump","jump");
}

int do_toss(string arg)
{
  string str;
  object ob,player;

  player=this_player();

  if (!arg || arg=="")
    return notify_fail("The Syntax: toss <object> into well\n");

  if (sscanf( arg,"%s into well",str) == 1) {
    ob=present(str,player);
    if (!ob)
       return notify_fail(
              "��û������������\n");
    if (ob->query("prevent_drop")||ob->query("secure"))
      return notify_fail(
              "��û�а취����������\n");
    if (str!="bucket") {
      write("\n���"+ob->query("c_name")+"���뾮�У�ֻ������ͨһ����"+ob->query("c_name")+"�����ĳ��뾮�С�\n");
      ob->remove();
      return 1;
    }
    write("\n���"+ob->query("c_name")+"���뾮�У�ֻ���ðȡ�һ���������"+ob->query("c_name")+"����ˮ���ϡ�\n");
    this_player()->set_temp("well",1);
    ob->remove();
    return 1;
  }
  printf("The Syntax: toss <object> into well\n");
  return 1;
}


int do_jump(string arg)
{

  if (!arg) {
    write("������?\n");
    return 1;
  }

  if (arg=="well" || arg=="��")
  {
    if (this_player()->query_temp("mounting")) {
      write("���뾮��ǰ����������\n");
      return 1;
    }
    if (!this_player()->query_temp("well")) {
      if ((this_player()->query_skill("swimming"))<50) {
        write("ֻ������ͨһ���������ˮ����ò������Ӿ������һ��ˮ����...\n")
;
        write("����..����....����˺ü���ˮ���㲻����У�������!������!\n");
        if (present("well guard",this_object())) {
          write("���������ᣬ�Ӿ�����������'���㲻Ҫ��ɱ��ƫ����'�����ӽ�ס��\n");
          write("���������ס���ӣ����������İ�������ȥ��\n");
          return 1;
        }
        write("�����һ����ͷ�Ӿ�����������'���㲻Ҫ��ɱ��ƫ����'�����ӽ�ס��\n");
        write("���������ס���ӣ��Ǹ��������İ�������ȥ��\n");
        return 1;
      }
      write("ֻ������ͨһ���������ˮ�������һ��������ֻ���û��·���Գ�ȥ��\n");
      write("��ֻ���ſں��ȣ�������! ������!\n");
      if (present("well guard", this_object())) {
        write("���������ᣬ�Ӿ�����������'���㲻Ҫ��ɱ��ƫ����'�����ӽ�ס��\n");
        write("������Ӱ����Լ����ϣ����������İ�������ȥ��\n");
      return 1;
      }
      write("�����һ����ͷ�Ӿ�����������'���㲻Ҫ��ɱ��ƫ����'�����ӽ�ס��\n");
      write("���������ס���ӣ��Ǹ��������İ�������ȥ��\n");
      return 1;
    }
    write("��ܲ��������������ȥ����.....�飬ǡ�ɵ�����ոն���ȥ�Ĵ�Ͱ���\n");
    this_player()->move_player(OTEMP"well1");
    return 1;
  }

  write("��! ��! '��������' \n");
  return 1;
}
